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


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _FN1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_60_ansi(
    MI_OCTD, MI_A1,   MI_C2,   MI_Eb2,  MI_Gb2,  MI_A2,   MI_C3,   MI_Eb3,  MI_Gb3,  MI_A3,   MI_C4,   MI_Gb4,  MI_A4,    MI_OCTU,
    KC_TAB,  MI_Bb1,  MI_Db2,  MI_E2,   MI_G2,   MI_Bb2,  MI_Db3,  MI_E3,   MI_G3,   MI_Bb3,  MI_Db4,  MI_G4,   MI_Bb4,   KC_BSLS,
    KC_CAPS, MI_B1,   MI_D2,   MI_F2,   MI_Ab2,  MI_B2,   MI_D3,   MI_F3,   MI_Ab3,  MI_B3,   MI_D4,   MI_Ab4,  MI_B4,
    KC_LSFT, MI_C2,   MI_Eb2,  MI_Gb2,  MI_A2,   MI_C3,   MI_Eb3,  MI_Gb3,  MI_A3,   MI_C4,   MI_Eb4,  MI_A4,
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                                          KC_RALT, KC_RGUI, MO(_FN1), KC_RCTL
  ),

  [_FN1] = LAYOUT_60_ansi(
    QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    RGB_TOG, RGB_MOD, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    BL_BRTG, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    BL_UP,   BL_DOWN, BL_TOGG, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
    KC_GRV,  _______, _______,                            _______,                            _______, _______, _______, QK_BOOT
  )
};
