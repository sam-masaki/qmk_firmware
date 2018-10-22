#include "keymap.h"

#define HUE_STEP 45
#define SAT_STEP 51
#define VAL_STEP 51
#define ___X___ KC_NO
#define ___E___ KC_NO
#define _CURMOD KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* Layer 0: Default Layer (QGMLWY)
	* ,-----------------------------------------------------------.
	* |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Num|Cap|
	* |-----------------------------------------------------------|
	* |Tab  |  Q|  G|  M|  L|  W|  Y|  F|  U|  B|  ;|  [|  ]|  \  |
	* |-----------------------------------------------------------|
	* |Bksp  |  D|  S|  T|  N|  R|  I|  A|  E|  O|  H|  '|  Return|
	* |-----------------------------------------------------------|
	* |Shift   |  Z|  X|  C|  V|  J|  K|  P|  ,|  .|  /| Shift|idk|
	* |-----------------------------------------------------------|
	* |Ctrl|Gui |Alt |   Space  | Fn1|  Del  | Alt| Fn2| FN3| Ctrl|
	* `-----------------------------------------------------------'
	*/

[L_QG] = LAYOUT(
	KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NLCK, KC_CAPS,

	KC_TAB,  KC_Q,    KC_G,    KC_M,    KC_L,    KC_W,    KC_Y,    KC_F,    KC_U,    KC_B,    KC_SCLN, KC_LBRC, KC_RBRC,          KC_BSLS,

	KC_BSPC, KC_D,    KC_S,    KC_T,    KC_N,    KC_R,    KC_I,    KC_A,    KC_E,    KC_O,    KC_H,    KC_QUOT,                   KC_ENT,

	KC_LSFT, ___E___, KC_Z,    KC_X,    KC_C,    KC_V,    KC_J,    KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, DZ_CYCL,

	KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,           MO(L_TH),         KC_DEL,                    KC_RALT, MO(L_FN),___E___, MO(L_RG),KC_RCTL),

	/*-----------------------------------------------------------------------------------------------------------------------------------*/

	/* Layer 1: QWERTY Layer
	* ,-----------------------------------------------------------.
	* |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Num|Cap|
	* |-----------------------------------------------------------|
	* |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
	* |-----------------------------------------------------------|
	* |Bksp  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|
	* |-----------------------------------------------------------|
	* |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| Shift|idk|
	* |-----------------------------------------------------------|
	* |Ctrl|Gui |Alt |   Space  | Fn1|  Del  | Alt| Fn2| FN3| Ctrl|
	* `-----------------------------------------------------------'
	*/

[L_QW] = LAYOUT(
	KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NLCK, KC_BSPC,

	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS,

	KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,

	KC_LSFT, ___E___, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, DZ_CYCL,

	KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,           MO(L_TH),         KC_DEL,                    KC_RALT, MO(L_FN),___E___, MO(L_RG),KC_RCTL),

	/*-----------------------------------------------------------------------------------------------------------------------------------*/

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
	_______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_P7,   KC_P7,   KC_P7,   ___X___, ___X___, ___X___, _CURMOD, ___X___,

	_______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_P4,   KC_P5,   KC_P6,   ___X___, ___X___, ___X___,          ___X___,

	_______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_P1,   KC_P2,   KC_P3,   ___X___, ___X___,                    KC_ENT,

	_______, ___E___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_P0,   ___X___, KC_PDOT, ___X___,          _______, ___X___,

	_______, _______, _______, _______,          ___X___,                   _______,          _______, ___X___, ___E___, ___X___, _______),

	/*-----------------------------------------------------------------------------------------------------------------------------------*/

	/* Layer 3: Thumb-Function Layer
	* ,-----------------------------------------------------------.
	* |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
	* |-----------------------------------------------------------|
	* |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
	* |-----------------------------------------------------------|
	* |      |   |   |   |   |   |   | < | V | ^ | > |   |        |
	* |-----------------------------------------------------------|
	* |        |   |   |   |   |   |   |   |   |   |   |      |   |
	* |-----------------------------------------------------------|
	* |    |    |    |          | XX |       |    |    |    |     |
	* `-----------------------------------------------------------'
	*/

[L_TH] = LAYOUT(
	_______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,

	_______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___,

	_______, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ___X___,                   ___X___,

	_______, ___E___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          _______, ___X___,

	_______, _______, _______, _______,          _CURMOD,                   _______,          _______, XXXXXXX, ___E___, XXXXXXX, _______),

	/*-----------------------------------------------------------------------------------------------------------------------------------*/

	/* Layer 4: Multi-Hand Function Layer
	* ,-----------------------------------------------------------.
	* | ~ | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |   |
	* |-----------------------------------------------------------|
	* |     | <<| P | >>|   |   |   |   |   |   |   |   |   |     |
	* |-----------------------------------------------------------|
	* |      | V-| M | V+|   |   |   |   |   |   |   |   |        |
	* |-----------------------------------------------------------|
	* |        |   |   |   |   |   |   | L1| L0|   |   |      |   |
	* |-----------------------------------------------------------|
	* |    |    |    |          |    |       |    | XX |    |     |
	* `-----------------------------------------------------------'
	*/

