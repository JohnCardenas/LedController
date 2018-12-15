#include "effects/BpmEffect.h"

BpmEffect::BpmEffect(CRGBPalette16 palette)
{
    m_initialFPS = 240;
    m_palette = palette;
}

void BpmEffect::executeFrame(struct CRGB (&leds)[LED_COUNT])
{
    uint8_t beat = beatsin8( m_beatsPerMinute, 64, 255);

    for(int i = 0; i < LED_COUNT; i++)
    {
        leds[i] = ColorFromPalette(m_palette, m_hue+(i*2), beat-m_hue+(i*10));
    }
}