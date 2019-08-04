#include "keymap.h"

#define HUE_STEP 45
#define SAT_STEP 51
#define VAL_STEP 51
#define LAYER_FLASH_MODE 23
#define LAYER_FLASH_LEN 500

#define RAW_RGB(enabled, mode, hue, sat, val) ((enabled) \
                                               + ((mode) << 1) \
                                               + ((hue) << 7) \
                                               + (((uint32_t)(sat)) << 16) \
                                               + (((uint32_t)(val)) << 24))

#define NUM_LOCK_GLOW RAW_RGB(1, 1, 120, 255, 0)
#define CAPS_LOCK_GLOW RAW_RGB(1, 1, 0, 255, 0)
#define BOTH_LOCK_GLOW RAW_RGB(1, 1, 60, 255, 0)
#define DEFAULT_GLOW RAW_RGB(1, 14, 270, 255, 255)

#define NUM_ACTIVE(led_int) ((led_int) & (1 << USB_LED_NUM_LOCK))
#define CAP_ACTIVE(led_int) ((led_int) & (1 << USB_LED_CAPS_LOCK))

#define ___X___ KC_NO    // Disabled keys
#define ___E___ KC_NO    // Nonexistent keys
#define _CURMOD KC_TRNS  // Active modifier

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer 0: Default Layer (QGMLWY)
   * ,-----------------------------------------------------------.
   * | ~ |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Num|Cap|
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  G|  M|  L|  W|  Y|  F|  U|  B|  ;|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |Bksp  |  D|  S|  T|  N|  R|  I|  A|  E|  O|  H|  '|  Return|
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  J|  K|  P|  ,|  .|  /| Shift|Lyr|
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |   Space  | Fn1|  Del  | Alt| Fn2| FN3| Ctrl|
   * `-----------------------------------------------------------'
   */

  [L_QG] = LAYOUT(
  /*  Tilde    1        2        3        4        5        6        7        8        9        0        Minus    Equal    NumLock  ScrLck   */
      KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NLCK, KC_CAPS,
  /*  Tab      Q        W        E        R        T        Y        U        I        O        P        LBrack   RBrack            Backslsh */
      KC_TAB,  KC_Q,    KC_G,    KC_M,    KC_L,    KC_W,    KC_Y,    KC_F,    KC_U,    KC_B,    KC_SCLN, KC_LBRC, KC_RBRC,          KC_BSLS,
  /*  CapsLck  A        S        D        F        G        H        J        K        L        Semicln  Quote                      Enter    */
      KC_BSPC, KC_D,    KC_S,    KC_T,    KC_N,    KC_R,    KC_I,    KC_A,    KC_E,    KC_O,    KC_H,    KC_QUOT,                   KC_ENT,
  /*  Shift             Z        X        C        V        B        N        M        Comma    Period   Slash             Shift    App      */
      KC_LSFT, ___E___, KC_Z,    KC_X,    KC_C,    KC_V,    KC_J,    KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, DZ_CYCL,
  /*  Control  Win      Alt      Space             Fn                Delete                     Alt      Fn                Menu     Control  */
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,           MO(L_TH),         KC_DEL,                    KC_RALT, MO(L_FN),___E___, MO(L_RG),KC_RCTL),

  /* Layer 1: QWERTY Layer
   * ,-----------------------------------------------------------.
   * |Esc|   |   |   |   |   |   |   |   |   |   |   |   |   |Bsp|
   * |-----------------------------------------------------------|
   * |     |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|   |   |     |
   * |-----------------------------------------------------------|
   * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|   |        |
   * |-----------------------------------------------------------|
   * |        |  Z|  X|  C|  V|  B|  N|  M|   |   |   |      |   |
   * |-----------------------------------------------------------|
   * |    |    |    |          |    |       |    |    |    |     |
   * `-----------------------------------------------------------'
   */

  [L_QW] = LAYOUT(
  /*  Tilde    1        2        3        4        5        6        7        8        9        0        Minus    Equal    NumLock  ScrLck   */
      KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC,
  /*  Tab      Q        W        E        R        T        Y        U        I        O        P        LBrack   RBrack            Backslsh */
      _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, _______,          _______,
  /*  CapsLck  A        S        D        F        G        H        J        K        L        Semicln  Quote                      Enter    */
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,                   _______,
  /*  Shift             Z        X        C        V        B        N        M        Comma    Period   Slash             Shift    App      */
      _______, ___E___, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    _______, _______, _______,          _______, _______,
  /*  Control  Win      Alt      Space             Fn                Delete                     Alt      Fn                Menu     Control  */
      _______, _______, _______, _______,          _______,          _______,                   _______, _______, ___E___, _______, _______),

  /* Layer 2: Numpad
   * ,-----------------------------------------------------------.
   * |   |   |   |   |   |   |   | 7 | 8 | 9 |   |   |   |XXX|   |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   | 4 | 5 | 6 |   |   |   |     |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   | 1 | 2 | 3 |   |   |KP Enter|
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   | 0 |   |Dot|   |      |   |
   * |-----------------------------------------------------------|
   * |    |    |    |          |    |       |    |    |    |     |
   * `-----------------------------------------------------------'
   */

  [L_NM] = LAYOUT(
  /*  Tilde    1        2        3        4        5        6        7        8        9        0        Minus    Equal    NumLock  ScrLck   */
      ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_P7,   KC_P7,   KC_P7,   ___X___, ___X___, ___X___, _CURMOD, _______,
  /*  Tab      Q        W        E        R        T        Y        U        I        O        P        LBrack   RBrack            Backslsh */
      _______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_P4,   KC_P5,   KC_P6,   ___X___, ___X___, ___X___,          ___X___,
  /*  CapsLck  A        S        D        F        G        H        J        K        L        Semicln  Quote                      Enter    */
      _______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_P1,   KC_P2,   KC_P3,   ___X___, ___X___,                    KC_ENT,
  /*  Shift             Z        X        C        V        B        N        M        Comma    Period   Slash             Shift    App      */
      _______, ___E___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_P0,   ___X___, KC_PDOT, ___X___,          _______, ___X___,
  /*  Control  Win      Alt      Space             Fn                Delete                     Alt      Fn                Menu     Control  */
      _______, _______, _______, _______,          ___X___,                   _______,          _______, ___X___, ___E___, ___X___, _______),

  /* Layer 3: Thumb-Function Layer
   * ,-----------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |      |HOM|PDN|PUP|PED|   |   | < | V | ^ | > |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |      |   |
   * |-----------------------------------------------------------|
   * |    |    |    |          | XX |       |    |    |    |     |
   * `-----------------------------------------------------------'
   */

  [L_TH] = LAYOUT(
  /*  Tilde    1        2        3        4        5        6        7        8        9        0        Minus    Equal    NumLock  ScrLck   */
      _______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
  /*  Tab      Q        W        E        R        T        Y        U        I        O        P        LBrack   RBrack            Backslsh */
      _______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___,
  /*  CapsLck  A        S        D        F        G        H        J        K        L        Semicln  Quote                      Enter    */
      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  ___X___, ___X___, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ___X___,                   ___X___,
  /*  Shift             Z        X        C        V        B        N        M        Comma    Period   Slash             Shift    App      */
      _______, ___E___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          _______, ___X___,
  /*  Control  Win      Alt      Space             Fn                Delete                     Alt      Fn                Menu     Control  */
      _______, _______, _______, _______,          _CURMOD,                   _______,          _______, XXXXXXX, ___E___, XXXXXXX, _______),

  /* Layer 4: Multi-Hand Function Layer
   * ,-----------------------------------------------------------.
   * | ~ | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Pdn|Pup|
   * |-----------------------------------------------------------|
   * |     | <<| P | >>|   |   |   |   | ^ |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |      | V-| M | V+|   |   |   | < | v | > |   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |      |   |
   * |-----------------------------------------------------------|
   * |    |    |    |          |    |       |    | XX |    |     |
   * `-----------------------------------------------------------'
   */

  [L_FN] = LAYOUT(
  /*  Tilde    1        2        3        4        5        6        7        8        9        0        Minus    Equal    NumLock  ScrLck   */
      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PGDN, KC_PGUP,
  /*  Tab      Q        W        E        R        T        Y        U        I        O        P        LBrack   RBrack            Backslsh */
      _______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_UP,   ___X___, ___X___, KC_VOLD, KC_VOLU,          KC_MUTE,
  /*  CapsLck  A        S        D        F        G        H        J        K        L        Semicln  Quote                      Enter    */
      _______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_LEFT, KC_DOWN, KC_RGHT, ___X___, ___X___,                   ___X___,
  /*  Shift             Z        X        C        V        B        N        M        Comma    Period   Slash             Shift    App      */
      _______, ___E___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_MPRV, KC_MNXT, KC_MPLY,          _______, ___X___,
  /*  Control  Win      Alt      Space             Fn                Delete                     Alt      Fn                Menu     Control  */
      _______, _______, _______, _______,          _______,                   _______,          _______, _CURMOD, ___E___, XXXXXXX, _______),

  /* Layer 5: RGB/Meta Keyboard Functions
   * ,-----------------------------------------------------------.
   * |TOG|STA|BRT|RMD|SWR|SNK|KIT|XMS|GRD|TST|   |   |   |   |RST|
   * |-----------------------------------------------------------|
   * |     |-HU|+HU|   |   |   |   |   |   |   |   |-MD|+MD|     |
   * |-----------------------------------------------------------|
   * |      |-SA|+SA|   |   |   |   |   |   |   |   |   |   DEBUG|
   * |-----------------------------------------------------------|
   * |        |-VA|+VA|   |   |   |   |   |   |   |   |      |   |
   * |-----------------------------------------------------------|
   * |Info|    |    |          |    |       |    |    | XX |     |
   * `-----------------------------------------------------------'
   */

  [L_RG] = LAYOUT(
  /*  Tilde    1        2        3        4        5        6        7        8        9        0        Minus    Equal    NumLock  ScrLck   */
      RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, ___X___, ___X___, ___X___, XXXXXXX, ___X___,
  /*  Tab      Q        W        E        R        T        Y        U        I        O        P        LBrack   RBrack            Backslsh */
      DZ_HU_D, RGB_HUD, RGB_HUI, DZ_HU_I, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, RGB_RMOD,RGB_MOD,          ___X___,
  /*  CapsLck  A        S        D        F        G        H        J        K        L        Semicln  Quote                      Enter    */
      DZ_SA_D, RGB_SAD, RGB_SAI, DZ_SA_I, ___X___, ___X___, ___X___, ___X___, RESET,   ___X___, ___X___, ___X___,                   DZ_DBUG,
  /*  Shift             Z        X        C        V        B        N        M        Comma    Period   Slash             Shift    App      */
      DZ_VA_D, ___E___, RGB_VAD, RGB_VAI, DZ_VA_I, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___, CURR_LR,
  /*  Control  Win      Alt      Space             Fn                Delete                     Alt      Fn                Menu     Control  */
      DZ_VERS, ___X___, ___X___, ___X___,          _______,                   ___X___,          ___X___, XXXXXXX, ___E___, _CURMOD, ___X___),
};

