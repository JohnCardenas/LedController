#ifndef __DEFINED_CONFIG_H
#define __DEFINED_CONFIG_H

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#define FASTLED_INTERRUPT_RETRY_COUNT 0
#include <FastLED.h>

#include <ArduinoOTA.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>

/**
 * DEVICE CONFIGURATION
 */
#define DEVICE_NAME "ledcon1" // Hostname of this device

/**
 * LED CONFIGURATION
 */
#define LED_DATA_PIN    D4     // Digital data pin connected to LEDs
#define LED_COUNT       150    // Number of LEDs on your string
#define LED_CHIPSET     WS2811 // LED chipset, defined by FastLED.h
#define LED_COLOR_ORDER RGB    // LED color order
#define LED_VOLTAGE     12     // Power supply voltage rating
#define LED_MILLIAMPS   30000  // Power supply amperage rating, in mA

/**
 * WIRELESS CONFIGURATION
 */
#define WIFI_SSID     "" // SSID of your WiFi network (only WPA-PSK is supported)
#define WIFI_PASSWORD ""

/**
 * MQTT CLIENT CONFIGURATION
 */
#define MQTT_SERVER   ""   // DNS name or IP address of your MQTT server
#define MQTT_USERNAME ""   // MQTT user name
#define MQTT_PASSWORD ""   // MQTT password
#define MQTT_PORT     1883 // MQTT service port

/**
 * MQTT TOPIC CONFIGURATION
 */
#define MQTT_TOPIC_ROOT "ledcontroller" // Topic root for this device becomes MQTT_TOPIC_ROOT/DEVICE_NAME

/**
 * OTA CONFIGURATION
 * 
 * Uncomment the fields below and set a password to enable OTA updating
 */
//#define OTA_PORT     8266 // ArduinoOTA update port
//#define OTA_PASSWORD ""   // ArduinoOTA password

#endif // __DEFINED_CONFIG_H