#ifndef __DEFINED_LIGHTNINGEFFECT_H
#define __DEFINED_LIGHTNINGEFFECT_H

#include "config.h"
#include "effects/Effect.h"

class LightningEffect : public Effect
{
    public:
        LightningEffect();
        virtual void resetEffect();
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);
    
    private:
        byte         m_frequency = 50;  // controls the interval between strikes
        byte         m_flashes = 8;     //the upper limit of flashes per strike
        unsigned int m_dimmer = 1;
        byte         m_ledStart;        // Starting location of a flash
        byte         m_ledLen;
        int          m_counter = 0;
};

#endif // __DEFINED_LIGHTNINGEFFECT_H