// Sets the underglow into a temporary mode for duration milliseconds
static void flashGlow(uint8_t mode, uint16_t hue, uint16_t duration);

// Flashes the underglow to show the current active layer
static void indicateLayer(void);

// Sets the underglow into a lock indicator state
static void lockGlow(rgblight_config_t *tempState);

// Sets the current underglow to the given tempState for duration
// milliseconds, or sets it indefinitely if duration is zero
static void setTempGlow(rgblight_config_t *tempState, uint16_t duration);

// Reset the underglow to an existing lock glow or the user's glow
static void restoreGlow(bool fromTimer);

// Sets the lock glow and the numpad layer based on lock leds
static void updateLocks(uint8_t usb_led);

// Original user-set underglow state
rgblight_config_t origGlowState;
// Long-term temp underglow (ie lock lights)
rgblight_config_t prevTempGlowState;

bool isGlowTemp = false;
uint16_t tempGlowDuration = 0;
uint16_t tempGlowStart = 0;
rgblight_config_t rgblight_config;

static void setTempGlow(rgblight_config_t *tempState, uint16_t duration) {
  if (duration != 0) {                     // If this is a flash
    if (isGlowTemp && tempGlowStart == 0)  // And its on top of a lock glow
      prevTempGlowState.raw = rgblight_config.raw;  // Save the lock glow

    tempGlowDuration = duration;
    tempGlowStart = timer_read();
  } else if (tempGlowDuration != 0) {  // If this is a lock glow on a flash
    // Make it restore to this glow state when the flash is done
    prevTempGlowState.raw = tempState->raw;
    return;
  }

  // If the current glow is the user's, save it
  if (!isGlowTemp)
    origGlowState = rgblight_config;

  // If it's off, turn it on to a non-blinding brightness
  if (origGlowState.enable == 0) {
    rgblight_enable();
    tempState->val = 70;
  }

  rgblight_mode(tempState->mode);
  rgblight_sethsv(tempState->hue, tempState->sat, tempState->val);

  isGlowTemp = true;
}

