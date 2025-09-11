// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

	/* Base (qwerty)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                             |   6  |   7  |   8  |   9  |   0  |  BSC |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | TAB  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |  win |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * |      |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |  '   |
     * +------+------+------+------+-------------+                             |-------------+------+------+------+------+
     * |      |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |  \   |
     * +------+------+------+------+------+------+                             |-------------+-------------+------+------+
     *               |      |      |Space | M(0) |                             | M(1) |Enter |      |      |
     *               +------|------|------+------|                             |------+------|------|------|
     *                             | CTRL | END  |                             | HOME |Shift |
     *                             +-------------+                             +-------------+
     *                             | BSPC |   [  |                             |   ]  |  ALT |
     *                             |------+------|                             |------+------|
    */

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_MRWD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MFFD, 
        KC_VOLD, KC_Q, KC_W, KC_E, KC_R, LT(2,KC_T), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_VOLU, 
        KC_MUTE, LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), LT(3,KC_G), KC_H, RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT, 
        KC_MPLY, KC_Z, KC_X, KC_C, KC_V, LT(1,KC_B), LT(1,KC_N), KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, 
        KC_UNDS, KC_MINS, KC_EQL, KC_PPLS, KC_QUOT, KC_SPC, KC_ENT, KC_BSPC, KC_TAB, KC_ESC, KC_ESC, KC_TAB, LGUI(KC_TAB), SGUI(KC_4), SGUI(KC_5), RGUI(KC_GRV)
    ),

    [_LOWER] = LAYOUT(
        KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
        _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
        _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
        _______,_______,_______,_______,_______,_______,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                        _______,_______,_______,_______,                        _______,_______,_______,_______,
                                        _______,_______,                        _______,_______,
                                        _______,_______,                        _______,_______
    ),

    [_RAISE] = LAYOUT(
        _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC,_______,KC_NUM ,KC_INS ,KC_SCRL,KC_MUTE,
        _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
                        _______,_______,_______,_______,                        _______,_______,_______,_______,
                                        _______,_______,                        _______,_______,
                                        _______,_______,                        _______,_______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}