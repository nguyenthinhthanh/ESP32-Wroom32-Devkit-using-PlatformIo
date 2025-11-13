#ifndef __RGB_LED__
#define __RGB_LED__
#include <Arduino.h>
#include "global.h"

#define RGB_LED_RED_PIN     GPIO_NUM_12
#define RGB_LED_GREEN_PIN   GPIO_NUM_13
#define RGB_LED_BLUE_PIN    GPIO_NUM_14

#define RED_CHANNEL   0
#define GREEN_CHANNEL 1
#define BLUE_CHANNEL  2

void setupRGB();
void setRGB(uint8_t r, uint8_t g, uint8_t b);
void rgb_led_task(void *pvParameters);

#endif