// Copyright 2023 Harold (@har-si)
// SPDX-License-Identifier: GPL-2.0
// Har-Si Version 2
// Callum Style One-Shot Mods
// QWERTY Base Layer
// Special Alt+Tab Macro
// Mouse Keys Constant Mode

#include QMK_KEYBOARD_H


#include "oneshot.h"

#define MO_NAV MO(NAV)
#define TO_BSE TO(BASE)
#define TO_NAV TO(NAVL)
#define TO_NUM TO(NUML)
#define TO_MSE TO(MSEL)

#define MC_COPY C(KC_C)
#define MC_PASTE C(KC_V)
#define MC_CUT C(KC_X)
#define MC_UNDO	C(KC_Z)
#define MC_REDO	C(KC_Y)
#define MC_ALTF4 A(KC_F4)
#define OS_MEH OSM(MOD_MEH)

#define __x__ KC_NO

// #define LAYER_TIMEOUT 60000  //configure your timeout in milliseconds


bool is_alt_tab_active = false; //Special Alt+Tab Macro on Nav Layer


enum ferris_layers {
	BASE,
	NAV,
	NUM,
	FUN,
	MSE,
	NAVL,
	NUML,
  MSEL
};


enum ferris_tap_dances {
  TD_NUM_SYM
};


enum keycodes {
    // Custom oneshot mod implementation with no timers.
  OS_SHFT = SAFE_RANGE,
  OS_CTRL,
  OS_ALT,
  OS_GUI,
	OS_ALGR,
	MC_SPTAB,    // Custom Special Tab
	MC_NAV       // Clear all layer and activate NAV
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,
    KC_A,     KC_S,     KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,
    KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,
                                      MC_NAV,  TD(TD_NUM_SYM), KC_SPC, OSM(MOD_LSFT)
  ),


  [NAV] = LAYOUT(
    KC_ESC,    MC_SPTAB,    __x__,    MC_ALTF4,   __x__,              KC_HOME,    KC_PGDN,   KC_PGUP,   KC_END,     KC_INS,
    KC_LCTL,   KC_LGUI,     KC_LALT,  KC_LSFT,    KC_ALGR,            KC_LEFT,    KC_DOWN,   KC_UP,     KC_RGHT,    KC_APP,
    TO_NAV,    TO_MSE,      __x__,    CW_TOGG,    __x__,              MC_UNDO,    KC_TAB,    MC_COPY,   MC_PASTE,   KC_ENT,
                                             KC_TRNS, KC_TRNS, KC_BSPC, KC_DEL
  ),


  [NUM] = LAYOUT(
    KC_ESC,    KC_GRV,    KC_LPRN,    KC_LBRC,    KC_LCBR,             KC_PSLS,    KC_7,    KC_8,      KC_9,     KC_MINS,
    OS_CTRL,   OS_GUI,    OS_ALT,     OS_SHFT,    OS_ALGR,             KC_ASTR,    KC_4,    KC_5,      KC_6,     KC_PLUS,
    TO_NUM,    KC_TILDE,  KC_RPRN,    KC_RBRC,    KC_RCBR,             KC_PDOT,    KC_1,    KC_2,      KC_3,     KC_ENT,
                                             KC_TRNS, KC_TRNS,  KC_BSPC, KC_0
  ),


  [FUN] = LAYOUT(
    KC_ESC,    KC_VOLD,   KC_MUTE,    KC_VOLU,    KC_NUM,              KC_PSCR,    KC_F7,    KC_F8,      KC_F9,     KC_F12,
    KC_LCTL,   KC_LGUI,   KC_LALT,    KC_LSFT,    KC_ALGR,             KC_SCRL,    KC_F4,    KC_F5,      KC_F6,     KC_F11,
    KC_MPRV,   KC_MPLY,   KC_MSTP,    KC_MNXT,    KC_CAPS,             KC_PAUS,    KC_F1,    KC_F2,      KC_F3,     KC_F10,
                                             KC_TRNS, KC_TRNS, KC_BSPC, KC_DEL
  ),


  [MSE] = LAYOUT(
    KC_ESC,    __x__,      __x__,     __x__,      __x__,               KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R,     KC_INS,
    KC_LCTL,   KC_LGUI,    KC_LALT,  KC_LSFT,    KC_ALGR,              KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,     KC_BTN2,
    TO_MSE,    KC_ACL2,    KC_ACL1,  KC_ACL0,    __x__,                KC_BTN3,    MC_CUT,     MC_COPY,    MC_PASTE,    KC_ENT,
                                             KC_TRNS, KC_TRNS, KC_BTN1, KC_DEL
  ),

  [NAVL] = LAYOUT(
    KC_ESC,    MC_SPTAB,    __x__,    MC_ALTF4,   __x__,              KC_HOME,    KC_PGDN,   KC_PGUP,   KC_END,     KC_INS,
    KC_LCTL,   KC_LGUI,     KC_LALT,  KC_LSFT,    KC_ALGR,            KC_LEFT,    KC_DOWN,   KC_UP,     KC_RGHT,    KC_APP,
    __x__,     TO_MSE,      __x__,    CW_TOGG,    __x__,              MC_UNDO,    KC_TAB,    MC_COPY,   MC_PASTE,   KC_ENT,
                                              KC_TRNS, KC_TRNS, KC_BSPC, KC_DEL
  ),


  [NUML] = LAYOUT(
    KC_ESC,    KC_GRV,    KC_LPRN,    KC_LBRC,    KC_LCBR,             KC_PSLS,    KC_P7,    KC_P8,      KC_P9,     KC_PMNS,
    KC_LCTL,   KC_LGUI,   KC_LALT,    KC_LSFT,    KC_ALGR,             KC_PAST,    KC_P4,    KC_P5,      KC_P6,     KC_PPLS,
    __x__,     KC_MEH,    KC_RPRN,    KC_RBRC,    KC_RCBR,             KC_PDOT,    KC_P1,    KC_P2,      KC_P3,     KC_PENT,
                                             KC_TRNS, KC_TRNS,  KC_BSPC, KC_P0
  ),


  [MSEL] = LAYOUT(
    KC_ESC,    __x__,    __x__,     __x__,      __x__,                KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R,     KC_INS,
    KC_LCTL,   KC_LGUI,  KC_LALT,   KC_LSFT,    KC_ALGR,              KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,     KC_BTN2,
    __x__,     KC_ACL2,  KC_ACL1,   KC_ACL0,    __x__,                KC_BTN3,    MC_CUT,     MC_COPY,    MC_PASTE,    KC_ENT,
                                             KC_TRNS, KC_ACL1, KC_BTN1, KC_DEL
  ),


};


