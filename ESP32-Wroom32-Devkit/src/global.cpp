#include "global.h"
float glob_temperature = 0;
float glob_humidity = 0;

String CORE_IOT_TOKEN;
String CORE_IOT_SERVER;
String CORE_IOT_PORT;

String AP_SSID = "ESP32-AP";
String AP_PASSWORD = "12345678";
String WIFI_SSID = "A18.02";
String WIFI_PASSWORD = "18021802";

boolean is_wifi_connected = false;
SemaphoreHandle_t xBinarySemaphoreInternet = xSemaphoreCreateBinary();