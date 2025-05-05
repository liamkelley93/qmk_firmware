#include QMK_KEYBOARD_H

enum ctrl_keycodes {
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
    L_T_BR,             //LED Toggle Breathe Effect
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction
    U_T_AUTO,           //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,           //USB Toggle Automatic GCR control
    DBG_TOG,            //DEBUG Toggle On / Off
    DBG_MTRX,           //DEBUG Toggle Matrix Prints
    DBG_KBD,            //DEBUG Toggle Keyboard Prints
    DBG_MOU,            //DEBUG Toggle Mouse Prints
    MD_BOOT,            //Restart into bootloader after hold timeout
    L_I_N,              //LED instruction preset Next
    L_I_P,              //LED instruction preset Previous
    L_SC_N,             //LED Pattern scroll next
    L_SC_P,             //LED Pattern scroll next
    L_GLITI,            //LED Glitter Speed Increase
    L_GLITD,            //LED Glitter Speed Decrease
    L_GLITSM,           //LED Glitter smooth (glitter vs clouds)
    L_T_GCM,            //LED Toggle Game Color Mode
    L_T_GLIT,           //LED Toggle Glitter Effect
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP, \
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(1),   KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [1] = LAYOUT(
        KC_SLEP,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_MUTE, KC_TRNS, KC_TRNS, \
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_MPLY, KC_MSTP, KC_VOLU, \
        L_T_BR,   L_PSI,   L_BRI,   L_SC_N,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_MPRV, KC_MNXT, KC_VOLD, \
        L_T_GLIT, L_PSD,   L_BRD,   L_SC_P,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, L_T_GCM, \
        L_GLITSM, L_T_MD,  L_T_ONF, L_T_PTD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              L_I_P,   \
        KC_TRNS,  KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            L_PTP,   L_I_N,   L_PTN \
    ),
    /*
    [X] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG_NKRO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS \
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

// led_instruction_t led_instructions[] = {
//     // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 10, .id1 = 9, .r = 255, .g = 0, .b = 0 },
//     // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN, .id0 = 4, .id1 = 0, .pattern_id = 8 },
//     // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 8, .id1 = 0, .r = 0, .g = 255, .b = 0 },
//     // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN, .id = 16, .id1 = 0, .pattern_id = 9 },
//     // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 32, .id1 = 0, .r = 0, .g = 0, .b = 255 },
//     // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id0 = 64, .id1 = 0},
//     // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_ROTATE_PATTERN, .id0 = 262144, .id1 = 0, .layer = 0 },
//     // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_ROTATE_PATTERN, .id = 16777216, .id1 = 0, .layer = 1 },
//     { .end = 1 }
// };

led_instruction_t led_instructions_green_teal_and_purple[] = {
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 536813086, .id1 = 1073250300, .id2 = 4286612479, .id3 = 8388607, .r = 32, .g = 255, .b = 80 }, // teal color for most keys, including ring
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 3758154209, .id1 = 3221716995, .id2 = 8354816, .id3 = 0, .r = 192, .g = 32, .b = 255 }, // purple color for accent keys (#s 1,6,7,8,9,14,15,16,30,31,32,33,34,48,49,50,51,63,64,75,76,77,78,79,81,82,83,84,85,86,87)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 3221233664, .id1 = 2151645215, .id2 = 7342087, .id3 = 0, .r = 32, .g = 255, .b = 80 }, // action keys are teal when fn is pressed (#s 14,31,32,33,34,35,36,37,48,49,50,51,52,53,54,64,65,66,67,76,85,86,87)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 0, .id2 = 4286578688, .id3 = 8388607, .r = 32, .g = 255, .b = 80 }, // ring lights still can glitter when fn is pressed (#s 88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 1, .id1 = 1073741824, .id2 = 131072, .id3 = 0, .r = 192, .g = 32, .b = 255 }, // fn, esc, and enter are purple when pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL, .layer = 1, .id0 = 1073733630, .id1 = 1069580256, .id2 = 915448, .id3 = 0 }, // other keys off when fn is pressed
  {.end = 1 }
};

led_instruction_t led_instructions_blue_teal_and_pink[] = {
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 536813086, .id1 = 1073250300, .id2 = 4286612479, .id3 = 8388607, .r = 47, .g = 198, .b = 178 }, // teal color for most keys, including ring
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 3758154209, .id1 = 3221716995, .id2 = 8354816, .id3 = 0, .r = 255, .g = 32, .b = 207 }, // pink color for accent keys (#s 1,6,7,8,9,14,15,16,30,31,32,33,34,48,49,50,51,63,64,75,76,77,78,79,81,82,83,84,85,86,87)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 3221233664, .id1 = 2151645215, .id2 = 7342087, .id3 = 0, .r = 47, .g = 198, .b = 178 }, // action keys are teal when fn is pressed (#s 14,31,32,33,34,35,36,37,48,49,50,51,52,53,54,64,65,66,67,76,85,86,87)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 0, .id2 = 4286578688, .id3 = 8388607, .r = 47, .g = 198, .b = 178 }, // ring lights still can glitter when fn is pressed (#s 88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 1, .id1 = 1073741824, .id2 = 131072, .id3 = 0, .r = 255, .g = 32, .b = 207 }, // fn, esc, and enter are pink when pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL, .layer = 1, .id0 = 1073733630, .id1 = 1069580256, .id2 = 915448, .id3 = 0 }, // other keys off when fn is pressed
  {.end = 1 }
};

led_instruction_t led_instructions_white_mains[] = {
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 0, .id0 = 0, .id1 = 267915260, .id2 = 127, .id3 = 0, .r = 255, .g = 255, .b = 255 }, // white color for alpha keys (#s 35,36,37,38,39,40,41,42,43,44,52,53,54,55,56,57,58,59,60,65,66,67,68,69,70,71)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 4294967295, .id1 = 4027052035, .id2 = 4294967168, .id3 = 8388607 }, // all pattern options for other keys & light ring
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .layer = 1, .id0 = 3221233664, .id1 = 2151645215, .id2 = 7342087, .id3 = 0 }, // action keys are pattern when fn is pressed (#s 14,31,32,33,34,35,36,37,48,49,50,51,52,53,54,64,65,66,67,76,85,86,87)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 0, .id2 = 4286578688, .id3 = 8388607 }, // ring lights are pattern + glitter when fn is pressed (#s 88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 1, .id1 = 1073741824, .id2 = 131072, .id3 = 0, .r = 255, .g = 255, .b = 255 }, // fn, esc, and enter are white when pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL, .layer = 1, .id0 = 1073733630, .id1 = 1069580256, .id2 = 915448, .id3 = 0 }, // other keys off when fn is pressed
  {.end = 1 }
};

led_instruction_t led_instructions_color_accents[] = {
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 536813086, .id1 = 1073250300, .id2 = 4286612479, .id3 = 8388607, .r = 47, .g = 198, .b = 178 }, // teal color for most keys, including ring
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 0, .id2 = 4286578688, .id3 = 8388607 }, // ring lights are pattern + glitter when fn is pressed (#s 88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 1, .id1 = 1073741824, .id2 = 131072, .id3 = 0, .r = 255, .g = 255, .b = 255 }, // fn, esc, and enter are white when pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL, .layer = 1, .id0 = 1073733630, .id1 = 1069580256, .id2 = 915448, .id3 = 0 }, // other keys off when fn is pressed
  {.end = 1 }
};

led_instruction_t led_instructions_gradient[] = {
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 65535, .id1 = 0, .id2 = 0, .id3 = 1048448, .r = 45, .g = 143, .b = 129 }, // top row
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 4294901760, .id1 = 1, .id2 = 0, .id3 = 1048640, .r = 94, .g = 165, .b = 153 }, // fifth row 
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 0, .id1 = 262142, .id2 = 0, .id3 = 2097184, .r = 136, .g = 187, .b = 177 }, // fourth row
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 0, .id1 = 2147221504, .id2 = 0, .id3 = 4194320, .r = 176, .g = 210, .b = 203 }, // third row
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 0, .id1 = 2147483648, .id2 = 4095, .id3 = 0, .r = 215, .g = 232, .b = 229 }, // second row
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 0, .id1 = 0, .id2 = 4294963200, .id3 = 15, .r = 255, .g = 255, .b = 255 }, // first row
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 3221233664, .id1 = 2151645215, .id2 = 7342087, .id3 = 0, .r = 45, .g = 143, .b = 129 }, // action keys are teal when fn is pressed (#s 14,31,32,33,34,35,36,37,48,49,50,51,52,53,54,64,65,66,67,76,85,86,87)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 0, .id2 = 4286578688, .id3 = 8388607 }, // ring lights are pattern + glitter when fn is pressed (#s 88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 1, .id1 = 1073741824, .id2 = 131072, .id3 = 0, .r = 255, .g = 255, .b = 255 }, // fn, esc, and enter are white when pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL, .layer = 1, .id0 = 1073733630, .id1 = 1069580256, .id2 = 915448, .id3 = 0 }, // other keys off when fn is pressed
  {.end = 1 }
};

led_instruction_t led_instructions_xmas[] = {
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 536813086, .id1 = 1073250300, .id2 = 33791, .id3 = 0, .r = 0, .g = 255, .b = 0 }, // green color for most keys (not ring)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 3758154209, .id1 = 3221716995, .id2 = 8354816, .id3 = 0, .r = 255, .g = 0, .b = 0 }, // red color for accent keys (#s 1,6,7,8,9,14,15,16,30,31,32,33,34,48,49,50,51,63,64,75,76,77,78,79,81,82,83,84,85,86,87)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN, .layer = 0, .id0 = 0, .id1 = 0, .id2 = 4286578688, .id3 = 8388607, .pattern_id = 17 }, // red and green stripes for ring
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 3221233664, .id1 = 2151645215, .id2 = 7342087, .id3 = 0, .r = 0, .g = 255, .b = 0 }, // action keys are green when fn is pressed (#s 14,31,32,33,34,35,36,37,48,49,50,51,52,53,54,64,65,66,67,76,85,86,87)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 1, .id1 = 1073741824, .id2 = 131072, .id3 = 0, .r = 255, .g = 0, .b = 0 }, // fn, esc, and enter are red when pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL, .layer = 1, .id0 = 1073733630, .id1 = 1069580256, .id2 = 915448, .id3 = 0 }, // other keys off when fn is pressed
  {.end = 1 }
};

led_instruction_t led_instructions_default[] = {
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 4294967295, .id1 = 4294967295, .id2 = 4294967295, .id3 = 8388607 }, // all keys, use regular patterns but also with glitter effect togglable
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .layer = 1, .id0 = 3221233664, .id1 = 2151645215, .id2 = 7342087, .id3 = 0 }, // action keys are pattern when fn is pressed (#s 14,31,32,33,34,35,36,37,48,49,50,51,52,53,54,64,65,66,67,76,85,86,87)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 0, .id2 = 4286578688, .id3 = 8388607 }, // ring lights are pattern + glitter when fn is pressed (#s 88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 1, .id1 = 1073741824, .id2 = 131072, .id3 = 0, .r = 255, .g = 255, .b = 255 }, // fn, esc, and enter are white when pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL, .layer = 1, .id0 = 1073733630, .id1 = 1069580256, .id2 = 915448, .id3 = 0 }, // other keys off when fn is pressed
  {.end = 1 }
};

led_instruction_t led_instructions_c2077[] = {
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 536813086, .id1 = 1073250300, .id2 = 4286612479, .id3 = 8388607, .pattern_id = 18 }, // c2077alt for most keys
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 0, .id0 = 3758154209, .id1 = 3221716995, .id2 = 8354816, .id3 = 0, .r = 251,	.g = 245, .b = 23 }, // yellow color for accent keys (#s 1,6,7,8,9,14,15,16,30,31,32,33,34,48,49,50,51,63,64,75,76,77,78,79,81,82,83,84,85,86,87)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 3221233664, .id1 = 2151645215, .id2 = 7342087, .id3 = 0, .r = 251,	.g = 245, .b = 23 }, // action keys are yellow when fn is pressed (#s 14,31,32,33,34,35,36,37,48,49,50,51,52,53,54,64,65,66,67,76,85,86,87)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 0, .id2 = 4286578688, .id3 = 8388607, .pattern_id = 18 }, // ring lights still can glitter when fn is pressed (#s 88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN, .layer = 1, .id0 = 1, .id1 = 1073741824, .id2 = 131072, .id3 = 0, .pattern_id = 18 }, // fn, esc, and enter are purple when pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL, .layer = 1, .id0 = 1073733630, .id1 = 1069580256, .id2 = 915448, .id3 = 0 }, // other keys off when fn is pressed
  {.end = 1 }
};

led_instruction_t led_instructions_white_teal[] = {
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 1, .id1 = 1073741824, .id2 = 4286578688, .id3 = 8388607, .r = 32, .g = 255, .b = 80 }, // teal color for ring, esc, enter
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 3758161918, .id1 = 2147975171, .id2 = 8354816, .id3 = 0, .r = 116, .g = 228, .b = 140 }, // dull teal color for accent keys (#s 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,30,31,32,33,34,48,49,50,51,64,75,76,77,78,79,81,82,83,84,85,86,87)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 536805376, .id1 = 1073250300, .id2 = 33791, .id3 = 0, .id3 = 0, .r = 200, .g = 200, .b = 200 }, // white color for other keys
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 3221233664, .id1 = 2151645215, .id2 = 7342087, .id3 = 0, .r = 116, .g = 228, .b = 140  }, // action keys are dull teal when fn is pressed (#s 14,31,32,33,34,35,36,37,48,49,50,51,52,53,54,64,65,66,67,76,85,86,87)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 0, .id2 = 4286578688, .id3 = 8388607, .r = 32, .g = 255, .b = 80 }, // ring lights still can glitter when fn is pressed (#s 88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 1, .id1 = 1073741824, .id2 = 131072, .id3 = 0, .r = 32, .g = 255, .b = 80 }, // fn, esc, and enter are teal when pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL, .layer = 1, .id0 = 1073733630, .id1 = 1069580256, .id2 = 915448, .id3 = 0 }, // other keys off when fn is pressed
  {.end = 1 }
};

led_instruction_t led_game_instructions_green_teal_and_purple[] = {
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 2049,         .id1 = 1077411848,  .id2 = 0,           .id3 = 0, .r = 192, .g = 32, .b = 255 }, // color for wasd, esc, enter, and f11 (#s 1, 12, 36, 52, 53, 54, 63)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 0,            .id1 = 0,           .id2 = 4286578688,  .id3 = 8388607, .r = 192, .g = 32, .b = 255 }, // color for ring
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 4294965246,   .id1 = 3217555447,  .id2 = 8388607,     .id3 = 0, .r = 32, .g = 255, .b = 80 }, // everything else
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0,            .id1 = 1073741824,  .id2 = 131072,      .id3 = 0, .r = 192, .g = 32, .b = 255 }, // purple color for fn (82) and enter (63) when fn is pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0,            .id1 = 0,           .id2 = 4286578688,  .id3 = 8388607, .r = 192, .g = 32, .b = 255 }, // ring can stay lit when fn is pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL,     .layer = 1, .id0 = 4294967295,   .id1 = 3221225471,  .id2 = 8257535,     .id3 = 0 }, // all other LEDs off when fn is pressed
  {.end = 1 }
};

led_instruction_t led_game_instructions_blue_teal_and_pink[] = {
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 2049,         .id1 = 1077411848,  .id2 = 0,           .id3 = 0, .r = 255, .g = 32, .b = 207 }, // color for wasd, esc, enter, and f11 (#s 1, 12, 36, 52, 53, 54, 63)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 0,            .id1 = 0,           .id2 = 4286578688,  .id3 = 8388607, .r = 255, .g = 32, .b = 207 }, // color for ring
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 4294965246,   .id1 = 3217555447,  .id2 = 8388607,     .id3 = 0, .r = 47, .g = 198, .b = 178 }, // everything else
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0,            .id1 = 1073741824,  .id2 = 131072,      .id3 = 0, .r = 255, .g = 32, .b = 207 }, // pink color for fn (82) and enter (63) when fn is pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0,            .id1 = 0,           .id2 = 4286578688,  .id3 = 8388607, .r = 255, .g = 32, .b = 207 }, // ring can stay lit when fn is pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL,     .layer = 1, .id0 = 4294967295,   .id1 = 3221225471,  .id2 = 8257535,     .id3 = 0 }, // all other LEDs off when fn is pressed
  {.end = 1 }
};

led_instruction_t led_game_instructions_white_mains[] = {
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN,  .layer = 0, .id0 = 2049,         .id1 = 1077411848,  .id2 = 0,           .id3 = 0 }, // color for wasd, esc, enter, and f11 (#s 1, 12, 36, 52, 53, 54, 63)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN,  .layer = 0, .id0 = 0,            .id1 = 0,           .id2 = 4286578688,  .id3 = 8388607 }, // color for ring
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 4294965246,   .id1 = 3217555447,  .id2 = 8388607,     .id3 = 0, .r = 255, .g = 255, .b = 255 }, // everything else
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN,  .layer = 1, .id0 = 0,            .id1 = 1073741824,  .id2 = 131072,      .id3 = 0 }, // rotating color for fn (82) and enter (63) when fn is pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN,  .layer = 1, .id0 = 0,            .id1 = 0,           .id2 = 4286578688,  .id3 = 8388607 }, // ring can stay lit when fn is pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL,     .layer = 1, .id0 = 4294967295,   .id1 = 3221225471,  .id2 = 8257535,     .id3 = 0 }, // all other LEDs off when fn is pressed
  {.end = 1 }
};

led_instruction_t led_game_instructions_white_and_red[] = {
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 2049,         .id1 = 1077411848,  .id2 = 0,           .id3 = 0, .r = 255, .g = 0, .b = 0 }, // color for wasd, esc, enter, and f11 (#s 1, 12, 36, 52, 53, 54, 63)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 0,            .id1 = 0,           .id2 = 4286578688,  .id3 = 8388607, .r = 255, .g = 0, .b = 0 }, // color for ring
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 4294965246,   .id1 = 3217555447,  .id2 = 8388607,     .id3 = 0, .r = 255, .g = 255, .b = 255 }, // everything else
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0,            .id1 = 1073741824,  .id2 = 131072,      .id3 = 0, .r = 255, .g = 0, .b = 0 }, // red color for fn (82) and enter (63) when fn is pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0,            .id1 = 0,           .id2 = 4286578688,  .id3 = 8388607, .r = 255, .g = 0, .b = 0 }, // ring can stay lit when fn is pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL,     .layer = 1, .id0 = 4294967295,   .id1 = 3221225471,  .id2 = 8257535,     .id3 = 0 }, // all other LEDs off when fn is pressed
  {.end = 1 }
};

led_instruction_t led_game_instructions_xmas[] = {
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 2049,         .id1 = 1077411848,  .id2 = 0,           .id3 = 0, .r = 255, .g = 0, .b = 0 }, // color for wasd, esc, enter, and f11 (#s 1, 12, 36, 52, 53, 54, 63)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 0,            .id1 = 0,           .id2 = 4286578688,  .id3 = 8388607, .r = 255, .g = 0, .b = 0 }, // color for ring
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 4294965246,   .id1 = 3217555447,  .id2 = 8388607,     .id3 = 0, .r = 0, .g = 255, .b = 0 }, // everything else
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0,            .id1 = 1073741824,  .id2 = 131072,      .id3 = 0, .r = 255, .g = 0, .b = 0 }, // red color for fn (82) and enter (63) when fn is pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0,            .id1 = 0,           .id2 = 4286578688,  .id3 = 8388607, .r = 255, .g = 0, .b = 0 }, // ring can stay lit when fn is pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL,     .layer = 1, .id0 = 4294967295,   .id1 = 3221225471,  .id2 = 8257535,     .id3 = 0 }, // all other LEDs off when fn is pressed
  {.end = 1 }
};

led_instruction_t led_game_instructions_white_teal[] = {
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 2049,         .id1 = 1077411848,  .id2 = 0,           .id3 = 0, .r = 32, .g = 255, .b = 80 }, // color for wasd, esc, enter, and f11 (#s 1, 12, 36, 52, 53, 54, 63)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 0,            .id1 = 0,           .id2 = 4286578688,  .id3 = 8388607, .r = 32, .g = 255, .b = 80 }, // color for ring
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 4294965246,   .id1 = 3217555447,  .id2 = 8388607,     .id3 = 0, .r = 116, .g = 228, .b = 140 }, // everything else
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0,            .id1 = 1073741824,  .id2 = 131072,      .id3 = 0, .r = 32, .g = 255, .b = 80 }, // teal color for fn (82) and enter (63) when fn is pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0,            .id1 = 0,           .id2 = 4286578688,  .id3 = 8388607, .r = 32, .g = 255, .b = 80 }, // ring can stay lit when fn is pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL,     .layer = 1, .id0 = 4294967295,   .id1 = 3221225471,  .id2 = 8257535,     .id3 = 0 }, // all other LEDs off when fn is pressed
  {.end = 1 }
};

led_instruction_t led_game_instructions_c2077[] = {
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 2049,         .id1 = 1077411848,  .id2 = 0,           .id3 = 0, .r = 251,	.g = 245, .b = 23 }, // yellow color for wasd, esc, enter, and f11 (#s 1, 12, 36, 52, 53, 54, 63)
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 0, .id0 = 0,            .id1 = 0,           .id2 = 4286578688,  .id3 = 8388607, .r = 251,	.g = 245, .b = 23 }, // yellow color for ring
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,  .layer = 0, .id0 = 4294965246,   .id1 = 3217555447,  .id2 = 8388607,     .id3 = 0, .pattern_id = 18 }, // everything else
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0,            .id1 = 1073741824,  .id2 = 131072,      .id3 = 0, .r = 251,	.g = 245, .b = 23 }, // yellow color for fn (82) and enter (63) when fn is pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,  .layer = 1, .id0 = 0,            .id1 = 0,           .id2 = 4286578688,  .id3 = 8388607, .r = 251,	.g = 245, .b = 23 }, // ring can stay lit when fn is pressed
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL,     .layer = 1, .id0 = 4294967295,   .id1 = 3221225471,  .id2 = 8257535,     .id3 = 0 }, // all other LEDs off when fn is pressed
  {.end = 1 }
};

void *led_instruction_list[] = {
    led_instructions_green_teal_and_purple,
    led_instructions_blue_teal_and_pink,
    led_instructions_white_teal,
    led_instructions_c2077,
    led_instructions_white_mains,
    led_instructions_default
};

void *led_game_instruction_list[] = {
    led_game_instructions_green_teal_and_purple,
    led_game_instructions_blue_teal_and_pink,
    led_game_instructions_white_teal,
    led_game_instructions_c2077,
    led_game_instructions_white_mains,
    led_game_instructions_white_and_red
};

const uint8_t led_instruction_count = sizeof(led_instruction_list) / sizeof(led_instruction_list[0]);

uint8_t led_default_rotate_pattern[6] = {  // each instruction group in led_instruction_list can have a default rotate pattern to set on change
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
