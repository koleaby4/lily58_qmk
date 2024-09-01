#include QMK_KEYBOARD_H

#define Copy LCTL(KC_C)
#define Paste LCTL(KC_V)

enum layer_number {
  _QWERTY = 0,
  _L1,
  _L2,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  DEL |  A   |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  # ~  |    |  INS  |------+------+------+------+------+------|
 * |Shft( |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |Shft) |
 * '-----------------------------------------/      /     \       \-----------------------------------------'
 *                   |  Alt | GUI | Ctrl |  / Space /      \ Enter \  | L1 [  | L2 ] |  # ~  |
 *                   '----------------------------'         '----------------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_ESC,       KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,  KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
  KC_TAB,       KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_DEL,       KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,   KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  SC_LSPO,      KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_NUHS,    KC_INS,   KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC, \
                                 KC_LALT, KC_LGUI, KC_LCTL, KC_SPC,     KC_ENT,   LT(_L1, KC_LBRC),LT(_L2, KC_RBRC),  KC_NUHS  \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CAP W |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   [  |  {   |   }  |   ]  |  =   |-------.    ,-------| PGUP | HOME |  🡩  | END  |  -   | ` ~  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| PGDN |  🡠  |  🡣 ️ |  🡢️  |   \   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /      /        \      \  |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_L1] = LAYOUT( \
  _______,    _______, _______,     _______,    _______,    _______,                        _______, _______, _______, _______, _______, KC_F12,  \
  _______,    KC_1,    KC_2,        KC_3,       KC_4,       KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  CW_TOGG,    KC_LBRC, S(KC_LBRC),  S(KC_RBRC), KC_RBRC,    KC_EQL,                         KC_PGUP, KC_HOME, KC_UP  , KC_END,  KC_MINS, KC_GRV,  \
  _______,    _______, _______,     _______,    _______,    _______,    _______,  _______,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NUBS, _______, \
                                                _______,    _______,    _______,  _______,  _______,  _______, _______, _______ \
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /      /        \      \  |      |      |       |
 *                   `----------------------------'           '------''--------------------'
 */

[_L2] = LAYOUT( \
  QK_BOOT, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  KC_CAPS, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, DM_PLY1, DM_REC1, _______, _______, _______, _______, _______, _______,\
                             _______, _______, _______, _______, DM_RSTP,  _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /      /        \      \  |      |      |       |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _L1, _L2, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
