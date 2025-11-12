#include "global.h"

#include "led_blinky.h"
#include "temp_humi_monitor.h"

#include "main_server.h"
#include "tiny_ml.h"

void setup()
{
  Serial.begin(115200);
  // check_info_File(0); Need to read here

  xTaskCreate(led_blinky, "Task LED Blink", 2048, NULL, 2, NULL);
  xTaskCreate(temp_humi_monitor, "Task Temperature Huminity Monitor", 2048, NULL, 2, NULL);
  xTaskCreate(main_server_task, "Task Main Server" ,8192  ,NULL  ,2 , NULL);
  xTaskCreate(tiny_ml_task, "Tiny ML Task" ,2048  ,NULL  ,2 , NULL);
  // xTaskCreate(coreiot_task, "CoreIOT Task" ,4096  ,NULL  ,2 , NULL);
  // xTaskCreate(Task_Toogle_BOOT, "Task_Toogle_BOOT", 4096, NULL, 2, NULL);
}

void loop()
{
  // if (check_info_File(1))
  // {
  //   if (!Wifi_reconnect())
  //   {
  //     Webserver_stop();
  //   }
  //   else
  //   {
  //     //CORE_IOT_reconnect();
  //   }
  // }
  // Webserver_reconnect();
}