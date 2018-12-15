#include "effects/SolidEffect.h"

SolidEffect::SolidEffect()
{
    m_Rcolor = 0;
    m_Gcolor = 0;
    m_Bcolor = 0;
}

void SolidEffect::executeFrame(struct CRGB (&leds)[LED_COUNT])
{
    fill_solid(leds, LED_COUNT, CRGB(m_Rcolor, m_Gcolor, m_Bcolor));
}

bool SolidEffect::supportsCustomColor() { return true; }

/*void SolidEffect::setCustomColor(byte Rvalue, byte Gvalue, byte Bvalue)
{
    m_Rcolor = Rvalue;
    m_Gcolor = Gvalue;
    m_Bcolor = Bvalue;
}*/