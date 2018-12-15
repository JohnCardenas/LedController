#include "effects/ConfettiEffect.h"

ConfettiEffect::ConfettiEffect()
{
    m_initialFPS = 120;
}

bool ConfettiEffect::supportsCustomColor() { return true; }

void ConfettiEffect::executeFrame(struct CRGB (&leds)[LED_COUNT])
{
    // random colored speckles that blink in and fade smoothly
    fadeToBlackBy(leds, LED_COUNT, 10);
    int pos = random16(LED_COUNT);
    leds[pos] += CRGB(m_Rcolor + random8(64), m_Gcolor, m_Bcolor);
}