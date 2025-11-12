#ifndef __TEMP_HUMI_MONITOR__
#define __TEMP_HUMI_MONITOR__

#include <Arduino.h>
#include "LiquidCrystal_I2C.h"
#include "DHT20.h"
#include "global.h"

#define SDA_PIN GPIO_NUM_21
#define SCL_PIN GPIO_NUM_22

void temp_humi_monitor(void *pvParameters);

#endif