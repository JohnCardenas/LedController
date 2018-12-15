#ifndef __DEFINED_JUGGLEEFFECT_H
#define __DEFINED_JUGGLEEFFECT_H

#include "config.h"
#include "effects/Effect.h"

class JuggleEffect : public Effect
{
    public:
        JuggleEffect();
        virtual bool supportsCustomColor();
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);
};

#endif // __DEFINED_JUGGLEEFFECT_H