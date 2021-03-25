#include <stdio.h>
#include "led.h"
#include "host.h"
#include "lily58.h"

char host_led_state_str[6];

const char *read_host_led_state(void)
{
  snprintf(host_led_state_str, sizeof(host_led_state_str), "%c %c %c",
           (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) ? 'C' : '_',
           (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) ? 'N' : '_',
           (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)) ? 'S' : '_');

  return host_led_state_str;
}
