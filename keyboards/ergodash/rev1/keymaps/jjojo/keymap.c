#include QMK_KEYBOARD_CONFIG_H
#include "wrappers.h"
#include "quantum.h"
#include "process_records.h"
#include "keymap_swedish.h"
#include "rgblight.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

//Tap Dance Declarations
enum {
  TD_ESC_CAPS = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
// Other declarations would go here, separated by commas, if you have them
};



enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};



#define EISU LALT(KC_GRV)

#define LAYOUT_ergodash_pretty_wrapper(...)   LAYOUT_ergodash_pretty(__VA_ARGS__)

    /* Keymap: BASE layer
     *
     * ,----------------------------------------------------.           ,----------------------------------------------------.
     * | ESC    |   1    |   2  |   3  |   4  |   5  |   [  |           |  ]   |   6  |   7  |   8  |   9  |   0    |   +    |
     * |--------+--------+------+------+------+-------------|           |------+------+------+------+------+--------+--------|
     * | `      |   K01  |  K02 |  K03 |  K04 |  K05 |   -  |           |  =   |  K06 |  K07 |  K08 |  K09 |  K0A   |   Å    |
     * |--------+--------+------+------+------+------|------|           |------|------+------+------+------+--------+--------|
     * | Tab    |   K11  |  K12 |  K13 |  K14 |  K15 |   {  |           |  '   |  K16 |  K17 |  K18 |  K19 |  K1A   |   Ä    |
     * |--------+--------+------+------+------+------|------'           `------|------+------+------+------+--------+--------|
     * | LShift |   K21  |  K22 |  K23 |  K24 |  K25 |                         |  K26 |  K27 |  K28 |  K29 |  K2A   | RShift |
     * |--------+--------+------+------+------+------'                         `------+------+------+------+--------+--------|
     * | LCtrl  |   GUI  |  Alt |  Alt |                                                     | LEFT | DOWN |   UP   | RIGHT  |
     * `-------------------------------'                                                      `-------------------------------'
     *                                       ,----------------.        ,--------------.
     *                                       |       |        |        |      |       |
     *                               ,-------| bkSpc |  RCtrl |        | Entr | Space  +-------.
     *                               | LOWER |       |        |        |      |       | RAISE |
     *                               `------------------------'        `----------------------'
     */
#define LAYOUT_ergodash_pretty_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_ergodash_pretty_wrapper( \
    TD(TD_ESC_CAPS),  ________________NUMBER_LEFT________________, SE_DLR_MAC,          SE_EQL, ________________NUMBER_RIGHT_______________, SE_PLUS, \
    KC_TAB,  TD(TD_ESC_CAPS),     K02,     K03,     K04,     K05,     SE_LESS_MAC,          LSFT(SE_GRV),  K06,    K07,    K08,    K09,    K0A,         SE_AA, \
    KC_CAPS, K11,     K12,     K13,     K14,     K15,     SE_GRTR_MAC,          KC_BSLS, K16,    K17,    K18,    K19,    K1A,         SE_AE, \
    OS_LSFT, K21,     K22,     K23,     K24,     K25,                                K26,    K27,    K28,    K29,    K2A,         OS_RSFT, \
    KC_LCTL, KC_LGUI, KC_LGUI, KC_LALT,                                                            KC_LEFT, KC_DOWN, KC_UP,       KC_RIGHT, \
                                        TT(_LOWER), KC_BSPC,  KC_RCTL,          KC_ENT, KC_SPC, TT(_RAISE)                               \
  )

#define LAYOUT_ergodash_pretty_base_wrapper(...)       LAYOUT_ergodash_pretty_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ergodash_pretty_base_wrapper(
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
  ),

  [_LOWER] = LAYOUT_ergodash_pretty_wrapper(
    KC_F11,  _________________FUNC_LEFT_________________, KC_RST ,         KC_RST , _________________FUNC_RIGHT________________, KC_F12,
    KC_TILD, _________________LOWER_L1__________________, _______,         _______, _________________LOWER_R1__________________, KC_PIPE,
    _______, _________________LOWER_L2__________________, _______,         _______, _________________LOWER_R2__________________, KC_DQUO,
    _______, _________________LOWER_L3__________________,                           _________________LOWER_R3__________________, KC_PSCR,
    _______, _______, _______, _______,                                                               _______, _______, _______, KC_PAUS,
                                        _______, _______, _______,         _______, _______, _______
  ),

  [_RAISE] = LAYOUT_ergodash_pretty_wrapper(
    KC_F12,  _________________FUNC_LEFT_________________, KC_RST,          KC_RST , _________________FUNC_RIGHT________________, KC_F11,
    KC_GRV,  _________________RAISE_L1__________________, _______,         _______, _________________RAISE_R1__________________, KC_BSLS,
    _______, _________________RAISE_L2__________________, _______,         _______, _________________RAISE_R2__________________, KC_QUOT,
    _______, _________________RAISE_L3__________________,                           _________________RAISE_R3__________________, KC_PSCR,
    _______, _______, _______, _______,                                                               KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                        _______, _______, _______,         _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_ergodash_pretty_wrapper(
    KC_F12,  _________________FUNC_LEFT_________________, KC_RST,          KC_RST , _________________FUNC_RIGHT________________, KC_F11,
    KC_GRV,  _________________ADJUST_L1_________________, _______,         _______, _________________ADJUST_R1_________________, KC_BSLS,
    _______, _________________ADJUST_L2_________________, _______,         _______, _________________ADJUST_R2_________________, KC_QUOT,
    _______, _________________ADJUST_L3_________________,                           _________________ADJUST_R3_________________, KC_PSCR,
    _______, _______, _______, _______,                                                               KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                    TO(_QWERTY), _______, _______,         _______, _______, TO(_QWERTY)
  ),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
};



void matrix_init_user(void) {
  rgblight_sethsv(0, 0, 50);
}


// void matrix_scan_user(void)
// {  // runs frequently to update info
//     uint8_t layer = biton32(layer_state); // get current layer
//     static uint8_t current_layer; // check historic layer
//     static bool has_layer_changed = true;
//     // static, so it is kept the same between calls
//     // defaults to true, so that it runs once to initially set the light

//     if (layer != current_layer) {
//         has_layer_changed = true;
//         current_layer = layer; // update layer information
//     }
//     // Check for layer change, and apply color if its changed since last check
//     if (has_layer_changed){
//         // change rgb light based on layer.
//         switch (layer){
//             case _LOWER:
//                 rgblight_sethsv(HSV_BLUE);
//                 break;
//             case _RAISE:
//                 rgblight_sethsv(HSV_GREEN);
//                 break;
//             case _ADJUST:
//                 rgblight_sethsv(HSV_RED);
//                 break;
//             default:
//                 rgblight_sethsv(HSV_WHITE);
//                 break;
//         }
//         has_layer_changed = false;
//     }
// };


