/* Copyright 2020 shela
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
#include "keymap_jis2us.h"
#include "action_pseudo.h"

// clang-format off
enum keyboard_layers {
    _QWERTY = 0,
    _PSEUDO,
    _MOUSE,
    _HHKB,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    PSEUDO,
    MOUSE,
    PSE_FN,
};
// clang-format on

/* Additional custom keycodes */
#define MO_HHKB MO(_HHKB)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty Layer
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
     * |-----------------------------------------------------------------------------------------|
     * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  | Delete |
     * |-----------------------------------------------------------------------------------------|
     * | LControl |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |   Enter    |
     * |-----------------------------------------------------------------------------------------|
     * |   LShift    |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RShift  |HHKB |
     * `-----------------------------------------------------------------------------------------'
     *          | LALT | LGUI |               Space               | RGUI | RALT |      | UP |
     *          `---------------------------------------------------------------' ,--------------.
     *                                                                            |LEFT|DOWN|RGHT|
     *                                                                            `--------------'
     */
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_DEL,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO_HHKB,
        KC_LALT, KC_LGUI, KC_SPC,  KC_RGUI, KC_RALT,
                                                                                                                    KC_UP,
                                                                                                           KC_LEFT, KC_DOWN, KC_RGHT
        ),
    /* Pseudo Layer
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|
     * |-----------------------------------------------------------------------------------------|
     * |  Tab   |PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn| Delete |
     * |-----------------------------------------------------------------------------------------|
     * | Control  |PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|   Enter    |
     * |-----------------------------------------------------------------------------------------|
     * |    Shift    |PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|PseFn|  Shift  |HHKB |
     * `-----------------------------------------------------------------------------------------'
     *          | LALT | LGUI |               Space               | RGUI | RALT |      | UP |
     *          `---------------------------------------------------------------' ,--------------.
     *                                                                            |LEFT|DOWN|RGHT|
     *                                                                            `--------------'
     */
    [_PSEUDO] = LAYOUT(
        KC_ESC,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,
        KC_TAB,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  KC_DEL,
        KC_LCTL, PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  KC_ENT,
        KC_LSFT, PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  PSE_FN,  KC_RSFT, MO_HHKB,
        KC_LALT, KC_LGUI, KC_SPC,  KC_RGUI, KC_RALT,
                                                                                                                    KC_UP,
                                                                                                           KC_LEFT, KC_DOWN, KC_RGHT
        ),
    /* Mouse layer
     * ,-----------------------------------------------------------------------------------------.
     * | Esc | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |     |     |
     * |-----------------------------------------------------------------------------------------|
     * |  Tab   |     |     |     |     |     | WhL | WhD | WhU | WhR |     |     |     | Delete |
     * |-----------------------------------------------------------------------------------------|
     * | LControl |     |     |     |     |     | MsL | MsD | MsU | MsR |     |     |   Enter    |
     * |-----------------------------------------------------------------------------------------|
     * |   LShift    |     |     |     |     |     | Mb1 | Mb2 | Mb3 |     |     | RShift  |HHKB |
     * `-----------------------------------------------------------------------------------------'
     *          | LALT | LGUI |               Space               | RGUI | RALT |      | UP |
     *          `---------------------------------------------------------------' ,--------------.
     *                                                                            |LEFT|DOWN|RGHT|
     *                                                                            `--------------'
     */
    [_MOUSE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX,
        KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX, KC_ENT,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX, KC_RSFT, MO_HHKB,
        KC_LALT, KC_LGUI, KC_SPC,  KC_RGUI, KC_RALT,
                                                                                                                    KC_MS_U,
                                                                                                           KC_MS_L, KC_MS_D, KC_MS_R
        ),

    /* HHKB Layer
     * ,-----------------------------------------------------------------------------------------.
     * |Power| F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | Ins | Del |
     * |-----------------------------------------------------------------------------------------|
     * |  Caps  |Qwert|Psedo|Mouse|     |     |     |     |PScr |SLck |Paus | Up  |     |   BS   |
     * |-----------------------------------------------------------------------------------------|
     * |          |VolD |VolU |Mute |Ejct |     |  *  |  /  |Home |PgUp |Left |Rght |   Enter    |
     * |-----------------------------------------------------------------------------------------|
     * |             |     |     |     |     |     |  +  |  -  | End |PgDn |Down |         |     |
     * `-----------------------------------------------------------------------------------------'
     *          |      |      |               Space               |      |      |      | UP |
     *          `---------------------------------------------------------------' ,--------------.
     *                                                                            |LEFT|DOWN|RGHT|
     *                                                                            `--------------'
     */
    [_HHKB] = LAYOUT(
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
        KC_CAPS, QWERTY,  PSEUDO,  MOUSE,   _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   XXXXXXX, KC_BSPC,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT,_______,
        _______, _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, _______, _______,
	_______, _______, KC_SPC,  _______, _______,
                                                                                                                    KC_PGUP,
                                                                                                           KC_HOME, KC_PGDN, KC_END
        ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case PSEUDO:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_PSEUDO);
            }
            return false;
        case MOUSE:
            if (record->event.pressed) {
                default_layer_set(1U << _MOUSE);
            }
            return false;
        case PSE_FN:
            action_pseudo_process(record, _QWERTY, keymap_jis2us);
            return false;
    }
    return true;
}
