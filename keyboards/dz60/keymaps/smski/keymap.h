#ifndef SMSKI_H
#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define XXXXXXX KC_NO

void flashGlow(rgblight_config_t tempState, uint16_t hue, uint16_t duration);
void lockGlow(rgblight_config_t tempState);
void setTempGlow(rgblight_config_t tempState, rgblight_config_t prevState, uint16_t duration);
void restoreGlow(bool fromTimer);
void changeLockState(bool numOn, bool capsOn, uint8_t changedLock);
void stepGlowValues(uint16_t hslToChange, bool increase, uint8_t stepSize);
rgblight_config_t setRgblight(bool enable, uint8_t mode, uint16_t hue, uint8_t sat, uint8_t val);

#endif
