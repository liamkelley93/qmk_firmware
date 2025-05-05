#include QMK_KEYBOARD_H


//notes:: LSHIFT and RSHIFT are defined in my keymap as space cadet shift

enum alt_keycodes {
    L_BRI = SAFE_RANGE, //LED Brightness Increase
    L_BRD,              //LED Brightness Decrease
    L_PTN,              //LED Pattern Select Next
    L_PTP,              //LED Pattern Select Previous
    L_PSI,              //LED Pattern Speed Increase
    L_PSD,              //LED Pattern Speed Decrease
    L_T_MD,             //LED Toggle Mode
    L_T_ONF,            //LED Toggle On / Off
    L_ON,               //LED On
    L_OFF,              //LED Off
    L_T_BR,             //LED Toggle Breath Effect
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction
    U_T_AUTO,           //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,           //USB Toggle Automatic GCR control
    DBG_TOG,            //DEBUG Toggle On / Off
    DBG_MTRX,           //DEBUG Toggle Matrix Prints
    DBG_KBD,            //DEBUG Toggle Keyboard Prints
    DBG_MOU,            //DEBUG Toggle Mouse Prints
    MD_BOOT,            //Restart into bootloader after hold timeout
    L_I_N,              //LED instruction preset Next
    L_I_P,              //LED instruciton preset Previous
    L_SC_N,             //LED Pattern scroll next
    L_SC_P,             //LED Pattern scroll next
    L_GLITI,            //LED Breath Speed Increase
    L_GLITD,            //LED Breath Speed Decrease
    L_GLITSM,           //LED Glitter smooth (glitter vs clouds)
    L_T_GCM,            //LED Toggle Game Color Mode
    L_T_GLIT,           //LED Toggle Glitter Effect
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,          KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [1] = LAYOUT(
        KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_MUTE, \
        L_T_BR,   L_PSI,   L_BRI,   L_SC_N,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRMD, KC_BRMU, KC_TRNS, KC_PAUS, \
        L_T_GLIT, L_PSD,   L_BRD,   L_SC_P,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          L_T_GCM, KC_VOLU, \
        L_GLITSM, L_GLITD, L_T_ONF, L_T_PTD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          L_I_P,   KC_VOLD, \
        KC_TRNS,  KC_TRNS, KC_MPRV,                            KC_MPLY,                            KC_MNXT, KC_TRNS, L_PTP,   L_I_N,   L_PTN  \
    ),
    /*
    [X] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  \
    ),
    */
};

