#ifndef __DEFINED_TWINKLEEFFECT_H
#define __DEFINED_TWINKLEEFFECT_H

#include "config.h"
#include "effects/Effect.h"

class TwinkleEffect : public Effect
{
    public:
        TwinkleEffect();
        virtual void resetEffect();
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);
    
    private:
        int m_counter = 0;
};

#endif // __DEFINED_TWINKLEEFFECT_H