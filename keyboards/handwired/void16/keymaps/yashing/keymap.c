// Copyright 2023 Harold (@har-si)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


#define MC_COPY C(KC_C)
#define MC_PASTE C(KC_V)
#define MC_UNDO C(KC_Z)
#define MC_ITAL C(KC_I)
#define MC_SAVE C(KC_S)
#define MC_EXIT A(KC_F4)
#define MC_1 C(KC_F14)
#define MC_2 C(KC_F15)
#define MC_3 C(KC_F16)
#define MC_4 C(KC_F17)
#define MC_5 C(KC_F18)
#define MC_6 C(KC_F19)
#define MC_7 C(KC_F20)
#define MC_8 C(KC_F21)
#define MC_9 C(KC_F22)
#define MC_10 C(KC_F23)
#define MC_11 C(KC_F24)
#define TO_RGB TO(_RGB)
#define TO_BASE TO(_BASE)

#define LAYER_TIMEOUT 15000  //configure your timeout in milliseconds

bool is_alt_tab_active = false; //Special Alt+Tab



enum layers {
    _BASE,
    _RGB
};


enum keycodes {
    EXLPASTE = SAFE_RANGE,
    NOCOLOR,
    FONTUP,
    FONTDN,
    ALTTAB,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_4x4(
        TO_RGB,     MC_EXIT,     MC_UNDO,     KC_BSPC,
        MC_SAVE,    FONTUP,      FONTDN,      NOCOLOR,
        MC_COPY,    MC_PASTE,    EXLPASTE,    MC_ITAL,
        MC_1,       MC_2,        MC_3,        ALTTAB
    ),

    [_RGB] = LAYOUT_ortho_4x4(
        TO_BASE,   RGB_MOD,    RGB_SAI,   RGB_HUI,
        RGB_TOG,   RGB_RMOD,   RGB_SAD,   RGB_HUD,
        MC_4,      MC_5,       MC_6,      MC_7,
        MC_8,      MC_9,       MC_10,     MC_11
    ),

};




//Macro for excel paste special-values
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case EXLPASTE:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("esv") "\n");
        }
        return false;


    case ALTTAB:
        if (record->event.pressed) {
            is_alt_tab_active = true;
            register_code16(KC_LALT);
            register_code16(KC_TAB);
            unregister_code16(KC_TAB);
        } else {
            unregister_code16(KC_LALT);
            is_alt_tab_active = false;
        }
        return false;


    case FONTDN:
        if (record->event.pressed) {
            if (is_alt_tab_active){
                SEND_STRING(SS_TAP(X_DOWN));
            } else{
                SEND_STRING(SS_LALT("hfk"));
            }
        }
        return false;


    case FONTUP:
        if (record->event.pressed) {
            if (is_alt_tab_active){
                SEND_STRING(SS_TAP(X_LEFT));
            } else{
                SEND_STRING(SS_LALT("hfg"));
            }
        }
        return false;


    case NOCOLOR:
        if (record->event.pressed) {
            if (is_alt_tab_active){
                SEND_STRING(SS_TAP(X_RGHT));
            } else{
                SEND_STRING(SS_LALT("hhn"));
            }
        }
        return false;


    case MC_UNDO:
        if (record->event.pressed) {
            if (is_alt_tab_active){
                SEND_STRING(SS_TAP(X_UP));
                return false;
            } else{
                return true;
            }
        } else{
            return true;
        }

    }
    return true;
};



//Prevent encoder debouncing
static fast_timer_t last_encoding_time = 0;
static const fast_timer_t ENCODER_DEBOUNCE = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {

    if (TIMER_DIFF_FAST(timer_read_fast(), last_encoding_time) >= ENCODER_DEBOUNCE) {
        last_encoding_time = timer_read_fast();
    }
    else {
        return false;
    }


    if (index == 0) { /* First encoder */
        if (get_highest_layer(layer_state) == _BASE){
            if (clockwise) {
                register_code(KC_LCTL);
                tap_code_delay(KC_WH_U, 10);
                unregister_code(KC_LCTL);
            } else {
                register_code(KC_LCTL);
                tap_code_delay(KC_WH_D, 10);
                unregister_code(KC_LCTL);
            }
        } else if (get_highest_layer(layer_state) == _RGB){
            if (clockwise) {
                rgblight_increase_val();
            } else {
                rgblight_decrease_val();
            }
        }
    }
    return false;
}




//Timer for TO layers (locking layers). TO layer will deactivate after lapse of specific time without activity.

void matrix_scan_user(void) {
  if (get_highest_layer(layer_state) == _RGB) {
    if (last_input_activity_elapsed() > LAYER_TIMEOUT) {
      layer_off(_RGB);     // Turnoff RGB Layer Lock
    }
  }

}


