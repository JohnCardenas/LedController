#include "config.h"
#include "ota.h"

#if defined(OTA_PORT) && defined(OTA_PASSWORD)

void otaOnStartCallback()
{
    String type;

    if (ArduinoOTA.getCommand() == U_FLASH)
    {
      type = "sketch";
    } 
    else 
    { 
        // U_SPIFFS
        type = "filesystem";
    }

    Serial.println("Start updating " + type);
}

void otaOnEndCallback()
{
    Serial.println("\nEnd");
}

void otaOnProgressCallback(unsigned int progress, unsigned int total)
{
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
}

void otaOnErrorCallback(ota_error_t error)
{
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
}

void otaSetup()
{
    ArduinoOTA.setPort(OTA_PORT);
    ArduinoOTA.setHostname(DEVICE_NAME);
    ArduinoOTA.setPassword((const char *)OTA_PASSWORD);

    ArduinoOTA.onStart(otaOnStartCallback);
    ArduinoOTA.onEnd(otaOnEndCallback);
    ArduinoOTA.onProgress(otaOnProgressCallback);
    ArduinoOTA.onError(otaOnErrorCallback);

    ArduinoOTA.begin();
}

void otaLoop()
{
    ArduinoOTA.handle();
}

#else

void otaSetup() {}
void otaLoop() {}

#endif