#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  _BL,
  _FL
};

// https://docs.qmk.fm/#/feature_macros?id=using-macros-in-c-keymaps
enum custom_keycodes {
    CUSTOM_MACRO_0 = SAFE_RANGE,
    CUSTOM_MACRO_1,
    CUSTOM_MACRO_2,
};

// macro definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CUSTOM_MACRO_0:
        if (record->event.pressed) {
            // macro key pressed
            SEND_STRING("colton.padden@fastmail.com");
        } else {
            // macro key released
        }
        break;

    case CUSTOM_MACRO_1:
        if (record->event.pressed) {
            // macro key pressed
            SEND_STRING("The quick brown fox jumped over the lazy dog...");
        } else {
            // macro key released
        }
        break;

    case CUSTOM_MACRO_2:
        if (record->event.pressed) {
            // macro key pressed
        } else {
            // macro key released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = | Backsp|
   * |-----------------------------------------------------------|
   * | Tab | Q | W | E | R | T | Y | U | I | O | P | [ | ] |  \  |
   * |-----------------------------------------------------------|
   * | Caps  | A | S | D | F | G | H | J | K | L | ; | ' | Enter |
   * |-----------------------------------------------------------|
   * | Shift  | Z | X | C | V | B | N | M | , | . | / |    Shift |
   * |-----------------------------------------------------------|
   * |Ctrl|GUI |Alt |         Space         | Alt| GUI| Fn | Ctrl|
   * `-----------------------------------------------------------'
   */
  [_BL] = LAYOUT_60_ansi(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, MO(_FL), KC_RCTL
  ),

  /* Keymap _FL: Function Layer
   */
  [_FL] = LAYOUT_60_ansi(
    KC_GRV,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, RESET,
    CUSTOM_MACRO_0, _______, KC_UP, _______, _______, KC_HOME, KC_PAGE_UP, KC_PRINT_SCREEN, KC_SCROLL_LOCK, KC_PAUSE, KC_UP, BL_DEC,  BL_INC,  BL_TOGG,
    CUSTOM_MACRO_1, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DELETE, KC_END, KC_PAGE_DOWN, _______, KC_INSERT, KC_LEFT, KC_DOWN, KC_RIGHT, _______,
    CUSTOM_MACRO_2, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_AUDIO_MUTE, _______, _______, _______, KC_MENU,          _______,
    _______, _______, _______, KC_SPC, _______, _______, _______, _______
  )
};
