#include "effects/SinelonEffect.h"

SinelonEffect::SinelonEffect() {}

bool SinelonEffect::supportsCustomColor() { return true; }

void SinelonEffect::executeFrame(struct CRGB (&leds)[LED_COUNT])
{
    fadeToBlackBy( leds, LED_COUNT, 20);
    int pos = beatsin16(13, 0, LED_COUNT);
    leds[pos] += CRGB(m_Rcolor, m_Gcolor, m_Bcolor);
}