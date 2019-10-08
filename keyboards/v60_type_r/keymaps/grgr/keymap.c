/* Copyright 2017 benlyall, MechMerlin, grgr
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

enum custom_keycodes {
  TMUX_O = SAFE_RANGE,
  TMUX_C,
  TMUX_VSPLIT,
  TMUX_HSPLIT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TMUX_O:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"o");
      } else {
      }
      break;
    case TMUX_C:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"c");
      } else {
      }
      break;
    case TMUX_VSPLIT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"%");
      } else {
      }
      break;
    case TMUX_HSPLIT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"\"");
      } else {
      }
      break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Default Layer (Qwerty)
   * ,-----------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   Bs  |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
   * |-----------------------------------------------------------|
   * |Cps/Ctrl|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return|
   * |-----------------------------------------------------------|
   * |LShift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RShift   |
   * |-----------------------------------------------------------|
   * |Ctrl|Alt |Gui |      Space/Fn           |Alt |Gui|Ctrl|Layr|
   * `-----------------------------------------------------------'
   */
  [0] = LAYOUT_60_ansi(
         KC_ESC,             KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
         LT(2,KC_TAB),       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
         CTL_T(KC_CAPS),     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT,          KC_ENT,  \
         KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,          KC_RSFT,   \
         KC_LCTL,   KC_LALT,   KC_LGUI,                      LT(1,KC_SPC),                           KC_RALT,  KC_RCTL, KC_RGUI, TG(1)),

  /* Keymap 1: FN Layer
   * ,-----------------------------------------------------------.
   * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
   * |-----------------------------------------------------------|
   * |     |   |   |MU |MB1|   |   |   |Prt|Scl|Pau|Up|   | Ins  |
   * |-----------------------------------------------------------|
   * |      |   |ML |MD |MR |   |Lef|Dwn|Up |Rig|Hme|PgU|        |
   * |-----------------------------------------------------------|
   * |        |   |   |MB2|   |VolD|VolU|Mut|End|PgD|Dwn|        |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
  [1] = LAYOUT_60_ansi(
         KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL, \
         KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_MS_UP, KC_MS_BTN1,   KC_TRNS,  KC_TRNS,   KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,    KC_TRNS,          KC_INS, \
         KC_TRNS,   KC_TRNS,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT, KC_TRNS,  KC_LEFT,   KC_DOWN, KC_UP, KC_RIGHT, KC_PGDOWN, KC_PGUP,          KC_TRNS,          \
         KC_TRNS,   KC_TRNS,  KC_MS_BTN3,  KC_MS_BTN2,  KC_TRNS,  KC_VOLD,   KC_VOLU, KC_MUTE, KC_TRNS,  KC_HOME,  KC_END,           KC_TRNS,  \
         KC_TRNS,   KC_TRNS,  KC_TRNS,            KC_TRNS,                                                           KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS),

  /* Keymap 2: tmux shortcuts
   * ,-----------------------------------------------------------.
   * |   |   |   |   |   |Vsp|   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   | O |   |   |   |     |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |Hsp|      |
   * |-----------------------------------------------------------|
   * |        |   |   | C |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                         |    |   |    |    |
   * `-----------------------------------------------------------'
   */
  [2] = LAYOUT_60_ansi(
         KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    TMUX_VSPLIT,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, \
         KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    TMUX_O,      KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, \
         KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,    TMUX_HSPLIT,          KC_TRNS,  \
         KC_TRNS,      KC_TRNS,    KC_TRNS,    TMUX_C,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,   KC_TRNS,         KC_TRNS,   \
         KC_TRNS,   KC_TRNS,   KC_TRNS,                          KC_TRNS,                           KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS),


  /* Keymap N: Transparent Layer (new layer template)
   * ,-----------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |   |      |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                         |    |   |    |    |
   * `-----------------------------------------------------------'
   */
  /*
  [N] = LAYOUT_60_ansi(
         KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, \
         KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, \
         KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,          KC_TRNS,  \
         KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,   KC_TRNS,          KC_TRNS,   \
         KC_TRNS,   KC_TRNS,   KC_TRNS,                           KC_TRNS,                           KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS),
  */

};

void led_set_user(uint8_t usb_led) {

}
