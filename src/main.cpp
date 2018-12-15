#include "config.h"
#include "LedController.h"
#include "mqtt.h"
#include "network.h"
#include "ota.h"

void setup()
{
   Serial.begin(115200);

   LedController::instance().setup();
   networkSetup();
   mqttSetup();
   otaSetup();

   Serial.println("Ready");
   Serial.print("IP address: ");
   Serial.println(networkIpAddress());
}

void loop()
{
   mqttLoop();
   otaLoop();

   LedController::instance().loop();
}