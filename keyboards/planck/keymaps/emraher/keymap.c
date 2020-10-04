/* Copyright 2015-2017 Jack Humbert
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


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTION
};

enum custom_keycodes {
    MY_ARROW = SAFE_RANGE,
    MY_PIPE,
    MY_URL
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define PSCR1    LGUI(LSFT(KC_3))       // Print screen on OSX - Save to desktop
#define PSCR2    LGUI(LSFT(KC_4))       // Print screen on OSX with bounding box - Save to desktop
#define PSCR3    LGUI(LSFT(LCTL(KC_3))) // Print screen on OSX
#define PSCR4    LGUI(LSFT(LCTL(KC_4))) // Print screen on OSX with bounding box
#define MOF MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | HYPR |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | FUNC | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    HYPR_T(KC_ESC) , KC_Q    , KC_W    , KC_E    , KC_R  , KC_T   , KC_Y   , KC_U  , KC_I           , KC_O           , KC_P         , KC_BSPC        ,
    CTL_T(KC_TAB)  , KC_A    , KC_S    , KC_D    , KC_F  , KC_G   , KC_H   , KC_J  , KC_K           , KC_L           , KC_SCLN      , KC_QUOT        ,
    KC_LSFT        , KC_Z    , KC_X    , KC_C    , KC_V  , KC_B   , KC_N   , KC_M  , KC_COMM        , KC_DOT         , KC_SLSH      , RSFT_T(KC_ENT) ,
    MOF            , KC_LCTL , KC_LALT , KC_LGUI , LOWER , KC_SPC , KC_SPC , RAISE , GUI_T(KC_LEFT) , ALT_T(KC_DOWN) , CTL_T(KC_UP) , KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7       , KC_8       , KC_9    , KC_0    , KC_BSPC ,
    KC_DEL  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_UNDS    , KC_PLUS    , KC_LCBR , KC_RCBR , KC_PIPE ,
    _______ , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , S(KC_NUHS) , S(KC_NUBS) , KC_HOME , KC_END  , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______    , KC_MNXT    , KC_VOLD , KC_VOLU , KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_BSPC  ,
    KC_DEL  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS  ,
    _______ , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_NUHS , KC_NUBS , KC_PGUP , KC_PGDN , _______  ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MNXT , KC_VOLD , KC_VOLU , KC_MPLY	
),

/* FUNCTION
 * ,-----------------------------------------------------------------------------------.
 * |      | url  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | arw  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | pipe |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------' */
[_FUNCTION] = LAYOUT_planck_grid(
    _______ , MY_URL , _______,  _______, _______, _______, _______, _______ , _______, _______, _______, _______,
    _______ , _______, _______,  _______, _______, _______, _______, MY_ARROW, _______, _______, _______, _______,
    _______ , _______, _______,  _______, _______, _______, _______, MY_PIPE , _______, _______, _______, _______,
    _______ , _______, _______,  _______, _______, _______, _______, _______ , _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |PSCR1 |PSCR2 |PSCR3 |PSCR4 |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset | Debug|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, PSCR1  , PSCR2  , PSCR3  , PSCR4  , _______, _______, _______, _______, _______, _______, _______,
    RESET  , DEBUG  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};



layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MY_ARROW:
        if (record->event.pressed) {
            SEND_STRING(" <- ");
        }
        break;

    case MY_PIPE:
        if (record->event.pressed) {
            SEND_STRING(" %>% ");
        }
        break;

    case MY_URL:
        if (record->event.pressed) {
           SEND_STRING("eremrah.com"); 
        }
        break;
    }
    return true;
};

