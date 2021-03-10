#include QMK_KEYBOARD_H

#include "transport.h"

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef SSD1306OLED
#include "ssd1306.h"
#endif

char wpm_str[10];
char debug_string[6];

#define _QGMLWY 0
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

enum custom_keycodes {
  QGMLWY = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  ADJUST,
  LAYOUT,
  VER_R,
  VER_L,
};

enum custom_maps {
  MAP_DEF = 0,
  MAP_LOW,
  MAP_RAI,
  MAP_ADJ,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QGMLWY (pretend this shows the right letters)
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |   ~  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|  Play |    | Enter |------+------+------+------+------+------|
   * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *                   | LGUI | LAlt | Space| /LOWER  /       \RAISE \  |BackSP| DEL  |ADJUST|
   *                   |      |      |      |/       /         \      \ |      |      |      |
   *                   `----------------------------'           '------''--------------------'
   */

  [_QGMLWY] = LAYOUT( \
      KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
      KC_TAB,   KC_Q,   KC_G,    KC_M,    KC_L,    KC_W,                     KC_Y,    KC_F,    KC_U,    KC_B,    KC_SCLN, KC_BSLS, \
      KC_LCTRL, KC_D,   KC_S,    KC_T,    KC_N,    KC_R,                     KC_I,    KC_A,    KC_E,    KC_O,    KC_H,    KC_QUOT, \
      KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_J, KC_MPLY,  KC_ENT,   KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
      KC_LGUI, KC_LALT, KC_SPC,  LOWER,                    RAISE,   KC_BSPC, KC_DEL,  ADJUST \
                      ),

  /* QWERTY
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
   * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
   *                   |      |      |      |/       /         \      \ |      |      |      |
   *                   `----------------------------'           '------''--------------------'
   */

  [_QWERTY] = LAYOUT( \
      _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, \
      _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, \
      _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, \
      _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______,  _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______, \
      _______, _______, _______, _______,                  _______, _______, _______, _______ \
                      ),
  /* LOWER
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |      |      |      |      |      | F12  |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |   `  |   !  |   @  |   #  |   (  |   {  |-------.    ,-------|   }  |   )  |   -  |      |      |      |
   * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
   * |      |      |      |      |   [  |      |-------|    |-------|      |   ]  |   _  |      |      |      |
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
   *                   |      |      |      |/       /         \      \ |      |      |      |
   *                   `----------------------------'           '------''--------------------'
   */
  [_LOWER] = LAYOUT( \
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
      _______, _______, _______, _______, KC_LCBR, _______,                   _______, KC_RCBR, KC_UNDS, KC_PLUS, _______, KC_F12, \
      _______, _______, _______, _______, KC_LPRN, KC_LBRC,                   KC_RBRC, KC_RPRN, KC_MINS, KC_EQL,  _______, _______, \
      _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, \
      _______, _______, _______, _______,                   LAYOUT, _______, _______, XXXXXXX\
                     ),
  /* RAISE
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
   * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
   * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
   *                   |      |      |      |/       /         \      \ |      |      |      |
   *                   `----------------------------'           '------''--------------------'
   */

