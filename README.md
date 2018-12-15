# LedController
A C++ refactor of the [Dr. Zzs](https://github.com/Snipercaine/Holiday-LED-files)/[Bruh](https://github.com/bruhautomation/ESP-MQTT-JSON-Digital-LEDs) LED controller Arduino sketch in Platform.io. Full credit for the original idea and code goes to them!

## Configuration
1. Install [Visual Studio Code](https://code.visualstudio.com/).
2. Install [Platform.io](https://docs.platformio.org/en/latest/ide/vscode.html#installation) in VS Code.
3. [Download](https://github.com/JohnCardenas/LedController/archive/master.zip) and extract a copy of this repository.
4. Edit the include/config.h file to match your setup.
5. Connect a Wemos D1 mini to your system and [upload](https://docs.platformio.org/en/latest/ide/vscode.html#project-tasks) the compiled firmware in VS Code.
6. Disconnect the D1 mini and connect it to a power source (breadboard or USB).
7. Enjoy.

## MQTT Topics
The LedController uses a topic structure similar to Tasmota. If you have not made any changes to MQTT topics or the root topic, the following topics will be available (substitute X for DEVICE_NAME in config.h).

### Telemetry topics
  * LED Count: `ledcontroller/X/tele/ledCount`
  * Availability: `ledcontroller/X/tele/LWT`

### State topics
  * Animation Speed: `ledcontroller/X/stat/animationSpeed`
  * Brightness: `ledcontroller/X/stat/brightness`
  * Custom Color: `ledcontroller/X/stat/customColor`
  * Effect: `ledcontroller/X/stat/effect`
  * Power: `ledcontroller/X/stat/power`

### Command topics:
  * Animation Speed: `ledcontroller/X/cmnd/animationSpeed`
  * Brightness: `ledcontroller/X/cmnd/brightness`
  * Custom Color: `ledcontroller/X/cmnd/customColor`
  * Effect: `ledcontroller/X/cmnd/effect`
  * Power: `ledcontroller/X/cmnd/power`
  
## Home Assistant Configuration
You can configure Home Assistant to control the LED strip using the following YAML:

```yaml
light:
  - platform: mqtt
    name: "Holiday LEDs"
    command_topic: "ledcontroller/ledcon1/cmnd/power"
    state_topic: "ledcontroller/ledcon1/stat/power"
    rgb_state_topic: "ledcontroller/ledcon1/stat/customColor"
    rgb_command_topic: "ledcontroller/ledcon1/cmnd/customColor"
    brightness_state_topic: "ledcontroller/ledcon1/stat/brightness"
    brightness_command_topic: "ledcontroller/ledcon1/cmnd/brightness"
    availability_topic: "ledcontroller/ledcon1/tele/LWT"
    effect_state_topic: "ledcontroller/ledcon1/stat/effect"
    effect_command_topic: "ledcontroller/ledcon1/cmnd/effect"
    effect_list:
      - "BPM"
      - "Confetti"
      - "Dots"
      - "Candy Cane"
      - "Christmas"
      - "Cyclon Rainbow"
      - "Easter"
      - "Fire"
      - "Glitter"
      - "Go Blue"
      - "Hail"
      - "Halloween"
      - "Holly Jolly"
      - "Independence"
      - "Juggle"
      - "Lightning"
      - "Lovey Day"
      - "Police All"
      - "Police One"
      - "Punkin"
      - "Rainbow"
      - "Rainbow Glitter"
      - "Ripple"
      - "Sinelon"
      - "Solid"
      - "St Patty"
      - "Thanksgiving"
      - "Touchdown"
      - "Turkey Day"
      - "Twinkle"
      - "USA"
      - "Valentine"
    payload_on: "ON"
    payload_off: "OFF"
    payload_available: "Online"
    payload_not_available: "Offline"
    qos: 0
    retain: true
```

## To-Do/Future
* Bugfixes
* Better code documentation
* More effects
* Web interface
* Web/MQTT effect configuration
* Web/MQTT palette configuration
