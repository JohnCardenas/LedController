#ifndef __DEFINED_PULSINGEFFECT_H
#define __DEFINED_PULSINGEFFECT_H

#include "config.h"
#include "effects/Effect.h"

class PulsingEffect : public Effect
{
    public:
        PulsingEffect(CRGBPalette16 palette);
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);
    
    private:
        byte          m_beat;
        byte          m_beatsPerMinute = 62;
        byte          m_hue = 0;
        CRGBPalette16 m_palette;
};

#endif // __DEFINED_PULSINGEFFECT_H