static void flashGlow(uint8_t mode, uint16_t hue, uint16_t duration) {
  rgblight_config_t flash_conf;
  flash_conf.raw = RAW_RGB(1, mode, hue, 255, rgblight_config.val);
  setTempGlow(&flash_conf, duration);
}

static void indicateLayer(void) {
  uint16_t layerHue = 270;
  if (default_layer_state == L_QG + 1) {
    layerHue = 120;
  } else if (default_layer_state == L_QW + 1) {
    layerHue = 0;
  }

  flashGlow(LAYER_FLASH_MODE, layerHue, LAYER_FLASH_LEN);
}

static void lockGlow(rgblight_config_t *tempState) {
  setTempGlow(tempState, 0);
}

static void restoreGlow(bool fromTimer) {
  // If the original state is identical to a lock light (ignoring value),
  // reset to the default so it's clear the lock is off
  if (origGlowState.raw << 8 == NUM_LOCK_GLOW << 8
      || origGlowState.raw << 8 == CAPS_LOCK_GLOW << 8
      || origGlowState.raw << 8 == BOTH_LOCK_GLOW << 8)
    origGlowState.raw = DEFAULT_GLOW;

  rgblight_config_t *restoreState;

  // Restore to a lock light state if there was one
  if (prevTempGlowState.raw != 0 && fromTimer) {
    restoreState = &prevTempGlowState;
  } else {  // Otherwise, restore to the original state
    restoreState = &origGlowState;
    isGlowTemp = false;
  }

  rgblight_mode(restoreState->mode);
  rgblight_sethsv(restoreState->hue, restoreState->sat, restoreState->val);

  if (restoreState->enable == 0)
    rgblight_disable();

  tempGlowDuration = 0;
  tempGlowStart = 0;
  prevTempGlowState.raw = 0;
}

