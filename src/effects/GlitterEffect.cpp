#include "effects/GlitterEffect.h"

GlitterEffect::GlitterEffect() {}

bool GlitterEffect::supportsCustomColor() { return true; }

void GlitterEffect::executeFrame(struct CRGB (&leds)[LED_COUNT])
{
    fadeToBlackBy(leds, LED_COUNT, 20);
    GlitterEffect::addGlitter(leds, 80, m_Rcolor, m_Gcolor, m_Bcolor);
}

void GlitterEffect::addGlitter(struct CRGB (&leds)[LED_COUNT], fract8 chanceOfGlitter)
{
    GlitterEffect::addGlitter(leds, chanceOfGlitter, 255, 255, 255);
}

void GlitterEffect::addGlitter(struct CRGB (&leds)[LED_COUNT], fract8 chanceOfGlitter, byte Rcolor, byte Gcolor, byte Bcolor)
{
    if (random8() < chanceOfGlitter)
    {
        leds[random16(LED_COUNT)] += CRGB(Rcolor, Gcolor, Bcolor);
    }
}