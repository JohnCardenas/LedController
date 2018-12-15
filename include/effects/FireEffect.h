#ifndef __DEFINED_FIREEFFECT_H
#define __DEFINED_FIREEFFECT_H

#include "config.h"
#include "effects/Effect.h"

class FireEffect : public Effect
{
    public:
        FireEffect();
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);
    
    private:
        CRGBPalette16 m_palette;
        bool          m_reverseDirection = false;
};

#endif // __DEFINED_FIREEFFECT_H