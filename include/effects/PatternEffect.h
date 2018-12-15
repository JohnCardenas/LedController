#ifndef __DEFINED_PATTERNEFFECT_H
#define __DEFINED_PATTERNEFFECT_H

#include "config.h"
#include "effects/Effect.h"

class PatternEffect : public Effect
{
    public:
        PatternEffect(CRGBPalette16 palette);
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);

    private:
        byte          m_startIndex = 0;
        CRGBPalette16 m_palette;
};

#endif // __DEFINED_PATTERNEFFECT_H