#ifndef __DEFINED_NOISEEFFECT_H
#define __DEFINED_NOISEEFFECT_H

#include "config.h"
#include "effects/Effect.h"

class NoiseEffect : public Effect
{
    public:
        NoiseEffect(CRGBPalette16 startingPalette, CRGBPalette16 targetPalette);
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);
    
    private:
        uint16_t m_scale = 30;      // Wouldn't recommend changing this on the fly, or the animation will be really blocky.
        uint16_t m_dist;            // A random number for our noise generator.
        uint8_t  m_maxChanges = 48; // Value for blending between palettes.

        CRGBPalette16 m_currentPalette;
        CRGBPalette16 m_targetPalette;
};

#endif // __DEFINED_NOISEEFFECT_H