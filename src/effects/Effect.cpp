#include "effects/Effect.h"

byte Effect::m_Rcolor = 0;
byte Effect::m_Gcolor = 0;
byte Effect::m_Bcolor = 0;

byte Effect::initialFPS() { return m_initialFPS; }
bool Effect::supportsCustomColor() { return false; }
void Effect::resetEffect() {}
void Effect::executeFrame(struct CRGB (&leds)[LED_COUNT]) {}

void Effect::setCustomColor(byte Rvalue, byte Gvalue, byte Bvalue) 
{
    m_Rcolor = Rvalue;
    m_Gcolor = Gvalue;
    m_Bcolor = Bvalue;
}