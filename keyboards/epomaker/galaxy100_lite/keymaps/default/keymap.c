/* Copyright 2025 Carlos Eduardo de Paula <carlosedp@gmail.com>
 * Copyright 2025 EPOMAKER <https://github.com/Epomaker>
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
#include "rdmctmzt_common.h"

// Layer 0: Windows base      Layer 2: Windows Fn (held with MO(2))
// Layer 1: macOS base        Layer 3: macOS Fn   (held with MO(3))

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_1800_ansi(
        QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_HOME, KC_END,  KC_PSCR, KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGDN, KC_P4,   KC_P5,   KC_P6,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                    KC_RALT, MO(2),   KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT
    ),
    [1] = LAYOUT_1800_ansi(
        QK_GESC, KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, KC_F5,   KC_F6,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,  KC_HOME, KC_END,  KC_PSCR, KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGDN, KC_P4,   KC_P5,   KC_P6,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                    KC_RGUI, MO(3),   KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT
    ),
    [2] = LAYOUT_1800_ansi(
        QK_GESC, KC_MYCM, KC_WHOM, KC_CALC, KC_MAIL, KC_MSEL, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,  KC_HOME, KC_END,  KC_PSCR, KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  EE_CLR,  KC_INS,  KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,  MD_BLE1, MD_BLE2, MD_BLE3, MD_24G,  MD_USB,  RM_TOGG, KC_U,    KC_I,    KC_O,    KC_P,    RM_SATD, RM_SATU, RM_HUEU, KC_PGUP, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_CAPS, TO(0),   TO(1),   KC_D,    KC_F,    KC_G,    DB_TOGG, KC_J,    KC_K,    KC_L,    RM_HUED, RM_HUEU, RM_NEXT, KC_PGDN, KC_P4,   KC_P5,   KC_P6,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    QK_BAT,  SIX_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, RM_VALU, KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        MW_CH,   QK_WLO,  KC_LALT,                   KC_SPC,                    KC_RALT, KC_NO,   RM_SPDD, RM_VALD, RM_SPDU, KC_P0,   KC_PDOT
    ),
    [3] = LAYOUT_1800_ansi(
        QK_GESC, KC_MYCM, KC_WHOM, KC_CALC, KC_MAIL, KC_MSEL, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,  KC_HOME, KC_END,  KC_PSCR, KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  EE_CLR,  KC_INS,  KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,  MD_BLE1, MD_BLE2, MD_BLE3, MD_24G,  MD_USB,  RM_TOGG, KC_U,    KC_I,    KC_O,    KC_P,    RM_SATD, RM_SATU, RM_HUEU, KC_PGUP, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_CAPS, TO(0),   TO(1),   KC_D,    KC_F,    KC_G,    DB_TOGG, KC_J,    KC_K,    KC_L,    RM_HUED, RM_HUEU, RM_NEXT, KC_PGDN, KC_P4,   KC_P5,   KC_P6,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    QK_BAT,  SIX_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, RM_VALU, KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        MW_CH,   QK_WLO,  KC_LGUI,                   KC_SPC,                    KC_RGUI, KC_NO,   RM_SPDD, RM_VALD, RM_SPDU, KC_P0,   KC_PDOT
    )
};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP)},
    [1] = {ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP)},
    [2] = {ENCODER_CCW_CW(RM_VALD, RM_VALU)},
    [3] = {ENCODER_CCW_CW(RM_VALD, RM_VALU)},
};
#endif
