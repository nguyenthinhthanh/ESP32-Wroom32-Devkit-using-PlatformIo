#ifndef __CORE_IOT_H__
#define __CORE_IOT_H__

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

#include "global.h"

void coreiot_task(void *pvParameters);

#endif