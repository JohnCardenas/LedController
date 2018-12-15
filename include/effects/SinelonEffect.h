#ifndef __DEFINED_SINELONEFFECT_H
#define __DEFINED_SINELONEFFECT_H

#include "config.h"
#include "effects/Effect.h"

class SinelonEffect : public Effect
{
    public:
        SinelonEffect();
        virtual bool supportsCustomColor();
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);
};

#endif // __DEFINED_SINELONEFFECT_H