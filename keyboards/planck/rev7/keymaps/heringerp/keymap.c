/* Copyright 2015-2023 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum planck_layers { _COLEMAK, _LOWER, _RAISE, _ADJUST };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LGUI, KC_A, KC_LALT, LCTL_T(KC_SPC), LOWER, RAISE, OSM(MOD_LSFT), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_LOWER] = LAYOUT_planck_grid(
    _______, KC_BRIU, KC_7,    KC_8,    KC_9,    KC_TAB,  KC_INS,  KC_PGDN, KC_PGUP, KC_DEL,  KC_BSPC, _______,
    _______, KC_BRID, KC_4,    KC_5,    KC_6,    KC_ESC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_ENT, _______,
    _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_LSFT, KC_HOME, KC_PSCR, LSFT(KC_PSCR), KC_END, _______,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
    _______, KC_VOLU, KC_AMPR, KC_ASTR, KC_PLUS, KC_LPRN, KC_RPRN, KC_QUOT, KC_DQUO, KC_RALT, KC_NO, _______,
    _______, KC_MUTE, KC_DLR,  KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_GRV,  KC_NO, _______,
    _______, KC_VOLD, KC_EXLM, KC_AT,   KC_HASH, KC_LCBR, KC_RCBR, KC_UNDS, KC_PIPE, KC_TILD, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), _______, _______, LGUI(KC_L), LGUI(KC_ENT), SGUI(KC_Q), _______, _______,
    _______, EE_CLR,  LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), _______, _______, KC_LSFT,    LGUI(KC_P), SGUI(KC_P), _______, _______,
    _______, _______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), _______, _______,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};
/* clang-format on */

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_COLEMAK] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_LOWER] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
    [_RAISE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_ADJUST] = { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif
