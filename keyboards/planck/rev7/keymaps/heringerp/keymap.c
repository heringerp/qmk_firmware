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

enum planck_keycodes { COLEMAK = SAFE_RANGE, BACKLIT, };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LCTL_T(KC_SPC), LOWER, RAISE, OSM(MOD_LSFT), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_BRIU, KC_7,    KC_8,    KC_9,    KC_TAB,  KC_INS,  KC_PGDN, KC_PGUP, KC_DEL,  KC_BSPC, _______,
    _______, KC_BRID, KC_4,    KC_5,    KC_6,    KC_ESC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_ENT, _______,
    _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_LSFT, KC_HOME, KC_PSCR, LSFT(KC_PSCR), KC_END, _______,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_VOLU, KC_AMPR, KC_ASTR, KC_PLUS, KC_LPRN, KC_RPRN, KC_QUOT, KC_DQUO, KC_RALT, KC_NO, _______,
    _______, KC_MUTE, KC_DLR,  KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_GRV,  KC_NO, _______,
    _______, KC_VOLD, KC_EXLM, KC_AT,   KC_HASH, KC_LCBR, KC_RCBR, KC_UNDS, KC_PIPE, KC_TILD, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), _______, _______, LGUI(KC_L), LGUI(KC_ENT), SGUI(KC_Q), _______, _______,
    _______, EE_CLR,  LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), _______, _______, KC_LSFT,    LGUI(KC_P), SGUI(KC_P), _______, _______,
    _______, AU_PREV, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), _______, _______,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};
/* clang-format on */

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            return false;
            break;
    }
    return true;
}

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    cancel_deferred_exec(tokens[index]);
    if (clockwise) {
        melody[index][1][0] = melody[index][1][0] * ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] / ET12_PERFECT_FIFTH;
        audio_play_melody(&melody[index], 2, false);
    } else {
        melody[index][1][0] = melody[index][1][0] / ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] * ET12_TRITONE;
        audio_play_melody(&melody[index], 2, false);
    }
    tokens[index] = defer_exec(1000, reset_note, &melody[index][1][0]);
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
    }
    return true;
}