[L_FN] = LAYOUT(
	KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___X___, ___X___,

	_______, KC_MPRV, KC_MPLY, KC_MNXT, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___,

	_______, KC_VOLD, KC_MUTE, KC_VOLU, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                   ___X___,

	_______, ___E___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, DZ_QWER, DZ_QGML, ___X___, ___X___,          _______, ___X___,

	_______, _______, _______, _______,          XXXXXXX,                   _______,          _______, _CURMOD, ___E___, XXXXXXX, _______),

	/*-----------------------------------------------------------------------------------------------------------------------------------*/

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
	RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, ___X___, ___X___, ___X___, XXXXXXX, RESET,

	DZ_HU_D, RGB_HUD, RGB_HUI, DZ_HU_I, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, RGB_RMOD,RGB_MOD,          ___X___,

	DZ_SA_D, RGB_SAD, RGB_SAI, DZ_SA_I, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                   DZ_DBUG,

	DZ_VA_D, ___E___, RGB_VAD, RGB_VAI, DZ_VA_I, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___, ___X___,

	DZ_VERS, ___X___, ___X___, ___X___,          XXXXXXX,                   ___X___,          ___X___, XXXXXXX, ___E___, _CURMOD, ___X___),
};

rgblight_config_t origGlowState; // Original user-set underglow state
rgblight_config_t prevTempGlowState; // Long-term temp underglow (ie lock lights)

// Preset Underglows
rgblight_config_t numLockGlow;
rgblight_config_t capsLockGlow;
rgblight_config_t bothLockGlow;
rgblight_config_t defaultGlow;

rgblight_config_t knightFlash;

bool isGlowTemp = false;
uint16_t tempGlowDuration;
uint16_t tempGlowStart = 0;
rgblight_config_t rgblight_config;

void setTempGlow(rgblight_config_t tempState, rgblight_config_t prevState, uint16_t duration) {
	if (duration != 0) { // If this is an underglow flash
		if (isGlowTemp && tempGlowStart == 0) // And this is on top of a long-temp underglow
			prevTempGlowState.raw = rgblight_config.raw;

		tempGlowDuration = duration;
		tempGlowStart = timer_read();
	}
	else if (tempGlowDuration != 0) { // If the current underglow is a flash and the new one isn't
		prevTempGlowState.raw = tempState.raw; // Make it restore to this new underglow
		return;
	}

	if (!isGlowTemp) // If the current underglow is the user's, save it to origGlowState
		origGlowState = prevState;

	if (origGlowState.enable == 0) { // Turn on underglow if it's off, and use a non-blinding brightness
		rgblight_enable();
		tempState.val = 70;
	}

	rgblight_mode(tempState.mode);
	rgblight_sethsv(tempState.hue, tempState.sat, tempState.val);

	isGlowTemp = true;
}

void flashGlow(rgblight_config_t tempState, uint16_t hue, uint16_t duration) {
	tempState.hue = hue;
	tempState.val = rgblight_config.val;
	setTempGlow(tempState, rgblight_config, duration);
}

void lockGlow(rgblight_config_t tempState) {
	setTempGlow(tempState, rgblight_config, 0);
}

// Reset the underglow to either the lock light or the user's original underglow
void restoreGlow(bool fromTimer) {
	if (origGlowState.raw << 8 == numLockGlow.raw << 8		// If the prev state was the same as a lock state, change to my usual
	 || origGlowState.raw << 8 == capsLockGlow.raw << 8	// Shift ignores brightness, and compares everything else
	 || origGlowState.raw << 8 == bothLockGlow.raw << 8)
		origGlowState.raw = defaultGlow.raw;

	rgblight_config_t restoreState;

	if (prevTempGlowState.raw != 0 && fromTimer) // Restore to a lock light state if there was one
		restoreState = prevTempGlowState;
	else {                                       // If not, then restore to the original state
		restoreState = origGlowState;
		isGlowTemp = false;
	}

	rgblight_mode(restoreState.mode);
	rgblight_sethsv(restoreState.hue, restoreState.sat, restoreState.val);

	if (restoreState.enable == 0)
		rgblight_disable();

	tempGlowDuration = 0;
	tempGlowStart = 0;
	prevTempGlowState.raw = 0;
}

rgblight_config_t setRgblight(bool enable, uint8_t mode, uint16_t hue, uint8_t sat, uint8_t val) {
	rgblight_config_t config;
	config.enable = enable;
	config.mode = mode;
	config.hue = hue;
	config.sat = sat;
	config.val = val;

	return config;
}

