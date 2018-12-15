#include "effects/DotsEffect.h"

DotsEffect::DotsEffect() {}

void DotsEffect::executeFrame(struct CRGB (&leds)[LED_COUNT])
{
    byte inner = beatsin8(m_bpm, LED_COUNT / 4, LED_COUNT / 4 * 3);
    byte outer = beatsin8(m_bpm, 0, LED_COUNT - 1);
    byte middle = beatsin8(m_bpm, LED_COUNT / 3, LED_COUNT / 3 * 2);

    leds[middle] = CRGB::Purple;
    leds[inner] = CRGB::Blue;
    leds[outer] = CRGB::Aqua;

    nscale8(leds, LED_COUNT, m_fadeVal);
}