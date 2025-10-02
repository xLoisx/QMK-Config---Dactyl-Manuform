// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/* Layers
 * _QWERTY = Base
 * _LOWER  = Symbols / Numpad
 * _RAISE  = Function / Arrows
 * _MOUSE  = Mouse keys
 */

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _MOUSE,
};

// Layer macros
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define MOUSE TG(_MOUSE)   // toggle mouse layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
      KC_VOLD, KC_1, KC_2, KC_3, KC_4, KC_5,                                          KC_6, KC_7, KC_8, KC_9, KC_0, KC_VOLU,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                           KC_Y, KC_U, KC_I, KC_O, KC_P, KC_GRV,
      KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,                                          KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
      KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                                          KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
      KC_RBRC, KC_LBRC, KC_MINS, KC_EQL, KC_ESC, KC_SPC, KC_ENT, KC_BSPC,
      KC_LALT, KC_HOME, KC_DEL, KC_RALT, KC_PSCR, TG(1), KC_END, KC_RGUI
    ),

    [1] = LAYOUT(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                     MS_WHLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                     MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                     MS_WHLD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, MS_BTN1, MS_BTN2, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(2), KC_NO, KC_NO
    ),

    [2] = LAYOUT(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                     KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), KC_NO, KC_NO
    ),


};
