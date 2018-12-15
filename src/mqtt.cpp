#include "config.h"
#include "mqtt.h"
#include "LedController.h"

#define MQTT_PAYLOAD_BUFFER_SIZE 100
#define MQTT_QOS 0

WiFiClient espClient;
PubSubClient mqttClient(espClient);

void mqttPublish(const char* topic, const char* value, bool retain = true)
{
    if (mqttClient.connected())
    {
        mqttClient.publish(topic, value, retain);
    }
}

void mqttPublishState(const char* topic, bool value)
{
    mqttPublish(topic, value ? MQTT_COMMAND_ON : MQTT_COMMAND_OFF);
}

void mqttPublishState(const char* topic, int value)
{
    mqttPublish(topic, String(value).c_str());
}

void mqttPublishState(const char* topic, String value)
{
    mqttPublish(topic, value.c_str());
}

void mqttPublishState(const char* topic, byte value)
{
    mqttPublishState(topic, (int)value);
}

void mqttPublishStates()
{
    LedController& controller = LedController::instance();

    mqttPublishState(MQTT_TOPIC_STATE_ANIMATION_SPEED, controller.animationSpeed());
    mqttPublishState(MQTT_TOPIC_STATE_BRIGHTNESS,      controller.brightness());
    mqttPublishState(MQTT_TOPIC_STATE_EFFECT,          controller.effect());
    mqttPublishState(MQTT_TOPIC_STATE_POWER,           controller.on());
    mqttPublishState(MQTT_TOPIC_STATE_USE_EFFECT_FPS,  controller.useEffectFPS());
    controller.notifyCustomColorChanged();
}

void mqttSubscribeCommands()
{
    mqttClient.subscribe(MQTT_TOPIC_COMMAND_ANIMATION_SPEED);
    mqttClient.subscribe(MQTT_TOPIC_COMMAND_BRIGHTNESS);
    mqttClient.subscribe(MQTT_TOPIC_COMMAND_CUSTOM_COLOR);
    mqttClient.subscribe(MQTT_TOPIC_COMMAND_EFFECT);
    mqttClient.subscribe(MQTT_TOPIC_COMMAND_POWER);
    mqttClient.subscribe(MQTT_TOPIC_COMMAND_USE_EFFECT_FPS);
}

void mqttPublishResult(String message)
{
    mqttPublish(MQTT_TOPIC_TELEMETRY_RESULT, message.c_str());
}

void mqttReconnect()
{
    // Loop until we're reconnected
    while (!mqttClient.connected())
    {
        Serial.print("Attempting MQTT connection... ");

        // Attempt to connect
        if (mqttClient.connect(DEVICE_NAME, MQTT_USERNAME, MQTT_PASSWORD, MQTT_TOPIC_TELEMETRY_LWT, MQTT_QOS, true, MQTT_LWT_OFFLINE))
        {
            Serial.println("connected");
            mqttPublish(MQTT_TOPIC_TELEMETRY_LWT, MQTT_LWT_ONLINE);
            mqttPublish(MQTT_TOPIC_TELEMETRY_LED_COUNT, String(LED_COUNT).c_str());
            mqttPublishStates();
            mqttSubscribeCommands();
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(mqttClient.state());
            Serial.println(" trying again in 5 seconds");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}

String mqttPayloadByteToString(byte* payload, unsigned int length)
{
    if (length > MQTT_PAYLOAD_BUFFER_SIZE - 1)
    {
        // Payload exceeds null-terminated buffer size; send back an empty string
        return {};
    }

    char buffer[MQTT_PAYLOAD_BUFFER_SIZE];

    for (int i = 0; i < length; i++)
    {
        buffer[i] = payload[i];
    }

    // Add string null termination
    buffer[length] = '\0';
    return String(buffer);
}

void mqttPayloadReceived(char* topic, byte* payload, unsigned int length)
{
    LedController& controller = LedController::instance();

    if (String(topic) == MQTT_TOPIC_COMMAND_ANIMATION_SPEED)
    {
        String value = mqttPayloadByteToString(payload, length);
        int speed = value.toInt();

        controller.setAnimationSpeed(speed);
    }
    else if (String(topic) == MQTT_TOPIC_COMMAND_BRIGHTNESS)
    {
        String value = mqttPayloadByteToString(payload, length);
        int brightness = value.toInt();
        
        controller.setBrightness(brightness);
    }
    else if (String(topic) == MQTT_TOPIC_COMMAND_CUSTOM_COLOR)
    {
        String value = mqttPayloadByteToString(payload, length);
        controller.setCustomColor(value);
    }
    else if (String(topic) == MQTT_TOPIC_COMMAND_EFFECT)
    {
        String value = mqttPayloadByteToString(payload, length);
        controller.setEffect(value);
    }
    else if (String(topic) == MQTT_TOPIC_COMMAND_POWER)
    {
        String command = mqttPayloadByteToString(payload, length);

        if (command == MQTT_COMMAND_OFF)
        {
            controller.setOn(false);
        }
        else if (command == MQTT_COMMAND_ON)
        {
            controller.setOn(true);
        }
    }
    else if (String(topic) == MQTT_TOPIC_COMMAND_USE_EFFECT_FPS)
    {
        String command = mqttPayloadByteToString(payload, length);

        if (command == MQTT_COMMAND_OFF)
        {
            controller.setUseEffectFPS(false);
        }
        else if (command == MQTT_COMMAND_ON)
        {
            controller.setUseEffectFPS(true);
        }
    }
}

void mqttSetup()
{
    mqttClient.setServer(MQTT_SERVER, MQTT_PORT);
    mqttClient.setCallback(mqttPayloadReceived);
}

void mqttLoop()
{
    if (!mqttClient.connected())
    {
        mqttReconnect();
    }

    mqttClient.loop();
}