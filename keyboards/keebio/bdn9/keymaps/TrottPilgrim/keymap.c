#include QMK_KEYBOARD_H

// enum layer_names {
//   _ZERO,
//   _ONE,
//   _TWO,
//   _THREE
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
    KC_MUTE, KC_HOME, KC_MUTE,
    MO(1),   KC_UP,   RGB_MOD,
    KC_LEFT, KC_DOWN, KC_RGHT
),

[1] = LAYOUT(
   _______, _______, _______,
   _______, _______, _______,
   _______, _______, _______
),

[2] = LAYOUT(
    _______, _______, _______,
    _______, _______, _______,
    _______, _______, _______
),

[3] = LAYOUT(
    _______, _______, _______,
    _______, _______, _______,
    _______, _______, _______
)

};


uint8_t selected_layer = 0;
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise && selected_layer < 3) {
            selected_layer++;
        } else if (!clockwise && selected_layer > 0) {
            selected_layer--;
        }
        tap_code(DF(selected_layer))
    }
}
