/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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
#include QMK_KEYBOARD_H

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      // Anything you can do in a macro.
      SEND_STRING("QMK is awesome.");
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    }
    SEQ_TWO_KEYS(KC_Y, KC_T) {
      SEND_STRING_DELAY("https://www.youtube.com\n", 5);
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING_DELAY("https://start.duckduckgo.com\n", 5);
    }
    SEQ_THREE_KEYS(KC_M, KC_K, KC_T) {
      SEND_STRING_DELAY("https://monkeytype.com\n", 5);
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
    SEQ_TWO_KEYS(KC_W, KC_N) {
        register_code(KC_LGUI);
        register_code(KC_LCTL);
        register_code(KC_RIGHT);
        unregister_code(KC_RIGHT);
        unregister_code(KC_LCTL);
        unregister_code(KC_LGUI);
    }
    SEQ_TWO_KEYS(KC_W, KC_P) {
        register_code(KC_LGUI);
        register_code(KC_LCTL);
        register_code(KC_LEFT);
        unregister_code(KC_LEFT);
        unregister_code(KC_LCTL);
        unregister_code(KC_LGUI);
    }
  }
} 


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _FN1,
    _MIDI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_60_ansi(
    KC_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                 KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,
    KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,
    KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,                 KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,
    OSM(MOD_LSFT), KC_Z, KC_X,    KC_C,    KC_V,    KC_B,    KC_N,                 KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                    OSM(MOD_RSFT),
    KC_LCTL,    KC_LGUI, KC_LALT,                            KC_SPC,                                          KC_RALT, KC_RGUI, MO(_FN1), KC_RCTL
  ),

  [_FN1] = LAYOUT_60_ansi(
    KC_GRV,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    TO(_MIDI), KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______, _______, _______, _______,                   _______,
    _______,   _______, _______,                            _______,                            _______, _______, _______, RESET
  ),

  [_MIDI] = LAYOUT_60_ansi(
<<<<<<< HEAD
    TO(_BASE),  MI_C_1,  MI_Ds_1, MI_Fs_1, MI_A_1,  MI_C_2,  MI_Ds_2, MI_Fs_2, MI_A_2,  MI_C_3,  MI_Ds_3, MI_Fs_3, MI_A_3, MI_C_4,
    KC_NO,      MI_Cs_1, MI_E_1,  MI_G_1,  MI_As_1, MI_Cs_2, MI_E_2,  MI_G_2,  MI_As_2, MI_Cs_3, MI_E_3,  MI_G_3,  MI_As_3, MI_Cs_4,
    KC_NO,      MI_D_1,  MI_F_1,  MI_Gs_1, MI_B_1,  MI_D_2,  MI_F_2,  MI_Gs_2, MI_B_2,  MI_D_3,  MI_F_3,  MI_Gs_3, MI_B_3,
    KC_NO,      MI_Ds_1, MI_Fs_1, MI_A_1,  MI_C_2,  MI_Ds_2, MI_Fs_2, MI_A_2,  MI_C_3,  MI_Ds_3, MI_Fs_3, MI_A_3,
    KC_NO,      MI_OCTD, MI_OCTU,                            KC_SPC,                                          MI_OCTD, MI_OCTU, KC_NO, KC_NO
=======
    TO(_BASE),     MI_C_1,  MI_Ds_1, MI_Fs_1, MI_A_1,  MI_C_2,  MI_Ds_2, MI_Fs_2, MI_A_2,  MI_C_3,  MI_Ds_3, MI_Fs_3, MI_A_3, MI_C_4,
    KC_NO,        MI_Cs_1, MI_E_1,  MI_G_1,  MI_As_1, MI_Cs_2, MI_E_2,  MI_G_2,  MI_As_2, MI_Cs_3, MI_E_3,  MI_G_3,  MI_As_3, MI_Cs_4,
    KC_NO,       MI_D_1,  MI_F_1,  MI_Gs_1, MI_B_1,  MI_D_2,  MI_F_2,  MI_Gs_2, MI_B_2,  MI_D_3,  MI_F_3,  MI_Gs_3, MI_B_3,
    KC_NO, MI_Ds_1, MI_Fs_1, MI_A_1,  MI_C_2,  MI_Ds_2, MI_Fs_2, MI_A_2,  MI_C_3,  MI_Ds_3, MI_Fs_3, MI_A_3,
    KC_NO, MI_OCTD, MI_OCTU,                            KC_SPC,                                          MI_OCTD, MI_OCTU, KC_NO, KC_NO
>>>>>>> 391a72e9eed623205905e7511b60223244daef8c
  )
};
