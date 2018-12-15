#include "effects/RainbowEffect.h"
#include "effects/GlitterEffect.h"

RainbowEffect::RainbowEffect(bool addGlitter)
{
    m_addGlitter = addGlitter;
}

void RainbowEffect::executeFrame(struct CRGB (&leds)[LED_COUNT])
{
    // Use FastLED's built-in rainbow generator
    m_thisHue++;
    fill_rainbow(leds, LED_COUNT, m_thisHue, m_deltaHue);

    if (m_addGlitter)
    {
        GlitterEffect::addGlitter(leds, 80);
    }
}