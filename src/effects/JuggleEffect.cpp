#include "effects/JuggleEffect.h"

JuggleEffect::JuggleEffect() {}

bool JuggleEffect::supportsCustomColor() { return true; }

void JuggleEffect::executeFrame(struct CRGB (&leds)[LED_COUNT])
{
    // eight colored dots, weaving in and out of sync with each other
    fadeToBlackBy( leds, LED_COUNT, 20);
    byte dotHue = 0;

    for ( int i = 0; i < 8; i++)
    {
      leds[beatsin16(i + 7, 0, LED_COUNT)] |= CRGB(m_Rcolor, m_Gcolor, m_Bcolor);
      dotHue += 32;
    }
}