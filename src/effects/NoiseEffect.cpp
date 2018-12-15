#include "effects/NoiseEffect.h"

NoiseEffect::NoiseEffect(CRGBPalette16 startingPalette, CRGBPalette16 targetPalette)
{
    m_currentPalette = startingPalette;
    m_targetPalette = targetPalette;
}

void NoiseEffect::executeFrame(struct CRGB (&leds)[LED_COUNT])
{
    EVERY_N_MILLISECONDS(10)
    {
        nblendPaletteTowardPalette(m_currentPalette, m_targetPalette, m_maxChanges);
    }

    for (int i = 0; i < LED_COUNT; i++)
    {
        // Just ONE loop to fill up the LED array as all of the pixels change.
        uint8_t index = inoise8(i * m_scale, m_dist + i * m_scale) % 255;            // Get a value from the noise function. I'm using both x and y axis.
        leds[i] = ColorFromPalette(m_currentPalette, index, 255, LINEARBLEND);   // With that value, look up the 8 bit colour palette value and assign it to the current LED.
    }

    // Moving along the distance (that random number we started out with). Vary it a bit with a sine wave.
    // In some sketches, I've used millis() instead of an incremented counter. Works a treat.
    m_dist += beatsin8(10, 1, 4);
}