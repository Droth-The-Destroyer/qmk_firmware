// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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
     * │F4 │   │ Z │ X │ ` │Tab│Spc│ M │
     * ├───┤   └───┴───┴───┤   │   ├───┤
     * │F5 │               │   │   │ B │
     * └───┘               └───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_ESC,     KC_PAST,    KC_PSLS,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
        KC_F1,      KC_1,       KC_Q,       KC_W,       KC_E,       KC_2,       KC_3,       KC_K,
        KC_F2,      KC_4,       KC_A,       KC_S,       KC_D,       KC_5,       KC_6,       KC_C,
        KC_F3,      KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_L,
        KC_F4,      KC_NO,      KC_Z,       KC_X,       KC_GRV,     KC_TAB,     KC_SPC,     KC_M,
        KC_F5,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_B
    )
};

// Runs at the end of each scan loop 
void housekeeping_task_user(void) {
    
}

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) }
};

// https://github.com/qmk/qmk_firmware/pull/19442/files#diff-766bd0ccc0ab634d6a710652ccca386759a701968a9a7ede3c859c3ea8effb2cR40
// Workaround: the keyboard has extra buttons, directly connected to the cpu. As we can't use both them and a matrix,
// let's configure them as dip switches that send keycodes
// This must match the order of the pins in DIP_SWITCH_PINS
// The number of switches is currently hardcoded, can't find a suitable macro/define to get that value from...
const uint16_t PROGMEM dip_switch_map[][2] = {
    [0] = { QK_BOOT, KC_SPC },
};

bool dip_switch_update_user(uint8_t index, bool active) {
    uint8_t active_layer = biton32(layer_state);
    if (active) {
        if (index == 0) {
            reset_keyboard();
        }
        register_code(dip_switch_map[active_layer][index]);
    } else {
        unregister_code(dip_switch_map[active_layer][index]);
    }
    return true;
}