const uint16_t PROGMEM fn_actions[] = {

};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (keyboard_report->mods & MOD_BIT(KC_LSHIFT) || keyboard_report->mods & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (keyboard_report->mods & MOD_BIT(KC_LCTL) || keyboard_report->mods & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (keyboard_report->mods & MOD_BIT(KC_LALT) || keyboard_report->mods & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_PTN:
            if (record->event.pressed) {
                if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
            return false;
        case L_PTP:
            if (record->event.pressed) {
                if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
                else led_animation_id--;
            }
            return false;
        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        case L_T_ONF:
            if (record->event.pressed) {
                led_enabled = !led_enabled;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_ON:
            if (record->event.pressed) {
                led_enabled = 1;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_OFF:
            if (record->event.pressed) {
                led_enabled = 0;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        case L_T_PTD:
            if (record->event.pressed) {
                led_animation_direction = !led_animation_direction;
            }
            return false;
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        //custom pleasuretek keycodes
        case L_I_N:
            if (record->event.pressed) {
                (led_instruction_id == led_instruction_count - 1) ? led_instruction_id = 0 : led_instruction_id++;
                set_led_animation_id(led_default_rotate_pattern[led_instruction_id]);
            }
            return false;
        case L_I_P:
            if (record->event.pressed) {
                (led_instruction_id == 0) ? led_instruction_id = led_instruction_count - 1 : led_instruction_id--;
                set_led_animation_id(led_default_rotate_pattern[led_instruction_id]);
            }
            return false;
        case L_SC_N:
            if(record->event.pressed) {
              led_animation_orientation++;
              if (led_animation_orientation > LED_SCROLL_MAX_INDEX) led_animation_orientation = LED_SCROLL_HORIZ;
            }
            return false;
        case L_SC_P:
            if(record->event.pressed) {
              if (led_animation_orientation == 0) led_animation_orientation = LED_SCROLL_MAX_INDEX;
              led_animation_orientation--;
            }
            return false;
        case L_GLITI:
            if (record->event.pressed) {
                if(glitter_step < 16) {
                  glitter_step++;
                }
            }
            return false;
        case L_GLITD:
            if (record->event.pressed) {
                if(glitter_step > 1) {
                  glitter_step--;
                } else {
                  glitter_step = 1;
                }
            }
            return false;
        case L_GLITSM:
            if (record->event.pressed) {
              glitter_smooth = !glitter_smooth;
            }
            return false;
        case L_T_GLIT:
            if (record->event.pressed) {
                led_animation_glittering = !led_animation_glittering;
                if (led_animation_glittering) {
                  uint8_t i;
                  for(i = 0; i < ISSI3733_LED_COUNT; i++) {
                    uint8_t rn = rand() % 255;
                    led_animation_glitter_cur[i] = rn;
                    if(i % 2) glitter_dir[i] = 1;
                    else glitter_dir[i] = -1;
                  }
                }
            }
            return false;
        case L_T_GCM:
            if (record->event.pressed) {
              led_game_colors = !led_game_colors;
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}


led_instruction_t led_instructions_green_teal_and_purple[] = {
    { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 2684297214, .id1 = 545252351, .id2 = 4294967288, .id3 = 511, .r = 32, .g = 255, .b = 80 }, // teal color for most keys, including ring
    { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 1610670081, .id1 = 3749714944, .id2 = 7, .id3 = 0, .r = 192, .g = 32, .b = 255 }, // purple color for accent keys (#s 1, 15, 31, 43-45, 56-61, 63-67)
    { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 3221233664, .id1 = 2151645215, .id2 = 7342087, .id3 = 0, .r = 32, .g = 255, .b = 80 }, // action keys are teal when fn is pressed (#s 16-19, 31-34, 45-48, 57, 65-67)
    { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 738222079, .id1 = 1912604672, .id2 = 0, .id3 = 0, .r = 116, .g = 228, .b = 140 }, // non-custom action keys (i.e. mute, volume up, F10, etc.) are dull teal when fn is pressed (#s 1-13, 15, 27, 28, 30, 44, 58, 61-63)
    { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 0, .id2 = 4294967288, .id3 = 511, .r = 32, .g = 255, .b = 80 }, // ring lights still can glitter when fn is pressed (#s 68-105)
    { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 0, .id1 = 2147484672, .id2 = 0, .id3 = 0, .r = 192, .g = 32, .b = 255 }, // fn and enter are purple when pressed
    { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL, .layer = 1, .id0 = 335028224, .id1 = 218039292, .id2 = 0, .id3 = 0 }, // other keys off when fn is pressed
    {.end = 1 }
};

led_instruction_t led_instructions_blue_teal_and_pink[] = {
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 2684297214, .id1 = 545252351, .id2 = 4294967288, .id3 = 511, .r = 47, .g = 198, .b = 178 }, // teal color for most keys, including ring
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 1610670081, .id1 = 3749714944, .id2 = 7, .id3 = 0, .r = 255, .g = 32, .b = 207 }, // pink color for accent keys (#s 1, 15, 31, 43-45, 56-61, 63-67)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 3221233664, .id1 = 2151645215, .id2 = 7342087, .id3 = 0, .r = 47, .g = 198, .b = 178 }, // action keys are teal when fn is pressed (#s 16-19, 31-34, 45-48, 57, 65-67)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 738222079, .id1 = 1912604672, .id2 = 0, .id3 = 0, .r = 116, .g = 227, .b = 212 }, // non-custom action keys (i.e. mute, volume up, F10, etc.) are dull teal when fn is pressed (#s 1-13, 15, 27, 28, 30, 44, 58, 61-63)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 0, .id2 = 4294967288, .id3 = 511, .r = 47, .g = 198, .b = 178 }, // ring lights still can glitter when fn is pressed (#s 68-105)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 0, .id1 = 2147484672, .id2 = 0, .id3 = 0, .r = 255, .g = 32, .b = 207 }, // fn and enter are pink when pressed
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL, .layer = 1, .id0 = 335028224, .id1 = 218039292, .id2 = 0, .id3 = 0 }, // other keys off when fn is pressed
{.end = 1 }
};


led_instruction_t led_instructions_white_mains[] = {
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 0, .id0 = 2214526976, .id1 = 1040639, .id2 = 0, .id3 = 0, .r = 255, .g = 255, .b = 255 }, // white color for alpha keys (#s 17-26, 32-40, 46-52)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 2080440319, .id1 = 4293926656, .id2 = 4294967295, .id3 = 511 }, // all pattern options for other keys & light ring
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .layer = 1, .id0 = 3221233664, .id1 = 2151645215, .id2 = 7342087, .id3 = 0 }, // action keys are pattern when fn is pressed (#s 16-19, 31-34, 45-48, 57, 65-67)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 738222079, .id1 = 1912604672, .id2 = 0, .id3 = 0, .r = 128, .g = 128, .b = 128 }, // non-custom action keys (i.e. mute, volume up, F10, etc.) are off-white when fn is pressed (#s 1-13, 15, 27, 28, 30, 44, 58, 61-63)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 0, .id2 = 4294967288, .id3 = 511 }, // ring lights are pattern + glitter when fn is pressed (#s 68-105)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 0, .id1 = 2147484672, .id2 = 0, .id3 = 0, .r = 255, .g = 255, .b = 255 }, // fn and enter are white when pressed
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL, .layer = 1, .id0 = 335028224, .id1 = 218039292, .id2 = 0, .id3 = 0 }, // other keys off when fn is pressed
{.end = 1 }
};

led_instruction_t led_instructions_gradient[] = {
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 32767, .id1 = 0, .id2 = 4290772992, .id3 = 31, .r = 45, .g = 143, .b = 129 }, // top row
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 1073709056, .id1 = 0, .id2 = 2097152, .id3 = 32, .r = 104, .g = 170, .b = 159 }, // fourth row 
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 3221225472, .id1 = 4095, .id2 = 1048576, .id3 = 64, .r = 155, .g = 198, .b = 189 }, // third row
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 0, .id1 = 67104768, .id2 = 524288, .id3 = 128, .r = 205, .g = 226, .b = 222 }, // second row
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 0, .id1 = 4227858432, .id2 = 524287, .id3 = 256, .r = 255, .g = 255, .b = 255 }, // first row
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 3221233664, .id1 = 2151645215, .id2 = 7342087, .id3 = 0, .r = 45, .g = 143, .b = 129 }, // action keys are teal when fn is pressed (#s 16-19, 31-34, 45-48, 57, 65-67)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 738222079, .id1 = 1912604672, .id2 = 0, .id3 = 0, .r = 155, .g = 198, .b = 189 }, // non-custom action keys (i.e. mute, volume up, F10, etc.) are dull teal when fn is pressed (#s 1-13, 15, 27, 28, 30, 44, 58, 61-63)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 0, .id2 = 4294967288, .id3 = 511, .r = 45, .g = 143, .b = 129 }, // ring lights still can glitter when fn is pressed (#s 68-105)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 0, .id1 = 2147484672, .id2 = 0, .id3 = 0, .r = 255, .g = 255, .b = 255 }, // fn and enter are white when pressed
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL, .layer = 1, .id0 = 335028224, .id1 = 218039292, .id2 = 0, .id3 = 0 }, // other keys off when fn is pressed
{.end = 1 }
};

