#ifndef __DEFINED_SOLIDEFFECT_H
#define __DEFINED_SOLIDEFFECT_H

#include "config.h"
#include "effects/Effect.h"

class SolidEffect : public Effect
{
    public:
        SolidEffect();
        virtual bool supportsCustomColor();
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);
};

#endif // __DEFINED_SOLIDEFFECT_H