#ifndef __DEFINED_EFFECT_H
#define __DEFINED_EFFECT_H

#include "config.h"

class Effect
{
    public:
        static void setCustomColor(byte Rvalue, byte Gvalue, byte Bvalue);

        byte initialFPS();
        virtual bool supportsCustomColor();
        virtual void resetEffect();
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);
    
    protected:
        byte m_initialFPS = 240;
        static byte m_Rcolor, m_Gcolor, m_Bcolor;
};

#endif // __DEFINED_EFFECT_H