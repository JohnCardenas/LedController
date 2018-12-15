#include <map>
#include "LedController.h"
#include "mqtt.h"
#include "GradientPalettes.h"
#include "PatternPalettes.h"

#include "effects/BpmEffect.h"
#include "effects/ConfettiEffect.h"
#include "effects/CyclonRainbowEffect.h"
#include "effects/DotsEffect.h"
#include "effects/FireEffect.h"
#include "effects/FunkboxEffect.h"
#include "effects/GlitterEffect.h"
#include "effects/JuggleEffect.h"
#include "effects/LightningEffect.h"
#include "effects/NoiseEffect.h"
#include "effects/PatternEffect.h"
#include "effects/PulsingEffect.h"
#include "effects/RainbowEffect.h"
#include "effects/RippleEffect.h"
#include "effects/SinelonEffect.h"
#include "effects/SolidEffect.h"
#include "effects/TwinkleEffect.h"

void LedController::initializeEffects()
{
    m_effects["BPM"]             = new BpmEffect(PartyColors_p);
    m_effects["Confetti"]        = new ConfettiEffect();
    m_effects["Dots"]            = new DotsEffect();
    m_effects["Candy Cane"]      = new PatternEffect(PatternPalettes::get("Candy Cane"));
    m_effects["Christmas"]       = new PulsingEffect(GradientPalettes::get("bhw2_xmas_gp"));
    m_effects["Cyclon Rainbow"]  = new CyclonRainbowEffect();
    m_effects["Easter"]          = new NoiseEffect(CRGBPalette16(CRGB::Black), CRGBPalette16(OceanColors_p));
    m_effects["Fire"]            = new FireEffect();
    m_effects["Glitter"]         = new GlitterEffect();
    m_effects["Go Blue"]         = new PulsingEffect(GradientPalettes::get("Pills_3_gp"));
    m_effects["Hail"]            = new PatternEffect(PatternPalettes::get("Hail"));
    m_effects["Halloween"]       = new PulsingEffect(GradientPalettes::get("Orange_to_Purple_gp"));
    m_effects["Holly Jolly"]     = new PatternEffect(PatternPalettes::get("Holly Jolly"));
    m_effects["Independence"]    = new PatternEffect(PatternPalettes::get("Independence"));
    m_effects["Juggle"]          = new JuggleEffect();
    m_effects["Lightning"]       = new LightningEffect();
    m_effects["Lovey Day"]       = new FunkboxEffect(0, 255, 244, true, 60);
    m_effects["Police All"]      = new FunkboxEffect(0, 255, 160, true, 120);
    m_effects["Police One"]      = new FunkboxEffect(0, 255, 160, false, 30);
    m_effects["Punkin"]          = new PatternEffect(PatternPalettes::get("Halloween"));
    m_effects["Rainbow"]         = new RainbowEffect();
    m_effects["Rainbow Glitter"] = new RainbowEffect(true);
    m_effects["Ripple"]          = new RippleEffect();
    m_effects["Sinelon"]         = new SinelonEffect();
    m_effects["Solid"]           = new SolidEffect();
    m_effects["St Patty"]        = new PulsingEffect(GradientPalettes::get("bhw2_greenman_gp"));
    m_effects["Thanksgiving"]    = new PatternEffect(PatternPalettes::get("Thanksgiving"));
    m_effects["Touchdown"]       = new FunkboxEffect(64, 255, 96, false, 120);
    m_effects["Turkey Day"]      = new PulsingEffect(GradientPalettes::get("bhw2_thanks_gp"));
    m_effects["Twinkle"]         = new TwinkleEffect();
    m_effects["USA"]             = new PulsingEffect(GradientPalettes::get("bhw3_41_gp"));
    m_effects["Valentine"]       = new PulsingEffect(GradientPalettes::get("bhw2_redrosey_gp"));
}

/**
 * Constructor
 */
LedController::LedController()
{
    initializeEffects();
}

/**
 * Initializers
 */
void LedController::setup()
{
    FastLED.addLeds<LED_CHIPSET, LED_DATA_PIN, LED_COLOR_ORDER>(m_leds, LED_COUNT);
    FastLED.setMaxPowerInVoltsAndMilliamps(LED_VOLTAGE, LED_MILLIAMPS);
    FastLED.setBrightness(brightness());

    // Set all LEDs to off
    FastLED.clear();
    FastLED.show();
}

