#include "effects/PulsingEffect.h"

PulsingEffect::PulsingEffect(CRGBPalette16 palette)
{
    m_palette = palette;
}

void PulsingEffect::executeFrame(struct CRGB (&leds)[LED_COUNT])
{
    m_beat = beatsin8( m_beatsPerMinute, 64, 255);

    for( int i = 0; i < LED_COUNT; i++)
    {
        //9948
        leds[i] = ColorFromPalette(m_palette, m_hue+(i*2), m_beat-m_hue+(i*10));
    }

    EVERY_N_MILLISECONDS(10) { m_hue++; }
}