led_instruction_t led_instructions_default[] = {
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 4294967295, .id1 = 4294967295, .id2 = 4294967295, .id3 = 511 }, // all keys, use regular patterns but also with glitter effect togglable
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .layer = 1, .id0 = 3221233664, .id1 = 2151645215, .id2 = 7342087, .id3 = 0 }, // action keys are pattern when fn is pressed (#s 16-19, 31-34, 45-48, 57, 65-67)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 0, .id2 = 4294967288, .id3 = 511 }, // ring lights are pattern + glitter when fn is pressed (#s 68-105)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 0, .id1 = 2147484672, .id2 = 0, .id3 = 0, .r = 255, .g = 255, .b = 255 }, // fn and enter are white when pressed
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL, .layer = 1, .id0 = 335028224, .id1 = 218039292, .id2 = 0, .id3 = 0 }, // other keys off when fn is pressed
{.end = 1 }
};

led_instruction_t led_instructions_c2077[] = {
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 2684297214, .id1 = 545252351, .id2 = 4294967288, .id3 = 511, .pattern_id = 18 }, // c2077 for most keys
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 0, .id0 = 1610670081, .id1 = 3749714944, .id2 = 7, .id3 = 0, .r = 251,	.g = 245, .b = 23 }, // yellow color for accent keys (#s 1, 15, 31, 43-45, 56-61, 63-67)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 3221233664, .id1 = 2151645215, .id2 = 7342087, .id3 = 0, .r = 251, .g = 245, .b = 23 }, // action keys are yellow when fn is pressed (#s 16-19, 31-34, 45-48, 57, 65-67)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 738222079, .id1 = 1912604672, .id2 = 0, .id3 = 0, .r = 199, .g = 197, .b = 155 }, // non-custom action keys (i.e. mute, volume up, F10, etc.) are dull yellow when fn is pressed (#s 1-13, 15, 27, 28, 30, 44, 58, 61-63)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 0, .id2 = 4294967288, .id3 = 511, .pattern_id = 18 }, // ring lights still can glitter when fn is pressed (#s 68-105)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN, .layer = 1, .id0 = 0, .id1 = 2147484672, .id2 = 0, .id3 = 0, .pattern_id = 18 }, // fn and enter are purple when pressed
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL, .layer = 1, .id0 = 335028224, .id1 = 218039292, .id2 = 0, .id3 = 0 }, // other keys off when fn is pressed
{.end = 1 }
};

