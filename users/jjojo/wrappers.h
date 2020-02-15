#pragma once
#include "jjojo.h"
#include "keymap_swedish.h"

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off

#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)

// Based on the LAYOUT_3key_2us layout
/*  ---------- LEFT HAND -----------                ---------- RIGHT HAND ---------- */
#define LAYOUT_ergodash_pretty( \
    L00, L01, L02, L03, L04, L05, L06,              R00, R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15, L16,              R10, R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25, L26,              R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35,                        R31, R32, R33, R34, R35, R36, \
    L40, L41, L42, L43,                                            R43, R44, R45, R46, \
                             L44, L45, L46,    R40, R41, R42                           \
    ) \
	{ \
        { L00, L01, L02, L03, L04, L05, L06 }, \
        { L10, L11, L12, L13, L14, L15, L16 }, \
        { L20, L21, L22, L23, L24, L25, L26 }, \
        { L30, L31, L32, L33, L34, L35, KC_NO }, \
        { L40, L41, L42, L43, L44, L45, L46 }, \
        { R06, R05, R04, R03, R02, R01, R00 }, \
        { R16, R15, R14, R13, R12, R11, R10 }, \
        { R26, R25, R24, R23, R22, R21, R20 }, \
        { R36, R35, R34, R33, R32, R31, KC_NO }, \
        { R46, R45, R44, R43, R42, R41, R40 }  \
    }

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/
#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


#define ___________________BLANK___________________        _______, _______, _______, _______, _______


#define _________________LOWER_L1__________________        SE_COLN, SE_LCBR, ALGR(KC_8), SE_LPRN, SE_PIPE
#define _________________LOWER_L2__________________        SE_COLN, SE_LCBR_MAC, ALGR(KC_8), SE_LPRN, SE_PIPE_MAC
#define _________________LOWER_L3__________________        _________________FUNC_RIGHT________________

#define _________________LOWER_R1__________________        SE_AMPR, SE_RPRN, ALGR(KC_9),SE_RCBR,  SE_SCLN
#define _________________LOWER_R2__________________        SE_AMPR, SE_RPRN, ALGR(KC_9),SE_RCBR_MAC,  SE_SCLN
#define _________________LOWER_R3__________________        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT



#define _________________RAISE_L1__________________        ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________        ___________________BLANK___________________
#define _________________RAISE_L3__________________        ___________________BLANK___________________

#define _________________RAISE_R1__________________        ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_R3__________________        _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END



#define _________________ADJUST_L1_________________        ___________________BLANK___________________
#define _________________ADJUST_L2_________________        _________________FUNC_LEFT_________________
#define _________________ADJUST_L3_________________        ___________________BLANK___________________

#define _________________ADJUST_R1_________________        ___________________BLANK___________________
#define _________________ADJUST_R2_________________        _________________FUNC_RIGHT________________
#define _________________ADJUST_R3_________________        KC_MUTE, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT

// clang-format on
