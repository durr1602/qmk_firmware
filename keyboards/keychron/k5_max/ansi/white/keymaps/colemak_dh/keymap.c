/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"
#include "keymap_canadian_french.h"

// Key overrides
const key_override_t scln_cln_swap = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);
const key_override_t s_frquot_override = ko_make_basic(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO);
const key_override_t s_frcomm_override = ko_make_basic(MOD_MASK_SHIFT, FR_COMM, FR_LABK);
const key_override_t s_frdot_override = ko_make_basic(MOD_MASK_SHIFT, FR_DOT, FR_RABK);
const key_override_t s_frlbrc_override = ko_make_basic(MOD_MASK_SHIFT, FR_LBRC, FR_LCBR);
const key_override_t s_frrbrc_override = ko_make_basic(MOD_MASK_SHIFT, FR_RBRC, FR_RCBR);
const key_override_t s_frslash_override = ko_make_basic(MOD_MASK_SHIFT, FR_SLSH, FR_QUES);
const key_override_t s_frbslash_override = ko_make_basic(MOD_MASK_SHIFT, FR_BSLS, FR_PIPE);

const key_override_t *key_overrides[] = {
	&scln_cln_swap,
    &s_frquot_override,
    &s_frcomm_override,
    &s_frdot_override,
    &s_frlbrc_override,
    &s_frrbrc_override,
    &s_frslash_override,
    &s_frbslash_override
};

// Define layers
enum layers {
    _COLEMAK,
    _COLEMAK_FN,
    _QWERTY,
    _QWERTY_FN,
    _COLEMAK_FR,
};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Important - Keychron features
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0: Colemak-DH base (ANSI 108) for writing in English and coding (no accents!)
 */
    [_COLEMAK] = LAYOUT_108_ansi(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_CTANA, BL_STEP,  _______,  _______,  _______,  _______,
        FR_HASH,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  FR_LBRC,  FR_RBRC,  FR_BSLS,  KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     FR_QUOT,            KC_ENT,                                 KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_X,     KC_C,     KC_D,     KC_V,     KC_Z,     KC_K,     KC_H,     KC_COMM,  KC_DOT,   FR_SLSH,            KC_RSFT,            KC_UP,    KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 TT(_COLEMAK_FR),KC_RWIN,MO(_COLEMAK_FN),KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT,KC_P0,            KC_PDOT,  KC_PENT
    ),

/* LAYER 1: Colemak FN - F-keys, media
 */
    [_COLEMAK_FN] = LAYOUT_108_ansi(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,   BL_DOWN,  BL_UP,   KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU, _______,  _______,  BL_TOGG, _______, _______, _______, _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  _______, _______, _______, _______, _______,
        BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  _______, _______, _______, _______,
        _______,  _______,  BL_DOWN,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,                              _______, _______, _______, _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,           _______,           _______, _______, _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______, _______,  _______,  _______, _______,          _______, _______
    ),

/* LAYER 2: QWERTY (default Windows - we leave the mapping entirely to Windows)
 */
    [_QWERTY] = LAYOUT_108_ansi(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_PSCR,  KC_CTANA, BL_STEP, _______, _______, _______, _______,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_INS,   KC_HOME,  KC_PGUP, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_DEL,   KC_END,   KC_PGDN, KC_P7,   KC_P8,   KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,                               KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,           KC_UP,             KC_P1,   KC_P2,   KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN, MO(_QWERTY_FN),KC_RCTL, KC_LEFT,  KC_DOWN,  KC_RGHT, KC_P0,         KC_PDOT, KC_PENT
    ),

/* LAYER 3: QWERTY FN Layer
 */
    [_QWERTY_FN] = LAYOUT_108_ansi(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,   BL_DOWN,  BL_UP,   KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU, _______,  _______,  BL_TOGG, _______, _______, _______, _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  _______, _______, _______, _______, _______,
        BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  _______, _______, _______, _______,
        _______,  _______,  BL_DOWN,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,                              _______, _______, _______, _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,           _______,           _______, _______, _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______, _______,  _______,  _______, _______,          _______, _______
    ),

/* LAYER 4: COLEMAK_FR Layer (activated upon double tap on RALT) for writing in French
 * 
 * direct é
 * ` (grave)
 * ^ (circumflex)
 * ¨ (diaeresis)
 * ¸ (cedilla)
 */
    [_COLEMAK_FR] = LAYOUT_108_ansi(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_PSCR,  KC_CTANA, BL_STEP,  _______,  _______,  _______,  _______,
        FR_HASH,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  FR_DCIR,  FR_CEDL,  FR_DGRV, KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     FR_QUOT,            KC_ENT,                                KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_X,     KC_C,     KC_D,     KC_V,     KC_Z,     KC_K,     KC_H,     KC_COMM,  KC_DOT,   FR_EACU,            KC_RSFT,           KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 _______,  KC_RWIN,MO(_COLEMAK_FN),KC_RCTL,KC_LEFT,KC_DOWN, KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT
    ),

};