  [_RAISE] = LAYOUT( \
      _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
      _______, _______, _______,  LAYOUT, _______,  _______, _______, XXXXXXX \
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
   *                   |NotMac| Mac  |LOWER | /Space  /       \Enter \  |RAISE |      |Adjust|
   *                   | Swap | Swap |       /       /         \      \ |      |      |      |
   *                   `----------------------------'           '------''--------------------'
   */
  [_ADJUST] = LAYOUT( \
      VER_L,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, VER_R, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
      LAG_NRM, LAG_SWP, _______, XXXXXXX,                   XXXXXXX,  _______, _______, _______ \
                      )
};

void matrix_init_user(void) {

}

void encoder_update_user(uint8_t index, bool clockwise) {
  snprintf(debug_string, sizeof(debug_string), "none");
  if (index == 0) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_270;
  else
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
}


// WPM-responsive animation stuff here
#define IDLE_FRAMES 5
#define IDLE_SPEED 40 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_FRAMES 2
#define TAP_SPEED 60 // above this wpm value typing animation to triggere

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#define ANIM_SIZE 96 // number of bytes in array, max is 1024
#define TAP_SIZE 128 // the tapping frames are a row taller so they need to be bigger

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;
bool was_tapping = false;

// Images credit j-inc(/James Incandenza) and pixelbenny. Credit to obosob for initial animation approach.
static void render_anim(void) {
  static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {
    {0,192, 32, 32, 64,128,128, 64, 64, 32, 32, 32, 16, 16,  8,  8,  8,  4,  2,  1,  1,  2, 12, 16, 32, 64,128,  0,  0,  0,  0,  0,  0, 15,240,  0,  0,  0,  0,  0,192,192,192, 24, 24,  0, 32, 32, 32,144,144,152,131,131,128,140,140, 12,  0,  1,  2,  4, 24,224, 28, 19,  8,  8,  8,  8,  8, 16, 32, 32, 64, 64, 64, 66, 61,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  2,  2,  2,  2,  1,},
    {0,  0,128, 64, 64,128,128, 64, 64, 32, 32, 32, 16, 16,  8,  8,  8,  4,  2,  2,  2,  2, 12, 16, 32, 64,128,  0,  0,  0,  0,  0,  0,  7,248,  0,  0,  0,  0,  0,192,192,192, 24, 24,  0, 32, 32, 32,144,144,152,131,131,128,140,140, 12,  0,  1,  2,  4, 24,224, 28, 19,  8,  8,  8,  8,  8, 16, 32, 32, 64, 64, 64, 66, 61,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  2,  2,  2,  2,  1,},
    {0,  0,  0,128,128,128,128, 64, 64, 32, 32, 32, 16, 16,  8,  8,  8,  4,  4,  2,  2,  4,  8, 16, 32, 64,128,  0,  0,  0,  0,  0,  0,198, 57,  0,  0,  0,  0,  0,192,192,192, 24, 24,  0, 32, 32, 32,144,144,152,131,131,128,140,140, 12,  0,  1,  2,  4, 24,224, 30, 17,  8,  8,  8,  8,  8, 16, 32, 32, 64, 64, 64, 66, 61,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  2,  2,  2,  2,  1,},
    {0,  0,  0,128,128,128,128, 64, 64, 32, 32, 32, 16, 16,  8,  8,  8,  4,  4,  2,  2,  4,  8, 16, 32, 64,128,  0,  0,  0,  0,  0,  0,198, 57,  0,  0,  0,  0,  0,192,192,192, 24, 24,  0, 32, 32, 32,144,144,152,131,131,128,140,140, 12,  0,  1,  2,  4, 24,224, 30, 17,  8,  8,  8,  8,  8, 16, 32, 32, 64, 64, 64, 66, 61,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  2,  2,  2,  2,  1,},
    {0,128, 64, 64,128,  0,  0,128,128, 64, 64, 64, 32, 32, 16, 16, 16,  8,  4,  2,  2,  4, 24, 32, 64,128,  0,  0,  0,  0,  0,  0,  0, 31,224,  0,  0,  1,  1,  0,128,128,128, 48, 48,  0, 64, 64, 64, 32,160,176,134,134,128,152,152, 24,  1,  2,  4,  8, 16,224, 24, 30,  9,  8,  8,  8,  8, 16, 33, 33, 65, 64, 64, 66, 61,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  1,  1,  2,  2,  2,  2,  1,}
  };
  static const char PROGMEM prep[][ANIM_SIZE] = {
    {0,192, 32, 32, 64,128,128, 64, 64, 32, 32, 32, 16, 16,  8,  8,  8,  4,  2,  1,  1,  2, 12, 16, 32, 64,128, 64, 64, 64,128,  0,  0, 15,240,  0,  0,192, 32, 16, 16, 96,128, 24, 24,  0, 32, 32, 32,144,144,152,131,131,128,128,128,156,131,128, 64, 64, 48, 47, 28, 19,  8,  8,  8,  8,  8,  4,  4,  4,  3,  2,  2,  2,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,}
  };
  static const char PROGMEM tap[TAP_FRAMES][TAP_SIZE] = {
    {0,192, 32, 32, 64,128,128, 64, 64, 32, 32, 32, 16, 16,  8,  8,  8,  4,  2,  1,  1,  2, 12, 16, 32, 64,128, 64, 64, 64,128,  0,  0, 15,240,  0,  0,  0,  0,  0,  0,  0,  0, 24, 24,  0, 32, 32, 32,144,144,152,131,131,128,128,128,156,131,128, 64, 64, 48, 47, 28, 19,  8,  8,  8,  8,  8, 16, 32, 32, 64, 64, 64, 66, 61,  1, 97, 96,224,224,224,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8, 12, 30, 63, 63, 63,  0,  0,  0,  0,  6, 30, 62, 60, 24,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,},
    {0,192, 32, 32, 64,128,128, 64, 64, 32, 32, 32, 16, 16,  8,  8,  8,  4,  2,  1,  1,  2, 12, 16, 32, 64,128,  0,  0,  0,  0,  0,  0, 15,240,  0,  0,192, 32, 16, 16, 96,128, 24, 24,  0, 32, 32, 32,144,144,152,131,131,128,128,128,  0,  0,  1,  2,  4, 24,224, 28, 19,  8,  8,  8,  8,  8,  4,  4,  4,  3,  2,  2,  1,  1,  1,  1,  0,  0,  6, 14,142,204,236,236,225,225,  2,130,194,226,241,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  1,  0,  0,  7,  7, 15, 15,},
  };

  //assumes 1 frame prep stages
  void animation_phase(void) {
    if(get_current_wpm() <=IDLE_SPEED){
      current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
      oled_write_raw_P(idle[abs((IDLE_FRAMES-1)-current_idle_frame)], ANIM_SIZE);
    }
    if(get_current_wpm() >IDLE_SPEED && get_current_wpm() <TAP_SPEED){
      // oled_write_raw_P(prep[abs((PREP_FRAMES-1)-current_prep_frame)], ANIM_SIZE); // uncomment if IDLE_FRAMES >1
      oled_write_raw_P(prep[0], ANIM_SIZE);  // remove if IDLE_FRAMES >1

      if (was_tapping) {
        for (uint16_t i = ANIM_SIZE; i < TAP_SIZE; i++) {
          oled_write_raw_byte(0, i);
        }
        was_tapping = false;
      }
    }
    if(get_current_wpm() >=TAP_SPEED){
      current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
      oled_write_raw_P(tap[abs((TAP_FRAMES-1)-current_tap_frame)], TAP_SIZE);
      was_tapping = true;
    }
  }

  if(get_current_wpm() != 000) {
    //oled_on(); // not essential but turns on animation OLED with any alpha keypress
    if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
      anim_timer = timer_read32();
      animation_phase();
    }
    anim_sleep = timer_read32();
  } else {
    if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
      oled_off();
    } else {
      if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animation_phase();
      }
    }
  }
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

const char *read_mode_icon(bool swap);
const char *read_host_led_state(void);
void set_timelog(void);
const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    //oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false);
    if (keymap_config.swap_lalt_lgui)
      oled_write_ln("Mac", false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
    oled_write_ln(debug_string, false);

    oled_set_cursor(0,13);
    switch (split_layerinfo) {
      case MAP_DEF:
        oled_write("     "
                   "     "
                   "     ", false);
        break;
      case MAP_LOW:
        oled_write("...{."
                   "...(["
                   ".....", false);
        break;
      case MAP_RAI:
        oled_write("....."
                   "....."
                   ".....", false);
        break;
      case MAP_ADJ:
        oled_write("s:Win"
                   "M:Mac"
                   "     ", false);
        break;
    }
  } else {
    render_anim();

    oled_set_cursor(0,5);
    sprintf(wpm_str, "WPM: %03d", get_current_wpm());
    oled_write_ln(wpm_str, false);

    oled_set_cursor(0,13);
    switch (split_layerinfo) {
      case MAP_DEF:
        oled_write("     "
                   "     "
                   "     ", false);
        break;
      case MAP_LOW:
        oled_write(".}_+."
                   "])-=."
                   ".....", false);
        break;
      case MAP_RAI:
        oled_write("....."
                   ".<v^>"
                   ".....", false);
        break;
      case MAP_ADJ:
        oled_write("     "
                   "     "
                   "     ", false);
        break;
    }
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    //set_keylog(keycode, record);
    //set_timelog();
#endif
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LAYOUT:
      if (record->event.pressed) {
        if (biton32(default_layer_state) == _QGMLWY) {
          set_single_persistent_default_layer(_QWERTY);
        } else if (biton32(default_layer_state) == _QWERTY) {
          set_single_persistent_default_layer(_QGMLWY);
        }
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        split_layerinfo = MAP_LOW;
        layer_on(_LOWER);
      } else {
        split_layerinfo = MAP_DEF;
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        split_layerinfo = MAP_RAI;
        layer_on(_RAISE);
      } else {
        split_layerinfo = MAP_DEF;
        layer_off(_RAISE);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        split_layerinfo = MAP_ADJ;
        layer_on(_ADJUST);
      } else {
        split_layerinfo = MAP_DEF;
        layer_off(_ADJUST);
      }
      return false;
      break;
    case VER_R:
    case VER_L:
      if (record->event.pressed) {
        SEND_STRING("21/03/10, Display layer maps on right OLED");
      }
  }
  return true;
}
