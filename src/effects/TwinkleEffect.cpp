#include "effects/TwinkleEffect.h"

#define DENSITY 80

TwinkleEffect::TwinkleEffect() {}

void TwinkleEffect::resetEffect()
{
    m_counter = 0;
}

void TwinkleEffect::executeFrame(struct CRGB (&leds)[LED_COUNT])
{
    m_counter++;

    if (m_counter < 2)
    {
        //Resets strip if previous animation was running
        FastLED.clear();
        FastLED.show();
    }

    const CRGB lightColor(8, 7, 1);

    for (int i = 0; i < LED_COUNT; i++)
    {
        if (!leds[i])
            continue; // skip black pixels

        if (leds[i].r & 1)
        {
            // is red odd?
            leds[i] -= lightColor; // darken if red is odd
        }
        else
        {
            leds[i] += lightColor; // brighten if red is even
        }
    }
    
    if ( random8() < DENSITY)
    {
        int j = random16(LED_COUNT);
        if (!leds[j]) leds[j] = lightColor;
    }
}