static void updateLocks(uint8_t usb_led) {
  rgblight_config_t newGlowState;

  if (NUM_ACTIVE(usb_led))
    layer_on(L_NM);
  else
    layer_off(L_NM);

  if (NUM_ACTIVE(usb_led) && CAP_ACTIVE(usb_led)) {
    newGlowState.raw = BOTH_LOCK_GLOW;
  } else if (NUM_ACTIVE(usb_led) && !CAP_ACTIVE(usb_led)) {
    newGlowState.raw = NUM_LOCK_GLOW;
  } else if (!NUM_ACTIVE(usb_led) && CAP_ACTIVE(usb_led)) {
    newGlowState.raw = CAPS_LOCK_GLOW;
  } else {
    restoreGlow(false);
    return;
  }

  newGlowState.val = rgblight_config.val;

  lockGlow(&newGlowState);
}

static void stepHue(bool subtract) {
  uint16_t hue = rgblight_config.hue;

  if (subtract) {
    hue -= HUE_STEP;
    if (hue > 359)
      hue = 359;
  } else {
    hue += HUE_STEP;
    if (hue > 359)
      hue = 0;
  }
  rgblight_sethsv(hue, rgblight_config.sat, rgblight_config.val);
}

static uint8_t stepGlow(uint8_t orig, bool subtract, uint8_t amount) {
  if (subtract) {
    if (orig < amount)
      orig = 0;
    else
      orig -= amount;
  } else {
    if ((255 - orig) < amount)
      orig = 255;
    else
      orig += amount;
  }
  return orig;
}

static void stepSat(bool subtract) {
  rgblight_sethsv(rgblight_config.hue,
                  stepGlow(rgblight_config.sat, subtract, SAT_STEP),
                  rgblight_config.val);
}

static void stepVal(bool subtract) {
  rgblight_sethsv(rgblight_config.hue,
                  rgblight_config.sat,
                  stepGlow(rgblight_config.val, subtract, VAL_STEP));
}

void matrix_scan_user() {
  if (tempGlowStart != 0 && timer_elapsed(tempGlowStart) > tempGlowDuration) {
    restoreGlow(true);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed)
    return true;

  switch (keycode) {
    case DZ_HU_D:
      stepHue(true);
      break;
    case DZ_HU_I:
      stepHue(false);
      break;
    case DZ_SA_D:
      stepSat(true);
      break;
    case DZ_SA_I:
      stepSat(false);
      break;
    case DZ_VA_D:
      stepVal(true);
      break;
    case DZ_VA_I:
      stepVal(false);
      break;
    case DZ_QWER:
      set_single_persistent_default_layer(L_QW);
      indicateLayer();
      break;
    case DZ_QGML:
      set_single_persistent_default_layer(L_QG);
      indicateLayer();
      break;
    case DZ_CYCL:
      if (default_layer_state == L_QG + 1) {
        set_single_persistent_default_layer(L_QW);
        indicateLayer();
      } else if (default_layer_state == L_QW + 1) {
        set_single_persistent_default_layer(L_QG);
        indicateLayer();
      }
      break;
    case DZ_VERS:
      SEND_STRING("Current Version: 1.08\n"
                  "Date: 8/03/19\n"
                  "Most Recent Change: Swapped tilde for esc on QWERTY\n");
      break;
    case DZ_DBUG:
      break;
    case CURR_LR:
      indicateLayer();
  }

  return true;
}

uint8_t prevLedState = 0;
void led_set_user(uint8_t usb_led) {
  if (usb_led != prevLedState) { // If a lock is changed
    uint8_t diff = prevLedState ^ usb_led;
    if (NUM_ACTIVE(diff) ||
        CAP_ACTIVE(diff)) {
      updateLocks(usb_led);
    }
    prevLedState = usb_led;
  }
}

void matrix_init_user(void) {
  prevTempGlowState.raw = 0;
}