// Set lock lights and the custom numpad layer based on the current active locks
void changeLockState(bool numOn, bool capsOn, uint8_t changedLock) {
	if ((!(changedLock & (1 << USB_LED_CAPS_LOCK)))
	 && (!(changedLock & (1 << USB_LED_NUM_LOCK))))
		return;

	rgblight_config_t newGlowState;

	if (numOn) {
		layer_on(L_NM);
		if (capsOn) {
			newGlowState.raw = bothLockGlow.raw;
		} else {
			newGlowState.raw = numLockGlow.raw;
		}
	} else {
		layer_off(L_NM);
		if (capsOn) {
			newGlowState.raw = capsLockGlow.raw;
		} else {
			restoreGlow(false);
			return;
		}
	}

	newGlowState.val = rgblight_config.val;

	lockGlow(newGlowState);
}

void stepGlowValues(uint16_t hslToChange, bool increase, uint8_t stepSize) {
	uint16_t current = 0;
	uint16_t newValue = 0;
	uint16_t propMax = 0;
	uint16_t rollover = 0;
	uint16_t rollunder = 0;

	switch (hslToChange) {
		case HUE:
			current = rgblight_config.hue;
			propMax = 359;
			rollover = 0;
			rollunder = 255;
			break;
		case SAT:
			current = rgblight_config.sat;
			propMax = 255;
			rollover = 255;
			rollunder = 0;
			break;
		case VAL:
			current = rgblight_config.val;
			propMax = 255;
			rollover = 255;
			rollunder = 0;
			break;
	}

	if (increase) {
		if (current > propMax - stepSize)
			newValue = rollover;
		else
			newValue = current + stepSize;
	} else {
		if (current < stepSize)
			newValue = rollunder;
		else
			newValue = current - stepSize;
	}

	switch (hslToChange) {
		case HUE:
			rgblight_sethsv(newValue, rgblight_config.sat, rgblight_config.val);
		break;
		case SAT:
			rgblight_sethsv(rgblight_config.hue, newValue, rgblight_config.val);
		break;
		case VAL:
			if (newValue == 0)
				newValue = stepSize;
			rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, newValue);
		break;
	}
}

void matrix_scan_user() {
	// Restore from temporary underglow
	if (tempGlowStart != 0 && timer_elapsed(tempGlowStart) > tempGlowDuration) {
		restoreGlow(true);
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	//char debugMessage [20];

	if (!record->event.pressed)
		return true;

	switch (keycode) {
		// Step color properties
		case DZ_HU_D:
			stepGlowValues(HUE, false, HUE_STEP);
			break;
		case DZ_HU_I:
			stepGlowValues(HUE, true, HUE_STEP);
			break;
		case DZ_SA_D:
			stepGlowValues(SAT, false, SAT_STEP);
			break;
		case DZ_SA_I:
			stepGlowValues(SAT, true, SAT_STEP);
			break;
		case DZ_VA_D:
			stepGlowValues(VAL, false, VAL_STEP);
			break;
		case DZ_VA_I:
			stepGlowValues(VAL, true, VAL_STEP);
			break;
		// Set the layout to QWERTY
		case DZ_QWER:
			flashGlow(knightFlash, 0, 500);

			set_single_persistent_default_layer(L_QW);
			break;
		// Set the layout to QGMLWY
		case DZ_QGML:
			flashGlow(knightFlash, 120, 500);

			set_single_persistent_default_layer(L_QG);
			break;
		// Cycle between layouts
		case DZ_CYCL:
			if (default_layer_state == L_QG + 1) {
				flashGlow(knightFlash, 0, 500);

				set_single_persistent_default_layer(L_QW);
			} else if (default_layer_state == L_QW + 1) {
				flashGlow(knightFlash, 120, 500);

				set_single_persistent_default_layer(L_QG);
			}
			break;
		// Print current version information
		case DZ_VERS:
			SEND_STRING("Current Version: 1.05    "
			            "Date: 10/22/18     "
			            "Most Recent Change: Swapped LAlt and LGui, made mods accessible under some temp layers.");
			break;
		// For general debugging
		case DZ_DBUG:
			//sprintf(debugMessage, "%lu | %u", default_layer_state, L_QG);
			//send_string(debugMessage);
			break;
	}

	return true;
}

uint8_t prevLedState = 0;
void led_set_user(uint8_t usb_led) {
	// When a lock is changed, call changeLockState to set the underglow
	if (usb_led != prevLedState) {
		changeLockState(usb_led & (1<<USB_LED_NUM_LOCK), usb_led & (1<<USB_LED_CAPS_LOCK), prevLedState ^ usb_led);

		prevLedState = usb_led;
	}
}

void matrix_init_user(void) {
	// Initialize all the preset underglows
	prevTempGlowState.raw = 0;

	numLockGlow = setRgblight(1, 1, 120, 255, 0);
	capsLockGlow = setRgblight(1, 1, 0, 255, 0);
	bothLockGlow = setRgblight(1, 1, 60, 255, 0);
	defaultGlow = setRgblight(1, 14, 270, 255, 255);
	knightFlash = setRgblight(1, 23, 0, 255, 255);
}
