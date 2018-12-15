#ifndef __DEFINED_MQTT_H
#define __DEFINED_MQTT_H

#include "config.h"

/**
 * Namespaces
 */
#define MQTT_NAMESPACE_TELEMETRY "tele"
#define MQTT_NAMESPACE_STATE     "stat"
#define MQTT_NAMESPACE_COMMAND   "cmnd"

/**
 * Prefixes
 */
#define MQTT_PREFIX_COMMAND   MQTT_TOPIC_ROOT "/" DEVICE_NAME "/" MQTT_NAMESPACE_COMMAND
#define MQTT_PREFIX_STATE     MQTT_TOPIC_ROOT "/" DEVICE_NAME "/" MQTT_NAMESPACE_STATE
#define MQTT_PREFIX_TELEMETRY MQTT_TOPIC_ROOT "/" DEVICE_NAME "/" MQTT_NAMESPACE_TELEMETRY

/**
 * Telemetry topics
 */
#define MQTT_TOPIC_TELEMETRY_LED_COUNT MQTT_PREFIX_TELEMETRY "/ledCount"
#define MQTT_TOPIC_TELEMETRY_LWT       MQTT_PREFIX_TELEMETRY "/LWT"
#define MQTT_TOPIC_TELEMETRY_RESULT    MQTT_PREFIX_TELEMETRY "/result"

/**
 * State topics
 */
#define MQTT_TOPIC_STATE_ANIMATION_SPEED              MQTT_PREFIX_STATE "/animationSpeed"
#define MQTT_TOPIC_STATE_BRIGHTNESS                   MQTT_PREFIX_STATE "/brightness"
#define MQTT_TOPIC_STATE_CUSTOM_COLOR                 MQTT_PREFIX_STATE "/customColor"
#define MQTT_TOPIC_STATE_EFFECT                       MQTT_PREFIX_STATE "/effect"
#define MQTT_TOPIC_STATE_EFFECT_SUPPORTS_CUSTOM_COLOR MQTT_PREFIX_STATE "/effectSupportsCustomColor"
#define MQTT_TOPIC_STATE_POWER                        MQTT_PREFIX_STATE "/power"
#define MQTT_TOPIC_STATE_USE_EFFECT_FPS               MQTT_PREFIX_STATE "/useEffectFPS"

/**
 * Command topics
 */
#define MQTT_TOPIC_COMMAND_ANIMATION_SPEED  MQTT_PREFIX_COMMAND "/animationSpeed"
#define MQTT_TOPIC_COMMAND_BRIGHTNESS       MQTT_PREFIX_COMMAND "/brightness"
#define MQTT_TOPIC_COMMAND_CUSTOM_COLOR     MQTT_PREFIX_COMMAND "/customColor"
#define MQTT_TOPIC_COMMAND_EFFECT           MQTT_PREFIX_COMMAND "/effect"
#define MQTT_TOPIC_COMMAND_POWER            MQTT_PREFIX_COMMAND "/power"
#define MQTT_TOPIC_COMMAND_USE_EFFECT_FPS   MQTT_PREFIX_COMMAND "/useEffectFPS"

/**
 * Command values
 */
#define MQTT_COMMAND_ON "ON"
#define MQTT_COMMAND_OFF "OFF"

/**
 * LWT Values
 */
#define MQTT_LWT_ONLINE "Online"
#define MQTT_LWT_OFFLINE "Offline"

void mqttSetup();
void mqttLoop();

void mqttPublishState(const char* stateTopic, bool   value);
void mqttPublishState(const char* stateTopic, int    value);
void mqttPublishState(const char* stateTopic, String value);
void mqttPublishState(const char* stateTopic, byte   value);

#endif // __DEFINED_MQTT_H