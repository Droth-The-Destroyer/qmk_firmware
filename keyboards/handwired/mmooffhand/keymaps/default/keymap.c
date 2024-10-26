// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdint.h>
#include "keycodes.h"
#include QMK_KEYBOARD_H
#include <display/display.c>

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  user_config.raw = 0;
  user_config.set_rgb_mode = false;
  user_config.set_rgb_static_color = 1;
  user_config.set_rgb_zone1_color = 1;
  user_config.set_rgb_zone2_color = 1;
  user_config.set_rgb_zone3_color = 1;
  user_config.set_rgb_zone4_color = 1;
  user_config.set_rgb_zone5_color = 1;
  user_config.set_screen_color = 1;
  user_config.set_pet = 1;
  user_config.set_encoderscroll = 1;
  eeconfig_update_user(user_config.raw); // Write default value to EEPROM now
}

int settings_sel;

enum layer_names {
    DL,
    ML,
    SL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ * │ / │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │F1 │ 1 │ Q │ W │ E │ 2 │ 3 │ K │
     * ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │F2 │ 4 │ A │ S │ D │ 5 │ 6 │ C │
     * ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │F3 │ 7 │ 8 │ 9 │ 0 │ - │ = │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┤
     * │F4 │   │ Z │ X │ ` │ T │ S │ M │
     * ├───┤   └───┴───┴───┤ a │ p ├───┤
     * │F5 │               │ b │ c │ B │
     * └───┘               └───┴───┴───┘
     */
    [DL] = LAYOUT(
        EE_CLR,     KC_PAST,    KC_PSLS,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
        KC_F1,      KC_1,       KC_Q,       KC_W,       KC_E,       KC_2,       KC_3,       KC_K,
        KC_F2,      KC_4,       KC_A,       KC_S,       KC_D,       KC_5,       KC_6,       KC_C,
        KC_F3,      KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_L,
        KC_F4,      KC_NO,      KC_Z,       KC_X,       KC_GRV,     KC_TAB,     KC_SPC,     KC_M,
        KC_F5,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_B
    ),
    [ML] = LAYOUT(
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO
    ),
    [SL] = LAYOUT(
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO
    ),
};


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [DL] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [ML] = { ENCODER_CCW_CW(PB_2, PB_3) },
    [SL] = { ENCODER_CCW_CW(PB_2, PB_3) }
};

// https://github.com/qmk/qmk_firmware/pull/19442/files#diff-766bd0ccc0ab634d6a710652ccca386759a701968a9a7ede3c859c3ea8effb2cR40
// Workaround: the keyboard has extra buttons, directly connected to the cpu. As we can't use both them and a matrix,
// let's configure them as dip switches that send keycodes
// This must match the order of the pins in DIP_SWITCH_PINS
// The number of switches is currently hardcoded, can't find a suitable macro/define to get that value from...
const uint16_t PROGMEM dip_switch_map[][2] = {
    [DL] = { QK_BOOT, PB_1 },
    [ML] = { QK_BOOT, PB_1 },
    [SL] = { QK_BOOT, PB_1 },
};

/* LEDs
* ┌────┬────┬────┬────┬────┬────┬────┬────┐
* │ 00 │ 01 │ 02 │ 03 │ 04 │ 05 │ 06 │ 07 │
* ├────┼────┼────┼────┼────┼────┼────┼────┤
* │ 08 │ 09 │ 10 │ 11 │ 12 │ 13 │ 14 │ 15 │
* ├────┼────┼────┼────┼────┼────┼────┼────┤
* │ 16 │ 17 │ 18 │ 19 │ 20 │ 21 │ 22 │ 23 │
* ├────┼────┼────┼────┼────┼────┼────┼────┤
* │ 24 │ 25 │ 26 │ 27 │ 28 │ 29 │ 30 │ 31 │
* ├────┼────┼────┼────┼────┼────┼────┼────┤
* │ 32 │    │ 33 │ 34 │ 35 │    │    │ 38 │
* ├────┤    └────┴────┴────┤ 36 │ 37 ├────┤
* │ 39 │                   │    │    │ 40 │
* └────┘                   └────┴────┴────┘
*/

bool rgb_mode;

const rgblight_segment_t PROGMEM DL_rgb_zones[] = RGBLIGHT_LAYER_SEGMENTS(
            {0, 1, rgb_zone1},
            {1, 2, rgb_zone5},
            {3, 5, rgb_zone2},
            {8, 1, rgb_zone1},
            {9, 1, rgb_zone4},
            {10, 3, rgb_zone3},
            {13, 2, rgb_zone4},
            {15, 1, rgb_zone2},
            {16, 1, rgb_zone1},
            {17, 1, rgb_zone4},
            {18, 3, rgb_zone3},
            {21, 2, rgb_zone4},
            {23, 1, rgb_zone2},
            {24, 1, rgb_zone1},
            {25, 6, rgb_zone4},
            {31, 1, rgb_zone2},
            {32, 1, rgb_zone1},
            {33, 5, rgb_zone5},
            {38, 1, rgb_zone2},
            {39, 1, rgb_zone1},
            {40, 1, rgb_zone2}
        );

const rgblight_segment_t PROGMEM DL_rgb_static[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 41, rgb_static}
);

const rgblight_segment_t PROGMEM ML_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 41, HSV_WHITE}
);

const rgblight_segment_t PROGMEM SL_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 41, HSV_WHITE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    DL_rgb_static,
    DL_rgb_zones,
    ML_rgb,
    SL_rgb
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
    user_config.raw = eeconfig_read_user();
}

layer_state_t default_layer_state_set_kb(layer_state_t state) {
    switch (user_config.set_rgb_mode) {
        case false:
            rgblight_set_layer_state(0, layer_state_cmp(state, DL));
        break;
        case true:
            rgblight_set_layer_state(1, layer_state_cmp(state, DL));
        break;
    }
    return state;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, ML));
    //rgblight_set_layer_state(3, layer_state_cmp(state, SL));
    return state;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    uint8_t active_layer = biton32(layer_state);
    switch (index) {
        case 0:
            if (active) {
                reset_keyboard();
                register_code(dip_switch_map[active_layer][index]);
            }
            else {
            unregister_code(dip_switch_map[active_layer][index]);
            }
            break;
        case 1:
            if (active) {
                switch (active_layer) {
                    case DL:
                        layer_move(ML);
                        settings_sel = 1;
                        ui_settings(settings_sel);
                        break;
                    case ML:
                        switch (settings_sel) {
                            case 1:
                                layer_move(SL);
                                ui_settings(settings_sel);
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            case 4:
                                break;
                            case 5:
                                break;
                            case 6:
                                eeconfig_update_user(user_config.raw);
                                layer_move(DL);
                                ui_init();
                                break;
                        }
                        break;
                    case SL:
                        layer_move(ML);
                        ui_settings(settings_sel);
                        break;
                }
                default_layer_state_set_kb(layer_state);
                break;
            }
            else {
            unregister_code(dip_switch_map[active_layer][index]);
            }
            break;
    }
    return true;
}

// Runs during key press
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    set_single_persistent_default_layer(DL);
    uint8_t active_layer = biton32(layer_state);
    if (record->event.pressed) {
        switch (active_layer) {
            case DL:
                switch (keycode) {
                    case KC_VOLD:
                        animate();
                        return true;
                        break;
                    case KC_VOLU:
                        animate();
                        return true;
                        break;
                }
                break;
            case ML:
                switch (keycode) {
                    case PB_2:
                        if (settings_sel >= 1) {
                            settings_sel --;
                        }
                        if (settings_sel < 1) {
                            settings_sel = 6;
                        }
                        ui_settings(settings_sel);
                        break;
                    case PB_3:
                        if (settings_sel <= 6) {
                            settings_sel ++;
                        }
                        if (settings_sel > 6) {
                            settings_sel = 1;
                        }
                        ui_settings(settings_sel);
                        break;
                }
                break;
            case SL:
                switch (keycode) {
                    case PB_2:
                        if (settings_sel == 1) {
                            ui_settings_rgbmode_click(settings_sel);
                        }
                        break;
                    case PB_3:
                        if (settings_sel == 1) {
                            ui_settings_rgbmode_click(settings_sel);
                        }
                        break;
                }
                break;
        }
    }
    return true;
}

// Runs after each key press, check if activity occurred
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t active_layer = biton32(layer_state);
    switch (active_layer) {
        case SL:
            switch (keycode) {
                case PB_2:
                    break;
                case PB_3:
                    break;
            }
    }
}

// Runs at the end of each scan loop
void housekeeping_task_user(void) {

}

/*
EEPROM Settings I want to add
     1. RGB Mode (Static/Zones)
     2. Static RGB Color
     3. Zone 1 RGB Color
     4. Zone 2 RGB Color
     5. Zone 3 RGB Color
     6. Zone 4 RGB Color
     7. Zone 5 RGB Color
     8. Screen RGB Color
     9. Pet
    10. Encoder Scrolls
*/
