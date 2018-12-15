#ifndef __DEFINED_BPMEFFECT_H
#define __DEFINED_BPMEFFECT_H

#include "config.h"
#include "effects/Effect.h"

class BpmEffect : public Effect
{
    public:
        BpmEffect(CRGBPalette16 palette);
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);

    private:
        CRGBPalette16 m_palette;
        byte m_beatsPerMinute = 62;
        byte m_hue = 0;
};

#endif // __DEFINED_BPMEFFECT_H