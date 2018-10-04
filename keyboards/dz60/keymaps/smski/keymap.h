#ifndef SMSKI_H
#include QMK_KEYBOARD_H

enum custom_keycodes {
	DZ_HU_D = SAFE_RANGE,
	DZ_HU_I,
	DZ_SA_D,
	DZ_SA_I,
	DZ_VA_D,
	DZ_VA_I,
	DZ_VERS,
	DZ_QGML,
	DZ_QWER,
	DZ_DBUG,
	DZ_CYCL,
};

enum custom_layers {
	L_QG = 0,
	L_QW,
	L_NM,
	L_TH,
	L_FN,
	L_RG
};

enum underglowProp {
	HUE = 0,
	SAT,
	VAL
};

void flashGlow(rgblight_config_t tempState, uint16_t hue, uint16_t duration);
void lockGlow(rgblight_config_t tempState);
void setTempGlow(rgblight_config_t tempState, rgblight_config_t prevState, uint16_t duration);
void restoreGlow(bool fromTimer);
void changeLockState(bool numOn, bool capsOn, uint8_t changedLock);
void stepGlowValues(uint16_t hslToChange, bool increase, uint8_t stepSize);
rgblight_config_t setRgblight(bool enable, uint8_t mode, uint16_t hue, uint8_t sat, uint8_t val);

#endif
