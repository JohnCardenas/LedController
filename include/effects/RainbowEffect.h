#ifndef __DEFINED_RAINBOWEFFECT_H
#define __DEFINED_RAINBOWEFFECT_H

#include "config.h"
#include "effects/Effect.h"

class RainbowEffect : public Effect
{
    public:
        RainbowEffect(bool addGlitter = false);
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);
    
    private:
        bool m_addGlitter;
        byte m_thisHue = 0;
        byte m_deltaHue = 10;
};

#endif // __DEFINED_RAINBOWEFFECT_H