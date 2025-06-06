/*
Copyright 2018 Massdrop Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "arm_atsam_protocol.h"
#include "tmk_core/common/led.h"
#include <string.h>
#include <print.h>
#include <math.h>
#include <inttypes.h>

void SERCOM1_0_Handler( void )
{
    if (SERCOM1->I2CM.INTFLAG.bit.ERROR)
    {
        SERCOM1->I2CM.INTFLAG.reg = SERCOM_I2CM_INTENCLR_ERROR;
    }
}

void DMAC_0_Handler( void )
{
    if (DMAC->Channel[0].CHINTFLAG.bit.TCMPL)
    {
        DMAC->Channel[0].CHINTFLAG.reg = DMAC_CHINTENCLR_TCMPL;

        i2c1_stop();

        i2c_led_q_running = 0;

        i2c_led_q_run();

        return;
    }

    if (DMAC->Channel[0].CHINTFLAG.bit.TERR)
    {
        DMAC->Channel[0].CHINTFLAG.reg = DMAC_CHINTENCLR_TERR;
    }
}

issi3733_driver_t issidrv[ISSI3733_DRIVER_COUNT];

issi3733_led_t led_map[ISSI3733_LED_COUNT+1] = ISSI3733_LED_MAP;
issi3733_led_t *lede = led_map + ISSI3733_LED_COUNT; //End pointer of mapping

uint8_t gcr_desired;
uint8_t gcr_breathe;
uint8_t gcr_use;
uint8_t gcr_actual;
uint8_t gcr_actual_last;

#define ACT_GCR_NONE    0
#define ACT_GCR_INC     1
#define ACT_GCR_DEC     2

#define LED_GCR_STEP_AUTO 2

static uint8_t gcr_min_counter;
static uint8_t v_5v_cat_hit;

//WARNING: Automatic GCR is in place to prevent USB shutdown and LED driver overloading
void gcr_compute(void)
{
    uint8_t action = ACT_GCR_NONE;

    if (led_animation_breathing)
        gcr_use = gcr_breathe;
    else
        gcr_use = gcr_desired;

    //If the 5v takes a catastrophic hit, disable the LED drivers briefly, assert auto gcr mode, min gcr and let the auto take over
    if (v_5v < V5_CAT)
    {
        I2C3733_Control_Set(0);
        //CDC_print("USB: WARNING: 5V catastrophic level reached! Disabling LED drivers!\r\n"); //Blocking print is bad here!
        v_5v_cat_hit = 20; //~100ms recover
        gcr_actual = 0; //Minimize GCR
        usb_gcr_auto = 1; //Force auto mode enabled
        return;
    }
    else if (v_5v_cat_hit > 1)
    {
        v_5v_cat_hit--;
        return;
    }
    else if (v_5v_cat_hit == 1)
    {
        I2C3733_Control_Set(1);
        CDC_print("USB: WARNING: Re-enabling LED drivers\r\n");
        v_5v_cat_hit = 0;
        return;
    }

    if (usb_gcr_auto)
    {
        if (v_5v_avg < V5_LOW) action = ACT_GCR_DEC;
        else if (v_5v_avg > V5_HIGH && gcr_actual < gcr_use) action = ACT_GCR_INC;
        else if (gcr_actual > gcr_use) action = ACT_GCR_DEC;
    }
    else
    {
        if (gcr_actual < gcr_use) action = ACT_GCR_INC;
        else if (gcr_actual > gcr_use) action = ACT_GCR_DEC;
    }

    if (action == ACT_GCR_NONE)
    {
        gcr_min_counter = 0;
    }
    else if (action == ACT_GCR_INC)
    {
        if (LED_GCR_STEP_AUTO > LED_GCR_MAX - gcr_actual) gcr_actual = LED_GCR_MAX; //Obey max and prevent wrapping
        else gcr_actual += LED_GCR_STEP_AUTO;
        gcr_min_counter = 0;
    }
    else if (action == ACT_GCR_DEC)
    {
        if (LED_GCR_STEP_AUTO > gcr_actual) //Prevent wrapping
        {
            gcr_actual = 0;
            //At this point, power can no longer be cut from the LED drivers, so focus on cutting out extra port if active
            if (usb_extra_state != USB_EXTRA_STATE_DISABLED_UNTIL_REPLUG) //If not in a wait for replug state
            {
                if (usb_extra_state == USB_EXTRA_STATE_ENABLED) //If extra usb is enabled
                {
                    gcr_min_counter++;
                    if (gcr_min_counter > 200) //5ms per check = 1s delay
                    {
                        USB_ExtraSetState(USB_EXTRA_STATE_DISABLED_UNTIL_REPLUG);
                        usb_extra_manual = 0; //Force disable manual mode of extra port
                        if (usb_extra_manual) CDC_print("USB: Disabling extra port until replug and manual mode toggle!\r\n");
                        else CDC_print("USB: Disabling extra port until replug!\r\n");
                    }
                }
            }
        }
        else
        {
            //Power successfully cut back from LED drivers
            //gcr_actual -= LED_GCR_STEP_AUTO;
            gcr_min_counter = 0;

            //If breathe mode is active, the top end can fluctuate if the host can not supply enough current
            //So set the breathe GCR to where it becomes stable
            // if (led_animation_breathing == 1)
            // {
            //     //gcr_breathe = gcr_actual;
            //     //PS: At this point, setting breathing to exhale makes a noticebly shorter cycle
            //     //    and the same would happen maybe one or two more times. Therefore I'm favoring
            //     //    powering through one full breathe and letting gcr settle completely
            // }
        }
    }
}

led_disp_t disp;

void issi3733_prepare_arrays(void)
{
    memset(issidrv,0,sizeof(issi3733_driver_t) * ISSI3733_DRIVER_COUNT);

    int i;
    uint8_t addrs[ISSI3733_DRIVER_COUNT] = ISSI3773_DRIVER_ADDRESSES;

    for (i=0;i<ISSI3733_DRIVER_COUNT;i++)
    {
        issidrv[i].addr = addrs[i];
    }

    issi3733_led_t *cur = led_map;

    while (cur < lede)
    {
        //BYTE: 1 + (SW-1)*16 + (CS-1)
        cur->rgb.g = issidrv[cur->adr.drv-1].pwm + 1 + ((cur->adr.swg-1)*16 + (cur->adr.cs-1));
        cur->rgb.r = issidrv[cur->adr.drv-1].pwm + 1 + ((cur->adr.swr-1)*16 + (cur->adr.cs-1));
        cur->rgb.b = issidrv[cur->adr.drv-1].pwm + 1 + ((cur->adr.swb-1)*16 + (cur->adr.cs-1));

        //BYTE: 1 + (SW-1)*2 + (CS-1)/8
        //BIT: (CS-1)%8
        *(issidrv[cur->adr.drv-1].onoff + 1 + (cur->adr.swg-1)*2+(cur->adr.cs-1)/8) |= (1<<((cur->adr.cs-1)%8));
        *(issidrv[cur->adr.drv-1].onoff + 1 + (cur->adr.swr-1)*2+(cur->adr.cs-1)/8) |= (1<<((cur->adr.cs-1)%8));
        *(issidrv[cur->adr.drv-1].onoff + 1 + (cur->adr.swb-1)*2+(cur->adr.cs-1)/8) |= (1<<((cur->adr.cs-1)%8));

        cur++;
    }
}

void disp_calc_extents(void)
{
    issi3733_led_t *cur = led_map;

    disp.left = 1e10;
    disp.right = -1e10;
    disp.top = -1e10;
    disp.bottom = 1e10;

    while (cur < lede)
    {
        if (cur->x < disp.left) disp.left = cur->x;
        if (cur->x > disp.right) disp.right = cur->x;
        if (cur->y < disp.bottom) disp.bottom = cur->y;
        if (cur->y > disp.top) disp.top = cur->y;

        cur++;
    }

    disp.width = disp.right - disp.left;
    disp.height = disp.top - disp.bottom;
    disp.max_distance = sqrtf(powf(disp.width, 2) + powf(disp.height, 2));
}

void disp_pixel_setup(void)
{
    issi3733_led_t *cur = led_map;

    while (cur < lede)
    {
        cur->px = (cur->x - disp.left) / disp.width * 100;
        cur->py = (cur->y - disp.bottom) / disp.height * 100;
        *cur->rgb.r = 0;
        *cur->rgb.g = 0;
        *cur->rgb.b = 0;

        cur++;
    }
}

void led_matrix_prepare(void)
{
    disp_calc_extents();
    disp_pixel_setup();
}

uint8_t led_enabled;
uint8_t led_lighting_mode;
float led_animation_speed;
uint8_t led_animation_direction;
uint8_t led_animation_orientation;
uint8_t led_animation_breathing;
uint8_t led_animation_breathe_cur;
uint8_t breathe_step;
int8_t breathe_dir;
uint8_t led_animation_glittering;
uint8_t glitter_smooth;
uint8_t glitter_step;
int16_t led_animation_glitter_cur[ISSI3733_LED_COUNT];
int8_t glitter_dir[ISSI3733_LED_COUNT];
uint8_t led_animation_circular;
uint64_t led_next_run;
uint8_t led_game_colors;

uint8_t led_animation_id;
uint8_t led_instruction_id;

issi3733_led_t *led_cur;
uint8_t led_per_run = 15;
float breathe_mult;
float pomod;

void led_run_pattern(led_setup_t *f, float* ro, float* go, float* bo, float pos) {
    float po;
    while (f->end != 1)
    {
        po = pos; //Reset po for new frame

        //Add in any moving effects
        if ((!led_animation_direction && f->ef & EF_SCR_R) || (led_animation_direction && (f->ef & EF_SCR_L)))
        {
            po -= pomod;

            if (po > 100) po -= 100;
            else if (po < 0) po += 100;
        }
        else if ((!led_animation_direction && f->ef & EF_SCR_L) || (led_animation_direction && (f->ef & EF_SCR_R)))
        {
            po += pomod;

            if (po > 100) po -= 100;
            else if (po < 0) po += 100;
        }

        //Check if LED's po is in current frame
        if (po < f->hs) { f++; continue; }
        if (po > f->he) { f++; continue; }
        //note: < 0 or > 100 continue

        //Calculate the po within the start-stop percentage for color blending
        po = (po - f->hs) / (f->he - f->hs);

        //Add in any color effects
        if (f->ef & EF_OVER)
        {
            *ro = (po * (f->re - f->rs)) + f->rs;// + 0.5;
            *go = (po * (f->ge - f->gs)) + f->gs;// + 0.5;
            *bo = (po * (f->be - f->bs)) + f->bs;// + 0.5;
        }
        else if (f->ef & EF_SUBTRACT)
        {
            *ro -= (po * (f->re - f->rs)) + f->rs;// + 0.5;
            *go -= (po * (f->ge - f->gs)) + f->gs;// + 0.5;
            *bo -= (po * (f->be - f->bs)) + f->bs;// + 0.5;
        }
        else
        {
            *ro += (po * (f->re - f->rs)) + f->rs;// + 0.5;
            *go += (po * (f->ge - f->gs)) + f->gs;// + 0.5;
            *bo += (po * (f->be - f->bs)) + f->bs;// + 0.5;
        }

        f++;
    }
}

void set_led_animation_id(uint8_t id) {
    led_animation_id = id;
}

void led_run_glitter(float* ro, float* go, float* bo) {
    double glitter_mult;
    if (led_animation_glittering)
    {
        uint8_t led_id = led_cur->id - 1;
        led_animation_glitter_cur[led_id] += glitter_step * glitter_dir[led_id];
        if(glitter_smooth) {
            if (led_animation_glitter_cur[led_id] >= BREATHE_MAX_STEP)
            {
                glitter_dir[led_id] = -1;
                led_animation_glitter_cur[led_id] = BREATHE_MAX_STEP;
            }
            else if (led_animation_glitter_cur[led_id] <= BREATHE_MIN_STEP)
            {
                glitter_dir[led_id] = 1;
                led_animation_glitter_cur[led_id] = BREATHE_MIN_STEP;
            }
        }
        else {
            if (led_animation_glitter_cur[led_id] >= BREATHE_MAX_STEP)
            {
                uint8_t randy = rand() % 255;
                randy -= 1;
                if (randy > 127)  glitter_dir[led_id] = -1;
                else led_animation_glitter_cur[led_id] = BREATHE_MIN_STEP;
            }
            else if (led_animation_glitter_cur[led_id] <= BREATHE_MIN_STEP)
            {
                uint8_t randy = rand() % 255;
                randy -= 1;
                if (randy > 127) glitter_dir[led_id] = 1;
                else led_animation_glitter_cur[led_id] = BREATHE_MAX_STEP;
            }
        }
        //Brightness curve created for 256 steps, 0 - ~98%
        glitter_mult = 0.000015 * led_animation_glitter_cur[led_id] * led_animation_glitter_cur[led_id];
        glitter_mult += 0.024625;              //add a small amount to get max to 1.0
        if (glitter_mult > 1.0) glitter_mult = 1.0;
        else if (glitter_mult < 0.0) glitter_mult = 0.0;

        *ro *= glitter_mult;
        *go *= glitter_mult;
        *bo *= glitter_mult;
    }
}

__attribute__((weak))
led_instruction_t led_instructions_default[] = { { .end = 1 } };
__attribute__((weak))
void *led_instruction_list[] = {led_instructions_default};
__attribute__((weak))
void *led_game_instruction_list[] = {led_instructions_default};

uint8_t highest_active_layer = 0;
uint32_t temp_layer_state = 0;

__attribute__ ((weak))
void led_matrix_run(void)
{
    float ro;
    float go;
    float bo;
    float po;

    uint8_t led_this_run = 0;
    led_setup_t *f = (led_setup_t*)led_setups[led_animation_id];

    if (led_cur == 0) //Denotes start of new processing cycle in the case of chunked processing
    {
        led_cur = led_map;

        disp.frame += 1;

        breathe_mult = 1;

        if (led_animation_breathing)
        {
            //+60us 119 LED
            led_animation_breathe_cur += breathe_step * breathe_dir;

            if (led_animation_breathe_cur >= BREATHE_MAX_STEP)
                breathe_dir = -1;
            else if (led_animation_breathe_cur <= BREATHE_MIN_STEP)
                breathe_dir = 1;

            //Brightness curve created for 256 steps, 0 - ~98%
            breathe_mult = 0.000015 * led_animation_breathe_cur * led_animation_breathe_cur;
            if (breathe_mult > 1) breathe_mult = 1;
            else if (breathe_mult < 0) breathe_mult = 0;
        }

        //Only needs to be calculated once per frame
        pomod = (float)(disp.frame % (uint32_t)(1000.0f / led_animation_speed)) / 10.0f * led_animation_speed;
        pomod *= 100.0f;
        pomod = (uint32_t)pomod % 10000;
        pomod /= 100.0f;

        highest_active_layer = 0;
        temp_layer_state = layer_state;

        while (temp_layer_state >> 1 != 0) {
            highest_active_layer++;
            temp_layer_state = temp_layer_state >> 1;
        }
    }

    while (led_cur < lede && led_this_run < led_per_run)
    {
        ro = 0;
        go = 0;
        bo = 0;
        float hundredpcent;
        hundredpcent = 100.0;
        switch(led_animation_orientation) {
            case LED_SCROLL_HORIZ:
                po = led_cur->px;
                break;
            case LED_SCROLL_VERT:
                po = led_cur->py;
                break;
            case LED_SCROLL_DIAG:
                led_animation_direction = 0;
                po = led_cur->py + led_cur->px;
                break;
            case LED_SCROLL_DIAG2:
                led_animation_direction = 0;
                po = (led_cur->py / 4) + led_cur->px;  //cool diagnal
                break;
            case LED_SCROLL_DIAG3:
                led_animation_direction = 0;
                po = fabsf(((hundredpcent - led_cur->py) / 4) + led_cur->px);  //cool opposite diagnal
                break;
            case LED_SCROLL_CIRC:
                po = sqrtf((powf(fabsf((disp.width / 2) - (led_cur->x - disp.left)), 2) + powf(fabsf((disp.height / 2) - (led_cur->y - disp.bottom)), 2))) / disp.max_distance * 100;
                break;
            case LED_SCROLL_CENT:
                po = (disp.right - led_cur->x >= 7.594) ? ((led_cur->py / 6) + ((disp.right - (led_cur->x - disp.left)) * 3)): (led_cur->py / 6) + (led_cur->x * 3);  //7.594 is middle of spacebar led
                break;
            case LED_SCROLL_CENT2:
                po = (led_cur->px >= 50) ? fabsf(((led_cur->py) / 4) + (hundredpcent - led_cur->px))  : (led_cur->py / 4) + led_cur->px;   //this one does have of keyboard
                break;
            case LED_SCROLL_SPLIT:
                led_animation_direction = 0;
                po = (disp.right - led_cur->x >= 7.294) ? fabsf(((hundredpcent - led_cur->py) / 4) + (hundredpcent - led_cur->px )) : fabsf((led_cur->py / 4) + (led_cur->px));   //split diagnal shifted left
                break;
            case LED_SCROLL_SPLIT2:
                po = (disp.right - led_cur->x >= 7.594) ? fabsf( ((hundredpcent - led_cur->py) / 4) + led_cur->px) : fabsf((led_cur->py / 4) + (hundredpcent - led_cur->px)) ;   //cool no glitching either direction
                break;
            case LED_SCROLL_FUNK1:
                led_animation_direction = 0;
                po = (disp.right - led_cur->x >= 7.594) ? fabsf( ((hundredpcent - led_cur->py) / 4) + led_cur->px) : fabsf( (led_cur->py / 4) + led_cur->px) ;   //roll over diag in middle
                break;
            case LED_SCROLL_FUNK2:
                led_animation_direction = 0;
                po = (disp.right - led_cur->x >= 7.594) ? fabsf( ((hundredpcent - led_cur->py) / 4) + (hundredpcent - led_cur->px )) : fabsf((led_cur->py / 4) + (hundredpcent - led_cur->px)) ;
                break;
            default:
                po = led_cur->px;
        }

        if (led_lighting_mode == LED_MODE_KEYS_ONLY && led_cur->scan == 255)
        {
            //Do not act on this LED
        }
        else if (led_lighting_mode == LED_MODE_NON_KEYS_ONLY && led_cur->scan != 255)
        {
            //Do not act on this LED
        }
        else if (led_lighting_mode == LED_MODE_INDICATORS_ONLY)
        {
            //Do not act on this LED (Only show indicators)
        }
        else
        {
            led_instruction_t *led_cur_instruction;

            if (led_game_colors) {
              led_cur_instruction = led_game_instruction_list[led_instruction_id];
            }
            else {
              led_cur_instruction = led_instruction_list[led_instruction_id];
            }

            //Act on LED
            if (led_cur_instruction->end) {
                // If no instructions, use normal pattern
                led_run_pattern(f, &ro, &go, &bo, po);
                led_run_glitter(&ro, &go, &bo);
            } else {
                uint8_t skip;
                uint8_t modid = (led_cur->id - 1) / 32;                         //PS: Calculate which id# contains the led bit
                uint32_t modidbit = 1 << ((led_cur->id - 1) % 32);              //PS: Calculate the bit within the id#
                uint32_t *bitfield;                                             //PS: Will point to the id# within the current instruction

                while (!led_cur_instruction->end) {
                    skip = 0;

                    //PS: Check layer active first
                    if (led_cur_instruction->flags & LED_FLAG_MATCH_LAYER) {
                        if (led_cur_instruction->layer != highest_active_layer) skip = 1;
                    }

                    if (!skip)
                    {
                        if (led_cur_instruction->flags & LED_FLAG_MATCH_ID) {
                            bitfield = &led_cur_instruction->id0 + modid;         //PS: Add modid as offset to id0 address. *bitfield is now idX of the led id
                            if (~(*bitfield) & modidbit) skip = 1;                //PS: Check if led bit is not set in idX
                        }
                    }

                    if (!skip) {
                        //set colors
                        if (led_cur_instruction->flags & LED_FLAG_USE_RGB) {
                            ro = led_cur_instruction->r;
                            go = led_cur_instruction->g;
                            bo = led_cur_instruction->b;
                        } else if (led_cur_instruction->flags & LED_FLAG_USE_PATTERN) {
                            led_run_pattern(led_setups[led_cur_instruction->pattern_id], &ro, &go, &bo, po);
                        } else if (led_cur_instruction->flags & LED_FLAG_USE_ROTATE_PATTERN) {
                            led_run_pattern(f, &ro, &go, &bo, po);
                        }

                        //apply glitter clouds effect
                        if(led_cur_instruction->flags & LED_FLAG_USE_GLITTER) {
                          led_run_glitter(&ro, &go, &bo);
                        }
                    }

                    led_cur_instruction++;
                }
            }
        }

        //Clamp values 0-255
        if (ro > 255) ro = 255; else if (ro < 0) ro = 0;
        if (go > 255) go = 255; else if (go < 0) go = 0;
        if (bo > 255) bo = 255; else if (bo < 0) bo = 0;

        if (led_animation_breathing)
        {
            ro *= breathe_mult;
            go *= breathe_mult;
            bo *= breathe_mult;
        }

        *led_cur->rgb.r = (uint8_t)ro;
        *led_cur->rgb.g = (uint8_t)go;
        *led_cur->rgb.b = (uint8_t)bo;

#ifdef USB_LED_INDICATOR_ENABLE
        if (keyboard_leds())
        {
            uint8_t kbled = keyboard_leds();
            if (
                #if USB_LED_NUM_LOCK_SCANCODE != 255
                (led_cur->scan == USB_LED_NUM_LOCK_SCANCODE && kbled & (1<<USB_LED_NUM_LOCK)) ||
                #endif //NUM LOCK
                #if USB_LED_CAPS_LOCK_SCANCODE != 255
                (led_cur->scan == USB_LED_CAPS_LOCK_SCANCODE && kbled & (1<<USB_LED_CAPS_LOCK)) ||
                #endif //CAPS LOCK
                #if USB_LED_SCROLL_LOCK_SCANCODE != 255
                (led_cur->scan == USB_LED_SCROLL_LOCK_SCANCODE && kbled & (1<<USB_LED_SCROLL_LOCK)) ||
                #endif //SCROLL LOCK
                #if USB_LED_COMPOSE_SCANCODE != 255
                (led_cur->scan == USB_LED_COMPOSE_SCANCODE && kbled & (1<<USB_LED_COMPOSE)) ||
                #endif //COMPOSE
                #if USB_LED_KANA_SCANCODE != 255
                (led_cur->scan == USB_LED_KANA_SCANCODE && kbled & (1<<USB_LED_KANA)) ||
                #endif //KANA
                (0))
            {
                *led_cur->rgb.r = 255 - *led_cur->rgb.r;
                *led_cur->rgb.g = 255 - *led_cur->rgb.g;
                *led_cur->rgb.b = 255 - *led_cur->rgb.b;
            }
        }
#endif //USB_LED_INDICATOR_ENABLE

        led_cur++;
        led_this_run++;
    }
}

uint8_t led_matrix_init(void)
{
    DBGC(DC_LED_MATRIX_INIT_BEGIN);

    issi3733_prepare_arrays();

    led_matrix_prepare();

    disp.frame = 0;
    led_next_run = 0;

    led_enabled = 1;
    led_lighting_mode = LED_MODE_NORMAL;
    led_animation_speed = 3.0f;
    led_animation_direction = 0;
    led_animation_orientation = LED_SCROLL_CENT2;  //setup default animation orientation (defined in header file)
    led_animation_breathing = 0;                  //turn breathing off by default
    led_animation_glittering = 0;                 //turn glitter off by default
    breathe_step = 1;
    breathe_dir = 1;
    glitter_smooth = 1;    //glitter vibes = 0 and cloud vibes = 1
    led_animation_breathe_cur = BREATHE_MIN_STEP;
    glitter_step = 2;
    led_game_colors = 0;                        //set game mode leds off default
    led_instruction_id = 0;                     //set default led instruction
    set_led_animation_id(0);                    //set default animation setup/colorPattern

    //setup random glitter steps to start
    uint8_t i;
    srand(710);
    for(i=0; i < ISSI3733_LED_COUNT; i++) {
      uint8_t rn = rand() % 255;
      led_animation_glitter_cur[i] = rn;
      if(i % 2) glitter_dir[i] = 1;
      else glitter_dir[i] = -1;
    }

    gcr_min_counter = 0;
    v_5v_cat_hit = 0;

    //Run led matrix code once for initial LED coloring
    led_cur = 0;
    rgb_matrix_init_user();
    led_matrix_run();

    DBGC(DC_LED_MATRIX_INIT_COMPLETE);

    return 0;
}

__attribute__ ((weak))
void rgb_matrix_init_user(void) {

}

#define LED_UPDATE_RATE 10  //ms

//led data processing can take time, so process data in chunks to free up the processor
//this is done through led_cur and lede
void led_matrix_task(void)
{
    if (led_enabled)
    {
        //If an update may run and frame processing has completed
        if (CLK_get_ms() >= led_next_run && led_cur == lede)
        {
            uint8_t drvid;

            led_next_run = CLK_get_ms() + LED_UPDATE_RATE;  //Set next frame update time

            //NOTE: GCR does not need to be timed with LED processing, but there is really no harm
            if (gcr_actual != gcr_actual_last)
            {
                for (drvid=0;drvid<ISSI3733_DRIVER_COUNT;drvid++)
                    I2C_LED_Q_GCR(drvid); //Queue data
                gcr_actual_last = gcr_actual;
            }

            for (drvid=0;drvid<ISSI3733_DRIVER_COUNT;drvid++)
                I2C_LED_Q_PWM(drvid); //Queue data

            i2c_led_q_run();

            led_cur = 0; //Signal next frame calculations may begin
        }
    }

    //Process more data if not finished
    if (led_cur != lede)
    {
        //m15_off; //debug profiling
        led_matrix_run();
        // if(led_animation_breathing)
        // {
        //     uprintf("\n");
        // }
        //m15_on; //debug profiling
    }
}

