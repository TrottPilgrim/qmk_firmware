#include QMK_KEYBOARD_H

enum custom_keycodes {
  SHIFT_DT_RIGHT,
  SHIFT_DT_LEFT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ortho_4x4(
    KC_7, KC_8, KC_9, SHIFT_DT_LEFT, 
    KC_4, KC_5, KC_6, SHIFT_DT_RIGHT, 
    KC_1, KC_2, KC_3, RGB_HUI, 
    KC_0, KC_ENT, KC_SFTENT, RGB_HUD)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHIFT_DT_LEFT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL(SS_LGUI(SS_TAP(X_LEFT))));
                // rgblight_setrgb(RGB_PURPLE);
            }
            return false;
            break;
        case SHIFT_DT_RIGHT:
            if (record-> event.pressed){
                SEND_STRING(SS_LCTRL(SS_LGUI(SS_TAP(X_RIGHT))));
                // rgblight_setrgb(RGB_PINK);
            }
            return false;
            break;
    }
    return true;
}

