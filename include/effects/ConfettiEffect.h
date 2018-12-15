#ifndef __DEFINED_CONFETTIEFFECT_H
#define __DEFINED_CONFETTIEFFECT_H

#include "config.h"
#include "effects/Effect.h"

class ConfettiEffect : public Effect
{
    public:
        ConfettiEffect();
        virtual bool supportsCustomColor();
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);
};

#endif // __DEFINED_CONFETTIEFFECT_H