/**
 * Getters
 */
LedController& LedController::instance()
{
    static LedController staticInstance;
    return staticInstance;
}

bool   LedController::on()               { return m_onState;          }
bool   LedController::useEffectFPS()     { return m_useEffectFPS;     }
byte   LedController::brightness()       { return m_brightness;       }
byte   LedController::animationSpeed()   { return m_animationSpeed;   }
String LedController::effect()           { return m_effect;           }
byte   LedController::customColorRed()   { return m_customColorRed;   }
byte   LedController::customColorGreen() { return m_customColorGreen; }
byte   LedController::customColorBlue()  { return m_customColorBlue;  }

/**
 * Setters
 */
void LedController::setOn(bool value)
{
    m_onState = value;
    mqttPublishState(MQTT_TOPIC_STATE_POWER, value);
}

void LedController::setUseEffectFPS(bool value)
{
    m_useEffectFPS = value;
    mqttPublishState(MQTT_TOPIC_STATE_USE_EFFECT_FPS, value);
}

void LedController::setBrightness(byte value)
{
    if (value == 0) 
        setOn(false);

    m_brightness = value;
    mqttPublishState(MQTT_TOPIC_STATE_BRIGHTNESS, value);
}

void LedController::setAnimationSpeed(byte value)
{
    m_animationSpeed = value;
    mqttPublishState(MQTT_TOPIC_STATE_ANIMATION_SPEED, value);
}

void LedController::setCustomColorRed(byte value, bool notifyChanged)
{
    m_customColorRed = value;

    if (notifyChanged)
        notifyCustomColorChanged();
}

void LedController::setCustomColorGreen(byte value, bool notifyChanged)
{
    m_customColorGreen = value;

    if (notifyChanged)
        notifyCustomColorChanged();
}

void LedController::setCustomColorBlue(byte value, bool notifyChanged)
{
    m_customColorBlue = value;

    if (notifyChanged)
        notifyCustomColorChanged();
}

void LedController::setCustomColor(byte Rvalue, byte Gvalue, byte Bvalue)
{
    setCustomColorRed(Rvalue, false);
    setCustomColorGreen(Gvalue, false);
    setCustomColorBlue(Bvalue, false);
    notifyCustomColorChanged();
}

void LedController::setCustomColor(String value)
{
    byte Rcolor = value.substring(0, value.indexOf(',')).toInt();
    byte Gcolor = value.substring(value.indexOf(',') + 1, value.lastIndexOf(',')).toInt();
    byte Bcolor = value.substring(value.lastIndexOf(',') + 1).toInt();
    setCustomColor(Rcolor, Gcolor, Bcolor);
}

void LedController::notifyCustomColorChanged()
{
    Effect::setCustomColor(customColorRed(), customColorGreen(), customColorBlue());
    updateCustomColorString();
    mqttPublishState(MQTT_TOPIC_STATE_CUSTOM_COLOR, m_customColor);
}

void LedController::updateCustomColorString()
{
    m_customColor = String(customColorRed()) + "," + String(customColorGreen()) + "," + String(customColorBlue());
}

void LedController::setEffect(String effectName)
{
    if (m_effects.find(effectName) != m_effects.end())
    {
        m_effect = effectName;

        if (useEffectFPS())
        {
            setAnimationSpeed(m_effects[effectName]->initialFPS());
        }

        m_effects[effectName]->resetEffect();
        mqttPublishState(MQTT_TOPIC_STATE_EFFECT, effectName);
        mqttPublishState(MQTT_TOPIC_STATE_EFFECT_SUPPORTS_CUSTOM_COLOR, m_effects[effectName]->supportsCustomColor());
    }
}

/**
 * Methods
 */
void LedController::loop()
{
    if (on() == false)
    {
        for (int i = 0; i < LED_COUNT; i++)
        {
            m_leds[i].fadeToBlackBy(8);
        }
    }
    else
    {
        m_effects[effect()]->executeFrame(m_leds);
    }

    FastLED.setBrightness(brightness());  //EXECUTE EFFECT COLOR
    FastLED.show();

    // Setting animation speed to maximum = no delay on loop
    if (animationSpeed() < 255)
    {
        // Delay by the number of frames per second
        FastLED.delay(1000 / animationSpeed());
    }

    random16_add_entropy(random8());
}