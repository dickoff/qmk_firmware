#include QMK_KEYBOARD_H

enum custom_keycodes {
  WEBEX_MIC_TOGGLE = SAFE_RANGE,
  WEBEX_VIDEO_TOGGLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    LAYOUT(
        KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_MEDIA_PLAY_PAUSE, WEBEX_MIC_TOGGLE, WEBEX_VIDEO_TOGGLE, TO(1)),

    LAYOUT(
        KC_1,  KC_NO, KC_NO, KC_NO, KC_NO, TO(0)),

    LAYOUT(
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

    LAYOUT(
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO) };


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case WEBEX_MIC_TOGGLE:  // Toggles mic in Webex 
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_LGUI("m")));
      }
      return false;
    case WEBEX_VIDEO_TOGGLE:  // Toggles Video in Webex
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT("v")));
      }
      return false;
  }
  return true;
}
