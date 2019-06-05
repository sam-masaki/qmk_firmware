#ifndef _SMSKI_H_
#define _SMSKI_H_
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
  CURR_LR
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

#endif
