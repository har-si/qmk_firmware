// Copyright 2023 Harold (@har-si)
// SPDX-License-Identifier: GPL-2.0
// Har-Si Version 1
// Callum Style One-Shot Mods
// QWERTY Base Layer
// Special Alt+Tab Macro

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
#define MC_UNDO	C(KC_Z)
#define MC_REDO	C(KC_Y)
#define MC_ALTF4 A(KC_F4)
#define OS_MEH OSM(MOD_MEH)

#define __x__ KC_NO

#define LAYER_TIMEOUT 60000  //configure your timeout in milliseconds


bool is_alt_tab_active = false; //Special Alt+Tab Macro on Nav Layer


enum layers {
	BASE,
	NAV,
	NUM,
	SYM,
	FUN,
	MSE,
	NAVL,
	NUML
};


enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
	OS_ALGR,
	MC_SPTAB    // Custom Special Tab
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
	  * BASE LAYER (QWERTY)
      * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
      * │ ESC │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │ BSPC│
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ TAB │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ SHFT│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │ CWRD│
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ CTRL│ GUI │ ALT │ NUM │ NAV │ OSFT│ SPC │ SYM │ FUN │ MEH │ RALT│ ENT │
	  * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
      */
    [BASE] = LAYOUT_ortho_4x12(
      //-----------------------------------------------------------------------------------------------------------------------------------------------------------
        KC_ESC,     KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC,
      //-----------------------------------------------------------------------------------------------------------------------------------------------------------
        KC_TAB,     KC_A,     KC_S,     KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
      //-----------------------------------------------------------------------------------------------------------------------------------------------------------
        KC_LSFT,    KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  CW_TOGG,
      //-----------------------------------------------------------------------------------------------------------------------------------------------------------
        KC_LCTL,    KC_LGUI,  KC_LALT,  OS_NUM,  MO_NAV,  OS_SHFT,  KC_SPC,  OS_SYM,  OS_FUN,   OS_MEH,   OS_ALGR,  KC_ENT
      //-----------------------------------------------------------------------------------------------------------------------------------------------------------
    ),
     /*
	  * NAVIGATION LAYER
      * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
      * │ ESC │     │     │     │ ALF4│     │ HOME│ PGDN│ PGUP│ END │ INS │ BSPC│
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ STAB│ CTRL│ GUI │ ALT │ SHFT│ TAB │ RGHT│ DOWN│ UP  │ LEFT│ MENU│ DEL │
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ SHFT│ NAVL│ MEH │     │     │     │ UNDO│ CUT │ COPY│ PSTE│ REDO│     │
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ CTRL│ WIN │ ALT │     │     │ OSFT│ SPC │     │     │ MEH │ RALT│ ENT │
	  * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
      */
    [NAV] = LAYOUT_ortho_4x12(
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_ESC,    __x__,     __x__,    __x__,    MC_ALTF4,   __x__,     KC_HOME,    KC_PGDN,   KC_PGUP,   KC_END,     KC_INS,     KC_BSPC,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        MC_SPTAB,  KC_LCTL,   KC_LGUI,  KC_LALT,  KC_LSFT,    KC_TAB,    KC_LEFT,    KC_DOWN,   KC_UP,     KC_RGHT,    KC_APP,     KC_DEL,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_LSFT,   TO_NAV,    OS_MEH,   __x__,    __x__,      __x__,     MC_UNDO,    MC_CUT,    MC_COPY,   MC_PASTE,   MC_REDO,    __x__,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_LCTL,   KC_LGUI,   KC_LALT,  __x__,    KC_TRNS,    OS_SHFT,   KC_SPC,     __x__,     __x__,     OS_MEH,     OS_ALGR,    KC_ENT
      //-----------------------------------------------------------------------------------------------------------------------------------------------
    ),
     /*
	  * NUMBER LAYER
      * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
      * │ ESC │     │     │  (  │  [  │  {  │  /  │  7  │  8  │  9  │  -  │ BSPC│
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ TAB │ CTRL│ GUI │ ALT │ SHFT│     │  *  │  4  │  5  │  6  │  +  │ NLCK│
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ SHFT│ NUML│ MEH │  )  │  ]  │  }  │  =  │  1  │  2  │  3  │  +  │  \  │
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ CTRL│ WIN │ ALT │     │     │ OSFT│ SPC │  0  │  ,  │  .  │ RALT│ ENT │
	  * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
      */
    [NUM] = LAYOUT_ortho_4x12(
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_ESC,   __x__,     __x__,     KC_LPRN,    KC_LBRC,    KC_LCBR,    KC_SLSH,    KC_7,    KC_8,      KC_9,     KC_MINS,   KC_BSPC,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_TAB,   KC_LCTL,   KC_LGUI,   KC_LALT,    KC_LSFT,    __x__,      KC_ASTR,    KC_4,    KC_5,      KC_6,     KC_PLUS,   KC_NUM,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_LSFT,  TO_NUM,    OS_MEH,    KC_RPRN,    KC_RBRC,    KC_RCBR,    KC_EQL,     KC_1,    KC_2,      KC_3,     KC_PLUS,   KC_BSLS,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_LCTL,  KC_LGUI,   KC_LALT,   KC_TRNS,    __x__,      OS_SHFT,    KC_SPC,     KC_0,    KC_COMM,   KC_DOT,   OS_ALGR,   KC_ENT
      //-----------------------------------------------------------------------------------------------------------------------------------------------
    ),
     /*
	  * SYMBOLS LAYER
      * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
      * │ ESC │  ~  │  `  │  (  │  [  │  {  │  /  │  &  │  *  │  _  │  -  │ BSPC│
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ TAB │ CTRL│ GUI │ ALT │ SHFT│     │  *  │  $  │  %  │  ^  │  +  │ CAPL│
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ SHFT│ MSE │ MEH │  )  │  ]  │  }  │  =  │  !  │  @  │  #  │  |  │  \  │
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ CTRL│ WIN │ ALT │     │     │ OSFT│ SPC │     │  ,  │  .  │ RALT│ ENT │
	  * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
      */
    [SYM] = LAYOUT_ortho_4x12(
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_ESC,   KC_TILD,   KC_GRV,     KC_LPRN,    KC_LBRC,    KC_LCBR,    KC_SLSH,    KC_AMPR,   KC_ASTR,    KC_UNDS,     KC_MINS,    KC_BSPC,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_TAB,   OS_CTRL,   OS_GUI,     OS_ALT,     OS_SHFT,    __x__,      KC_ASTR,    KC_DLR,    KC_PERC,    KC_CIRC,     KC_PLUS,    KC_CAPS,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_LSFT,  TO_MSE,    OS_MEH,      KC_RPRN,    KC_RBRC,    KC_RCBR,    KC_EQL,     KC_EXLM,   KC_AT,      KC_HASH,     KC_PIPE,    KC_BSLS,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_LCTL,  KC_LGUI,   KC_LALT,    __x__,      __x__,      OS_SHFT,    KC_SPC,     KC_TRNS,   KC_COMM,    KC_DOT,      OS_ALGR,    KC_ENT
      //-----------------------------------------------------------------------------------------------------------------------------------------------
    ),
     /*
	  * FUNCTION LAYER
      * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
      * │ ESC │     │ VOLU│ MUTE│ VOLD│     │ PSCR│  F7 │  F8 │  F9 │ F12 │ BSPC│
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ TAB │ CTRL│ GUI │ ALT │ SHFT│     │ SCRL│  F4 │  F5 │  F6 │ F11 │     │
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ SHFT│ PREV│ PLAY│ STOP│ NEXT│     │ PUSB│  F1 │  F2 │  F3 │ F10 │     │
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ CTRL│ WIN │ ALT │     │     │ OSFT│ SPC │     │     │ MEH │ RALT│ ENT │
	  * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
      */
    [FUN] = LAYOUT_ortho_4x12(
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_ESC,   __x__,     KC_VOLD,   KC_MUTE,    KC_VOLU,    __x__,      KC_PSCR,    KC_F7,    KC_F8,      KC_F9,     KC_F12,     KC_BSPC,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_TAB,   OS_CTRL,   OS_GUI,    OS_ALT,     OS_SHFT,    __x__,      KC_SCRL,    KC_F4,    KC_F5,      KC_F6,     KC_F11,     __x__,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_LSFT,  KC_MPRV,   KC_MPLY,   KC_MSTP,    KC_MNXT,    __x__,      KC_PAUS,    KC_F1,    KC_F2,      KC_F3,     KC_F10,     __x__,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_LCTL,  KC_LGUI,   KC_LALT,   __x__,      __x__,      OS_SHFT,    KC_SPC,     __x__,    KC_TRNS,    OS_MEH,    OS_ALGR,    KC_ENT
      //-----------------------------------------------------------------------------------------------------------------------------------------------
    ),
     /*
	  * MOUSE LAYER
      * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
      * │ ESC │     │     │     │     │     │ WH_l│ WH_D│ WH_U│ WH_R│     │ BSPC│
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ TAB │ CTRL│ GUI │ ALT │ SHFT│     │ MS_l│ MS_D│ MS_U│ MS_R│     │ DEL │
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ SHFT│     │ MEH │     │     │     │     │ ACL0│ ACL1│ ACL2│     │     │
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ CTRL│ WIN │ ALT │ BASE│ BASE│     │ lCLK│ RCLK│ CCLK│ MEH │ RALT│ ENT │
	  * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
      */
    [MSE] = LAYOUT_ortho_4x12(
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_ESC,    __x__,     __x__,    __x__,     __x__,      __x__,     KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R,     __x__,     KC_BSPC,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_TAB,    KC_LCTL,   KC_LGUI,  KC_LALT,   KC_LSFT,    __x__,     KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,     __x__,     KC_DEL,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_LSFT,   __x__,     OS_MEH,    __x__,     __x__,      __x__,     __x__,      KC_ACL0,    KC_ACL1,    KC_ACL2,     __x__,     __x__,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_LCTL,   KC_LGUI,   KC_LALT,  TO_BSE,    TO_BSE,     __x__,     KC_BTN1,    KC_BTN2,    KC_BTN3,    OS_MEH,      OS_ALGR,   KC_ENT
      //-----------------------------------------------------------------------------------------------------------------------------------------------
    ),
	/*
	  * NAVIGATION LOCK LAYER
      * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
      * │ ESC │     │     │     │ ALF4│     │ HOME│ PGDN│ PGUP│ END │ INS │ BSPC│
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ TAB │ CTRL│ GUI │ ALT │ SHFT│ TAB │ RGHT│ DOWN│ UP  │ LEFT│ MENU│ DEL │
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ SHFT│     │ MEH │     │     │     │ UNDO│ CUT │ COPY│ PSTE│ REDO│     │
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ CTRL│ WIN │ ALT │ BASE│ BASE│ OSFT│ SPC │     │     │ MEH │ RALT│ ENT │
	  * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
      */
    [NAVL] = LAYOUT_ortho_4x12(
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_ESC,    __x__,     __x__,    __x__,    MC_ALTF4,   __x__,     KC_HOME,    KC_PGDN,   KC_PGUP,   KC_END,      KC_INS,     KC_BSPC,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        MC_SPTAB,  KC_LCTL,   KC_LGUI,  KC_LALT,  KC_LSFT,    KC_TAB,    KC_LEFT,    KC_DOWN,   KC_UP,     KC_RGHT,     KC_APP,     KC_DEL,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_LSFT,   __x__,     OS_MEH,    __x__,    __x__,      __x__,     MC_UNDO,    MC_CUT,    MC_COPY,   MC_PASTE,    MC_REDO,    __x__,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_LCTL,   KC_LGUI,   KC_LALT,  TO_BSE,   TO_BSE,     OS_SHFT,   KC_SPC,     __x__,     __x__,     OS_MEH,      OS_ALGR,    KC_ENT
      //-----------------------------------------------------------------------------------------------------------------------------------------------
    ),
     /*
	  * NUMBER LOCK LAYER
      * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
      * │ ESC │     │     │  (  │  [  │  {  │  /  │  7  │  8  │  9  │  -  │ BSPC│
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ TAB │ CTRL│ GUI │ ALT │ SHFT│     │  *  │  4  │  5  │  6  │  +  │ NLCK│
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ SHFT│     │ MEH │  )  │  ]  │  }  │  =  │  1  │  2  │  3  │  +  │  \  │
      * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
      * │ CTRL│ WIN │ ALT │ BASE│ BASE│ OSFT│ SPC │  0  │  ,  │  .  │ RALT│ ENT │
	  * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
      */
    [NUML] = LAYOUT_ortho_4x12(
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_ESC,   __x__,     __x__,     KC_LPRN,    KC_LBRC,    KC_LCBR,    KC_PSLS,    KC_P7,    KC_P8,      KC_P9,     KC_PMNS,   KC_BSPC,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_TAB,   KC_LCTL,   KC_LGUI,   KC_LALT,    KC_LSFT,    __x__,      KC_PAST,    KC_P4,    KC_P5,      KC_P6,     KC_PPLS,   KC_NUM,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_LSFT,  __x__,     OS_MEH,     KC_RPRN,    KC_RBRC,    KC_RCBR,    KC_PEQL,    KC_P1,    KC_P2,      KC_P3,     KC_PPLS,   KC_BSLS,
      //-----------------------------------------------------------------------------------------------------------------------------------------------
        KC_LCTL,  KC_LGUI,   KC_LALT,   TO_BSE,     TO_BSE,     OS_SHFT,    KC_SPC,     KC_P0,    KC_COMM,    KC_PDOT,   OS_ALGR,   KC_ENT
      //-----------------------------------------------------------------------------------------------------------------------------------------------
    ),
};


bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case MO_NAV:
    case OS_NUM:
	case OS_SYM:
	case OS_FUN:
	case TO_MSE:
	case TO_BSE:
	case TO_NAV:
	case TO_NUM:
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
	case OS_ALGR:
        return true;
    default:
        return false;
    }
}


oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;
oneshot_state os_algr_state = os_up_unqueued;


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
    update_oneshot(
        &os_algr_state, KC_ALGR, OS_ALGR,
        keycode, record
    );


	//Special Alt+Tab Macro.. Holds Alt while on NAV layer..
    switch (keycode) {
        case MC_SPTAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {             //if error occur, change is_alt_tab_active == false
                    is_alt_tab_active = true;
                    register_code16(KC_LALT);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;

        case KC_ENT:                                 //Release special tab alt mod if enter is pressed os that it can be implemented on NAVL.
            if (record->event.pressed) {
                if (is_alt_tab_active) {             //if error occur, change is_alt_tab_active == false
                    register_code16(KC_ENT);
                    unregister_code16(KC_LALT);
                    is_alt_tab_active = false;
                    return false;
                }else{
                    return true;
                }
            }else {
                return true;
            }
    }

    return true;
}


//Special Alt+Tab Macro.. Release Alt upon exiting NAV Layer..
layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(state) != NAV && is_alt_tab_active) {    //if error occur, change is_alt_tab_active == true
        unregister_code16(KC_LALT);
        is_alt_tab_active = false;
    }

    if (get_highest_layer(state) == NAV && get_oneshot_mods()) {
        clear_oneshot_mods();
        clear_mods();
    }

    if (get_highest_layer(state) == NUM && get_oneshot_mods()) {
        clear_oneshot_mods();
        clear_mods();
    }

    return state;
}




//Caps Word Implementation
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}



//Timer for TO layers (locking layers). TO layer will deactivate after lapse of specific time without activity.

void matrix_scan_user(void) {
  if (get_highest_layer(layer_state) == NAVL) {
    if (last_input_activity_elapsed() > LAYER_TIMEOUT) {
      layer_off(NAVL);     // Turnoff Navigation Layer Lock
    }
  }

  if (get_highest_layer(layer_state) == NUML) {
    if (last_input_activity_elapsed() > LAYER_TIMEOUT) {
      layer_off(NUML);    // Turnoff Number layer Lock
    }
  }
  if (get_highest_layer(layer_state) == MSE) {
    if (last_input_activity_elapsed() > LAYER_TIMEOUT) {
      layer_off(MSE);    // Turnoff Number layer Lock
    }
  }

}

