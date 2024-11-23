// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0
// Har-Si Version 1
// Callum Style One-Shot Mods
// QWERTY Base Layer

#include QMK_KEYBOARD_H

#include "oneshot.h"

#define MO_NAV MO(NAV)
#define OS_NUM OSL(NUM)
#define OS_SYM OSL(SYM)
#define OS_FUN OSL(FUN)
#define TO_MSE TO(MSE)
#define TO_BSE TO(BASE)
#define TO_NAV TO(NAVL)
#define TO_NUM TO(NUML)
#define MC_COPY C(KC_C)
#define MC_PASTE C(KC_V)
#define MC_CUT C(KC_X)


enum layers {
	BASE,
	NAV,
	NUM,
	SYM,
	FUN,
	MSE,
	NAVL,
	NUML,
};


enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
	  * BASE LAYER (QWERTY)
      * ┌───┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───┐
      * │N/A│ Q │ W │ E │ R │ T │           │ Y │ U │ I │ O │ P │N/A│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │N/A│ A │ S │ D │ F │ G │           │ H │ J │ K │ L │ ; │N/A│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │N/A│ Z │ X │ C │ V │ B │           │ N │ M │ , │ . │ / │N/A│
      * └───┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───┘
      *             ┌────┐                          ┌───┐
      *             │NUM ├────┐                ┌────┤FUN│
      *             └────┤NAV ├────┐      ┌────┤SPC ├───┘
      *                  └────┤OSFT│      │SYM ├────┘
      *                       └────┘      └────┘
      */
    [BASE] = LAYOUT_split_3x6_3(
      //--------------------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
      //--------------------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_NO,
      //--------------------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
      //--------------------------------------------------------------------------         ---------------------------------------------------------------------------------
                              OS_NUM, MO_NAV, OS_SHFT,                                         OS_SYM, KC_SPC, OS_FUN
      //--------------------------------------------------------------------------         ---------------------------------------------------------------------------------
    ),
     /*
	  * NAVIGATION LAYER
      * ┌───┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───┐
      * │N/A│   │   │   │   │   │           │ESC│HOM│UP │END│PDN│N/A│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │N/A│WIN│ALT│CTL│SFT│   │           │TAB│RGT│DWN│LFT│PUP│N/A│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │N/A│NAV│   │   │   │   │           │MEN│CUT│CPY│PST│INS│N/A│
      * └───┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───┘
      *             ┌────┐                          ┌───┐
      *             │TRN ├────┐                ┌────┤DEL│
      *             └────┤TRN ├────┐      ┌────┤BCK ├───┘
      *                  └────┤TRN │      │ENT ├────┘
      *                       └────┘      └────┘
      */
    [NAV] = LAYOUT_split_3x6_3(
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  KC_NO,    KC_NO,   KC_NO,    KC_NO,      KC_NO,                   KC_ESC,    KC_HOME,    KC_UP,    KC_END,    KC_PGUP,   KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  OS_GUI,   OS_ALT,  OS_CTRL,  OS_SHFT,    KC_NO,                  KC_TAB,    KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_PGDN,   KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  TO_NAV,   KC_NO,   KC_NO,    KC_NO,      KC_NO,                   KC_APP,    MC_CUT,  MC_COPY,   MC_PASTE,    KC_INS,    KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
                                            KC_TRNS, KC_TRNS, KC_TRNS,               KC_ENT, KC_BSPC, KC_DEL
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
    ),
     /*
	  * NUMBER LAYER
      * ┌───┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───┐
      * │N/A│   │   │   │   │   │           │ / │ 7 │ 8 │ 9 │ - │N/A│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │N/A│WIN│ALT│CTL│SFT│   │           │ * │ 4 │ 5 │ 6 │ + │N/A│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │N/A│NUM│   │   │NLK│   │           │ = │ 1 │ 2 │ 3 │ . │N/A│
      * └───┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───┘
      *             ┌────┐                          ┌───┐
      *             │TRN ├────┐                ┌────┤ 0 │
      *             └────┤TRN ├────┐      ┌────┤BCK ├───┘
      *                  └────┤TRN │      │ENT ├────┘
      *                       └────┘      └────┘
      */
    [NUM] = LAYOUT_split_3x6_3(
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                  KC_PSLS,    KC_P7,    KC_P8,      KC_P9,    KC_PMNS,   KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO, OS_GUI,    OS_ALT,   OS_CTRL,  OS_SHFT,  KC_NO,                 KC_PAST,    KC_P4,    KC_P5,      KC_P6,    KC_PPLS,   KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO, TO_NUM,    KC_NO,     KC_NO,    KC_NUM,    KC_NO,                  KC_PEQL,    KC_P1,    KC_P2,      KC_P3,    KC_PDOT,   KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
                                            KC_TRNS, KC_TRNS, KC_TRNS,           KC_ENT, KC_BSPC, KC_P0
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
    ),
     /*
	  * SYMBOLS LAYER
      * ┌───┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───┐
      * │N/A│ ~ │ ` │ | │ \ │ [ │           │ ] │ & │ * │ _ │ - │N/A│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │N/A│WIN│ALT│CTL│SFT│ ( │           │ ) │ $ │ % │ ^ │ " │N/A│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │N/A│   │   │   │CLK│ { │           │ } │ ! │ @ │ # │ ' │N/A│
      * └───┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───┘
      *             ┌────┐                          ┌───┐
      *             │TRN ├────┐                ┌────┤TRN│
      *             └────┤TRN ├────┐      ┌────┤TRN ├───┘
      *                  └────┤TRN │      │TRN ├────┘
      *                       └────┘      └────┘
      */
    [SYM] = LAYOUT_split_3x6_3(
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  KC_TILD,   KC_GRV,    KC_PIPE,    KC_BSLS,    KC_LBRC,                   KC_RBRC,  KC_AMPR,    KC_ASTR,    KC_UNDS,     KC_MINS,     KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  OS_GUI,    OS_ALT,    OS_CTRL,    OS_SHFT,    KC_LPRN,                   KC_RPRN,   KC_DLR,     KC_PERC,   KC_CIRC,     KC_DQUO,     KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  KC_NO,     KC_NO,     KC_NO,      KC_CAPS,    KC_LCBR,                   KC_RCBR,   KC_EXLM,    KC_AT,      KC_HASH,    KC_QUOT,     KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
                                             KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
    ),
     /*
	  * FUNCTION LAYER
      * ┌───┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───┐
      * │N/A│   │   │   │   │   │           │PSC│F7 │F8 │F9 │F12│N/A│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │N/A│WIN│ALT│CTL│SFT│   │           │SLK│F4 │F5 │F6 │F11│N/A│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │N/A│   │   │   │   │   │           │PUS│F1 │F2 │F3 │F10│N/A│
      * └───┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───┘
      *             ┌────┐                          ┌────┐
      *             │TRN ├────┐                ┌────┤MOUS│
      *             └────┤TRN ├────┐      ┌────┤TRN ├────┘
      *                  └────┤TRN │      │TRN ├────┘
      *                       └────┘      └────┘
      */
    [FUN] = LAYOUT_split_3x6_3(
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                   KC_PSCR,    KC_F7,    KC_F8,    KC_F9,    KC_F12,    KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  OS_GUI,   OS_ALT,   OS_CTRL,  OS_SHFT,  KC_NO,                   KC_SCRL,    KC_F4,    KC_F5,    KC_F6,    KC_F11,    KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                   KC_PAUS,    KC_F1,    KC_F2,    KC_F3,    KC_F10,     KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
                                           KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, TO_MSE
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
    ),
     /*
	  * MOUSE LAYER
      * ┌───┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───┐
      * │N/A│PRV│PLY│STP│NXT│   │           │   │WLF│MUP│WRT│WUP│N/A│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │N/A│WIN│ALT│CTL│SFT│   │           │   │MLF│MDN│MRT│WDN│N/A│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │N/A│   │VDN│MUT│VUP│   │           │   │AC0│AC1│AC2│   │N/A│
      * └───┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───┘
      *             ┌────┐                          ┌────┐
      *             │TRN ├────┐                ┌────┤CCLK│
      *             └────┤MOU ├────┐      ┌────┤LCLK├────┘
      *                  └────┤TRN │      │RCLK├────┘
      *                       └────┘      └────┘
      */
    [MSE] = LAYOUT_split_3x6_3(
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  KC_MPRV,   KC_MPLY,   KC_MSTP,  KC_MNXT,   KC_NO,                  KC_NO,    KC_WH_L,    KC_MS_U,      KC_WH_R,    KC_WH_U,   KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  OS_GUI,    OS_ALT,    OS_CTRL,  OS_SHFT,   KC_NO,                  KC_NO,    KC_MS_L,    KC_MS_D,      KC_MS_R,    KC_WH_D,   KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  KC_NO,     KC_VOLD,   KC_MUTE,  KC_VOLU,   KC_NO,                  KC_NO,    KC_ACL0,    KC_ACL1,      KC_ACL2,    KC_NO,     KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
                                            KC_TRNS, TO_BSE, KC_TRNS,           KC_BTN2, KC_BTN1, KC_BTN3
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
    ),	
	/*
	  * NAVIGATION LOCK LAYER
      * ┌───┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───┐
      * │N/A│   │   │   │   │   │           │ESC│HOM│UP │END│PDN│N/A│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │N/A│WIN│ALT│CTL│SFT│   │           │TAB│RGT│DWN│LFT│PUP│N/A│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │N/A│   │   │   │   │   │           │MEN│CUT│CPY│PST│INS│N/A│
      * └───┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───┘
      *             ┌────┐                          ┌───┐
      *             │TRN ├────┐                ┌────┤DEL│
      *             └────┤BSE ├────┐      ┌────┤BCK ├───┘
      *                  └────┤TRN │      │ENT ├────┘
      *                       └────┘      └────┘
      */
    [NAVL] = LAYOUT_split_3x6_3(
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,                   KC_ESC,    KC_HOME,    KC_UP,    KC_END,    KC_PGUP,   KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  OS_GUI,   OS_ALT,  OS_CTRL,  OS_SHFT,    KC_NO,                  KC_TAB,    KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_PGDN,   KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  KC_NO,    KC_NO,   KC_NO,    KC_NO,     KC_NO,                   KC_APP,    MC_CUT,  MC_COPY,   MC_PASTE,    KC_INS,    KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
                                            KC_TRNS, TO_BSE, KC_TRNS,               KC_ENT, KC_BSPC, KC_DEL
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
    ),
     /*
	  * NUMBER LOCK LAYER
      * ┌───┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───┐
      * │N/A│   │   │   │   │   │           │ / │ 7 │ 8 │ 9 │ - │N/A│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │N/A│WIN│ALT│CTL│SFT│   │           │ * │ 4 │ 5 │ 6 │ + │N/A│
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │N/A│   │   │   │NLK│   │           │ = │ 1 │ 2 │ 3 │ . │N/A│
      * └───┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───┘
      *             ┌────┐                          ┌───┐
      *             │TRN ├────┐                ┌────┤ 0 │
      *             └────┤BSE ├────┐      ┌────┤BCK ├───┘
      *                  └────┤TRN │      │ENT ├────┘
      *                       └────┘      └────┘
      */
    [NUML] = LAYOUT_split_3x6_3(
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                  KC_PSLS,    KC_P7,    KC_P8,      KC_P9,    KC_PMNS,   KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO, OS_GUI,    OS_ALT,   OS_CTRL,  OS_SHFT,  KC_NO,                 KC_PAST,    KC_P4,    KC_P5,      KC_P6,    KC_PPLS,   KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO, KC_NO,    KC_NO,     KC_NO,    KC_NUM,    KC_NO,                  KC_PEQL,    KC_P1,    KC_P2,      KC_P3,    KC_PDOT,   KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
                                            KC_TRNS, TO_BSE, KC_TRNS,           KC_ENT, KC_BSPC, KC_P0
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
    ),
};


bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case MO_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case MO_NAV:
    case OS_NUM:
	case OS_SYM:
	case OS_FUN:
	case TO_MSE:
	case TO_BSE:
	case TO_NAV:
	case TO_NUM:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_GUI:
        return true;
    default:
        return false;
    }
}


oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_gui_state, KC_LGUI, OS_GUI,
        keycode, record
    );

    return true;
}