led_instruction_t led_instructions_white_teal[] = {
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 1, .id1 = 2147484672, .id2 = 4294967288, .id3 = 511, .r = 32, .g = 255, .b = 80 }, // teal color for ring, esc, fn, enter
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 1610661888, .id1 = 528488448, .id2 = 7, .id3 = 0, .r = 116, .g = 228, .b = 140 }, // dull teal color for accent keys (#s 15, 31, 44, 45, 56-61, 63, 65-67)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 2684305406, .id1 = 1618994175, .id2 = 0, .id3 = 0, .id3 = 0, .r = 200, .g = 200, .b = 200 }, // white color for other keys
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 3221233664, .id1 = 2151645215, .id2 = 7342087, .id3 = 0, .r = 32, .g = 255, .b = 80 }, // action keys are teal when fn is pressed (#s 16-19, 31-34, 45-48, 57, 65-67)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 738222079, .id1 = 1912604672, .id2 = 0, .id3 = 0, .r = 116, .g = 228, .b = 140 }, // non-custom action keys (i.e. mute, volume up, F10, etc.) are dull teal when fn is pressed (#s 1-13, 15, 27, 28, 30, 44, 58, 61-63)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 0, .id2 = 4294967288, .id3 = 511, .r = 32, .g = 255, .b = 80 }, // ring lights still can glitter when fn is pressed (#s 68-105)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 0, .id1 = 2147484672, .id2 = 0, .id3 = 0, .r = 32, .g = 255, .b = 80 }, // fn and enter are teal when pressed
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL, .layer = 1, .id0 = 335028224, .id1 = 218039292, .id2 = 0, .id3 = 0 }, // other keys off when fn is pressed
{.end = 1 }
};

led_instruction_t led_game_instructions_green_teal_and_purple[] = {
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 2147614721, .id1 = 1027, .id2 = 4294967288, .id3 = 511, .r = 192, .g = 32, .b = 255 }, // purple color for wasd, esc, enter, and ring (#s 1, 18, 32-34, 43, 68-105)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 2147352574, .id1 = 4294966268, .id2 = 7, .id3 = 0, .r = 32, .g = 255, .b = 80 }, // everything else is teal
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0, .id1 = 2147484672, .id2 = 4294967288, .id3 = 511, .r = 192, .g = 32, .b = 255 }, // purple color for fn (64), enter (43), and ring when fn is pressed
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL,     .layer = 1, .id0 = 4294967295, .id1 = 2147482623, .id2 = 7, .id3 = 0 }, // all other LEDs off when fn is pressed
{.end = 1 }
};

led_instruction_t led_game_instructions_blue_teal_and_pink[] = {
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 2147614721, .id1 = 1027, .id2 = 4294967288, .id3 = 511, .r = 255, .g = 32, .b = 207 }, // pink color for wasd, esc, enter, and ring (#s 1, 18, 32-34, 43, 68-105)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 2147352574, .id1 = 4294966268, .id2 = 7, .id3 = 0, .r = 47, .g = 198, .b = 178 }, // everything else is blue teal
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0, .id1 = 2147484672, .id2 = 4294967288, .id3 = 511, .r = 255, .g = 32, .b = 207 }, // pink color for fn (64), enter (43), and ring when fn is pressed
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL,     .layer = 1, .id0 = 4294967295, .id1 = 2147482623, .id2 = 7, .id3 = 0 }, // all other LEDs off when fn is pressed
{.end = 1 }
};

