#ifndef __DEFINED_FUNKBOXEFFECT_H
#define __DEFINED_FUNKBOXEFFECT_H

#include "config.h"
#include "effects/Effect.h"

class FunkboxEffect : public Effect
{
    public:
        FunkboxEffect(byte hue, byte saturation, byte oppositeHueOffset, bool solid, byte initialFPS);
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);
    
    private:
        int antipodalIndex(int i);

        byte m_hue;
        byte m_saturation;
        byte m_oppositeHueOffset;

        bool m_solid;
        int  m_index = 0;

        static int m_topIndex;
};

#endif // __DEFINED_FUNKBOXEFFECT_H