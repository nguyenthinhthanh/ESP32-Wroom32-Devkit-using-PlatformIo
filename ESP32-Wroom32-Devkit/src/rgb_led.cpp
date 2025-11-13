#include "rgb_led.h"

void setupRGB() {
  ledcSetup(RED_CHANNEL, 5000, 8); 
  ledcSetup(GREEN_CHANNEL, 5000, 8);
  ledcSetup(BLUE_CHANNEL, 5000, 8);

  ledcAttachPin(RGB_LED_RED_PIN, RED_CHANNEL);
  ledcAttachPin(RGB_LED_GREEN_PIN, GREEN_CHANNEL);
  ledcAttachPin(RGB_LED_BLUE_PIN, BLUE_CHANNEL);
}

void setRGB(uint8_t r, uint8_t g, uint8_t b) {
  ledcWrite(RED_CHANNEL, r);
  ledcWrite(GREEN_CHANNEL, g);
  ledcWrite(BLUE_CHANNEL, b);
}

void rgb_led_task(void *pvParameters){
  setupRGB();
  
  while(1) {                        
    if (is_ap_mode)
    {
        setRGB(0,0,255);
        vTaskDelay(1000);
    }
    else if (is_connecting)
    {
        setRGB(255,0,0);
        vTaskDelay(100);
    }
    else if (is_wifi_connected)
    {
        setRGB(0,255,0);
    }
    else{
        setRGB(0,0,0);
    }
  }
}