led_instruction_t led_game_instructions_white_mains[] = {
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN,  .layer = 0, .id0 = 2147614721, .id1 = 1027, .id2 = 4294967288, .id3 = 511 }, // rotate pattern for wasd, esc, enter, and ring (#s 1, 18, 32-34, 43, 68-105)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 2147352574, .id1 = 4294966268, .id2 = 7, .id3 = 0, .r = 255, .g = 255, .b = 255 }, // everything else is white
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN,  .layer = 1, .id0 = 0, .id1 = 2147484672, .id2 = 4294967288, .id3 = 511 }, // rotating color for fn (64), enter (43), and ring when fn is pressed
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL,     .layer = 1, .id0 = 4294967295, .id1 = 2147482623, .id2 = 7, .id3 = 0 }, // all other LEDs off when fn is pressed
{.end = 1 }
};

led_instruction_t led_game_instructions_white_and_red[] = {
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 2147614721, .id1 = 1027, .id2 = 4294967288, .id3 = 511, .r = 255, .g = 0, .b = 0 }, // red color for wasd, esc, enter, and ring (#s 1, 18, 32-34, 43, 68-105)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 2147352574, .id1 = 4294966268, .id2 = 7, .id3 = 0, .r = 255, .g = 255, .b = 255 }, // everything else is white
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0, .id1 = 2147484672, .id2 = 4294967288, .id3 = 511, .r = 255, .g = 0, .b = 0 }, // red color for fn (64), enter (43), and ring when fn is pressed
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL,     .layer = 1, .id0 = 4294967295, .id1 = 2147482623, .id2 = 7, .id3 = 0 }, // all other LEDs off when fn is pressed
{.end = 1 }
};

led_instruction_t led_game_instructions_white_teal[] = {
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 2147614721, .id1 = 1027, .id2 = 4294967288, .id3 = 511, .r = 32, .g = 255, .b = 80 }, // teal color for wasd, esc, enter, and ring (#s 1, 18, 32-34, 43, 68-105)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 2147352574, .id1 = 4294966268, .id2 = 7, .id3 = 0, .r = 116, .g = 228, .b = 140 }, // everything else is light teal
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0, .id1 = 2147484672, .id2 = 4294967288, .id3 = 511, .r = 32, .g = 255, .b = 80 }, // teal color for fn (64), enter (43), and ring when fn is pressed
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL,     .layer = 1, .id0 = 4294967295, .id1 = 2147482623, .id2 = 7, .id3 = 0 }, // all other LEDs off when fn is pressed
{.end = 1 }
};

led_instruction_t led_game_instructions_c2077[] = {
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 2147614721, .id1 = 1027, .id2 = 4294967288, .id3 = 511, .r = 251,	.g = 245, .b = 23 }, // yellow color for wasd, esc, enter, and f11 (#s 1, 12, 36, 52, 53, 54, 63)
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,  .layer = 0, .id0 = 2147352574, .id1 = 4294966268, .id2 = 7, .id3 = 0, .pattern_id = 18 }, // everything else is c2077 pattern
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0, .id1 = 2147484672, .id2 = 4294967288, .id3 = 511, .r = 251,	.g = 245, .b = 23 }, // yellow color for fn (64), enter (43), and ring when fn is pressed
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL,     .layer = 1, .id0 = 4294967295, .id1 = 2147482623, .id2 = 7, .id3 = 0 }, // all other LEDs off when fn is pressed
{.end = 1 }
};

void *led_instruction_list[] = {
    led_instructions_green_teal_and_purple,
    led_instructions_blue_teal_and_pink,
    led_instructions_white_teal,
    led_instructions_gradient,
    led_instructions_c2077,
    led_instructions_white_mains,
    led_instructions_default
};

void *led_game_instruction_list[] = {
    led_game_instructions_green_teal_and_purple,
    led_game_instructions_blue_teal_and_pink,
    led_game_instructions_white_teal,
    led_game_instructions_white_teal,
    led_game_instructions_c2077,
    led_game_instructions_white_mains,
    led_game_instructions_white_and_red
};

const uint8_t led_instruction_count = sizeof(led_instruction_list) / sizeof(led_instruction_list[0]);

uint8_t led_default_rotate_pattern[led_instruction_count] = {  // each instruction group in led_instruction_list can have a default rotate pattern to set on change
    0,
    0,
    0,
    0,
    0,
    4,
    4
};


//this runs once when keyboard is plugged in
void rgb_matrix_init_user(void) {
    //S et which from led_instruction_list should be default
    uint8_t index = 0;    // led_instructions_pleasuretek  is position 0 in led_instruction_list  -- change this number to match in led_instruction_list to set default
    led_instruction_id = index;
    set_led_animation_id(led_default_rotate_pattern[index]);
}
