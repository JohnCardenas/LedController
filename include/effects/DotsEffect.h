#ifndef __DEFINED_DOTSEFFECT_H
#define __DEFINED_DOTSEFFECT_H

#include "config.h"
#include "effects/Effect.h"

class DotsEffect : public Effect
{
    public:
        DotsEffect();
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);
    
    private:
        byte m_fadeVal = 224; // Trail behind the LED's. Lower => faster fade.
        byte m_bpm     = 30;
};

#endif // __DEFINED_DOTSEFFECT_H