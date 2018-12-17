#ifndef __DEFINED_LEDCONTROLLER_H
#define __DEFINED_LEDCONTROLLER_H

#include <map>
#include "config.h"
#include "effects/Effect.h"

class LedController
{
    public:
        // Initializers
        void setup();

        // Singleton
        static LedController& instance();
        LedController(LedController const&) = delete;
        void operator=(LedController const&) = delete;

        // Getters
        bool   on();
        bool   useEffectFPS();
        String effect();
        byte   brightness();
        byte   animationSpeed();
        byte   customColorRed();
        byte   customColorGreen();
        byte   customColorBlue();
        String customColor();
        
        // Setters
        void setOn(bool value);
        void setUseEffectFPS(bool value);
        void setEffect(String effect);
        void setBrightness(byte value);
        void setAnimationSpeed(byte value);
        void setCustomColorRed(byte value, bool notifyChanged = true);
        void setCustomColorGreen(byte value, bool notifyChanged = true);
        void setCustomColorBlue(byte value, bool notifyChanged = true);
        void setCustomColor(byte Rvalue, byte Gvalue, byte Bvalue);
        void setCustomColor(String value);

        // Methods
        void loop();
        void notifyCustomColorChanged();

    private:
        // Constructor
        LedController();

        // Methods
        void initializePalettes();
        void initializeEffects();
        void updateCustomColorString();

        // Member Variables
        struct CRGB m_leds[LED_COUNT];
        std::map<String, Effect*> m_effects;

        String m_effect;
        bool   m_onState          = false;
        bool   m_useEffectFPS     = true;
        byte   m_brightness       = 150;
        byte   m_animationSpeed   = 240;
        byte   m_customColorRed   = 0;
        byte   m_customColorGreen = 0;
        byte   m_customColorBlue  = 0;
        String m_customColor;
};

#endif // __DEFINED_LEDCONTROLLER_H