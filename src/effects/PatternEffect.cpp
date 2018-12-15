#include "effects/PatternEffect.h"

PatternEffect::PatternEffect(CRGBPalette16 palette)
{
    m_initialFPS = 120;
    m_palette = palette;
}

void PatternEffect::executeFrame(struct CRGB (&leds)[LED_COUNT])
{
    m_startIndex = m_startIndex + 1; /* higher = faster motion */

    fill_palette(leds, LED_COUNT, m_startIndex, 16, /* higher = narrower stripes */ 
                 m_palette, 255, LINEARBLEND);
}