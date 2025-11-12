#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

extern float glob_temperature;
extern float glob_humidity;

extern String CORE_IOT_TOKEN;
extern String CORE_IOT_SERVER;
extern String CORE_IOT_PORT;

extern String AP_SSID;
extern String AP_PASSWORD;
extern String WIFI_SSID;
extern String WIFI_PASSWORD;

extern boolean is_wifi_connected;
extern SemaphoreHandle_t xBinarySemaphoreInternet;
#endif