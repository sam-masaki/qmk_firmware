
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

#define L_BASE_CARPALX 0
#define L_BASE_QWERTY 1
#define L_BASE 0
//#define L_QWERTY (1 << 1)
#define L_LOWER (1 << 2)
#define L_RAISE (1 << 3)
#define L_ADJUST (1 << 4)
#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)

char layer_state_str[24];

const char *read_layer_state(void) {
  snprintf(layer_state_str, sizeof(layer_state_str), "%i", biton32(default_layer_state));

  switch (layer_state)
  {
    case L_BASE:
      if (biton32(default_layer_state) == L_BASE_CARPALX)
        snprintf(layer_state_str, sizeof(layer_state_str), "Carpx");
      else if (biton32(default_layer_state) == L_BASE_QWERTY)
        snprintf(layer_state_str, sizeof(layer_state_str), "QWERT");
      break;
    case L_RAISE:
      snprintf(layer_state_str, sizeof(layer_state_str), "Raise");
      break;
    case L_LOWER:
      snprintf(layer_state_str, sizeof(layer_state_str), "Lower");
      break;
    case L_ADJUST:
    case L_ADJUST_TRI:
      snprintf(layer_state_str, sizeof(layer_state_str), "Adjus");
      break;
    default:
      snprintf(layer_state_str, sizeof(layer_state_str), "Undef-%ld", layer_state);
  }

  return layer_state_str;
}