//Tap dance macros
void layer_num_fun_finish(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            layer_move(NUM);
            break;
        case 2:
            layer_move(FUN);
            break;
        default:
            layer_move(MSE);
            break;
    }
}


void layer_num_fun_reset(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            layer_off(NUM);
            break;
        case 2:
            layer_off(FUN);
            break;
        default:
            layer_off(MSE);
            break;
    }
}


// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_NUM_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, layer_num_fun_finish, layer_num_fun_reset)
};



//Keyoverride implementation
const key_override_t pdot_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_PDOT, KC_EQL);  // Shift P. is =
const key_override_t psls_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_PSLS, KC_BSLS);  // Shift P/ is bsls
const key_override_t astr_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_ASTR, KC_PIPE);  // Shift P* is pipe
const key_override_t eight_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_QUOT); // Shift 8 is '
const key_override_t nine_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_DQUO);  // Shift 9 is "



// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &pdot_key_override,
    &psls_key_override,
    &astr_key_override,
    &eight_key_override,
    &nine_key_override,
    NULL    // Null terminate the array of overrides!
};




bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case MO_NAV:
	  case TO_MSE:
	  case TO_BSE:
  	case TO_NAV:
	  case TO_NUM:
    case TD(TD_NUM_SYM):
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case MO_NAV:
  	case TO_MSE:
  	case TO_BSE:
  	case TO_NAV:
  	case TO_NUM:
    case TD(TD_NUM_SYM):
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

    //Clear all active layer then momentarily activate NAV layer            
        case MC_NAV:
            if (record->event.pressed) {
                layer_clear();
                layer_on(NAV);
            } else {
                unregister_code(KC_TAB);
                layer_off(NAV);
            }
            return false;
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

    if (get_highest_layer(state) == FUN && get_oneshot_mods()) {
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
/*
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
  if (get_highest_layer(layer_state) == MSEL) {
    if (last_input_activity_elapsed() > LAYER_TIMEOUT) {
      layer_off(MSEL);    // Turnoff Number layer Lock
    }
  }

}
*/
// Uncomment also the #define LAYER_TIMEOUT 60000 above 




