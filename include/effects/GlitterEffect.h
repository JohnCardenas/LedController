#ifndef __DEFINED_GLITTEREFFECT_H
#define __DEFINED_GLITTEREFFECT_H

#include "config.h"
#include "effects/Effect.h"

class GlitterEffect : public Effect
{
    public:
        GlitterEffect();
        virtual bool supportsCustomColor();
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);
        static void addGlitter(struct CRGB (&leds)[LED_COUNT], fract8 chanceOfGlitter);
        static void addGlitter(struct CRGB (&leds)[LED_COUNT], fract8 chanceOfGlitter, byte Rcolor, byte Gcolor, byte Bcolor);
};

#endif // __DEFINED_GLITTEREFFECT_H