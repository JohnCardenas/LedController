#ifndef __DEFINED_RIPPLEEFFECT_H
#define __DEFINED_RIPPLEEFFECT_H

#include "config.h"
#include "effects/Effect.h"

class RippleEffect : public Effect
{
    public:
        RippleEffect();
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);
    
    private:
        uint8_t m_color;        // Ripple color is randomized.
        int     m_center = 0;   // Center of the current ripple.
        int     m_step = -1;    // -1 is the initializing step.
        uint8_t m_myFade = 255; // Starting brightness.
        uint8_t m_bgCol = 0;    // Background colour rotates.
};

#endif // __DEFINED_RIPPLEEFFECT_H