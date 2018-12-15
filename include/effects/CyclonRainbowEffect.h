#ifndef __DEFINED_CYCLONRAINBOWEFFECT_H
#define __DEFINED_CYCLONRAINBOWEFFECT_H

#include "config.h"
#include "effects/Effect.h"

class CyclonRainbowEffect : public Effect
{
    public:
        CyclonRainbowEffect();
        virtual void executeFrame(struct CRGB (&leds)[LED_COUNT]);

    private:
        void fadeAll(struct CRGB (&leds)[LED_COUNT]);
        byte m_hue = 0;
};

#endif // __DEFINED_CYCLONRAINBOWEFFECT_H