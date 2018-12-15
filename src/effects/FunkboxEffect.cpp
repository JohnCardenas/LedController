#include "effects/FunkboxEffect.h"

int FunkboxEffect::m_topIndex = int(LED_COUNT / 2);

FunkboxEffect::FunkboxEffect(byte hue, byte saturation, byte oppositeHueOffset, bool solid, byte initialFPS)
{
  m_initialFPS = initialFPS;

  m_hue = hue;
  m_saturation = saturation;
  m_oppositeHueOffset = oppositeHueOffset;
  m_solid = solid;
}

void FunkboxEffect::executeFrame(struct CRGB (&leds)[LED_COUNT])
{
  m_index++;

  if (m_index >= LED_COUNT)
  {
    m_index = 0;
  }
  int indexR = m_index;
  int indexB = antipodalIndex(indexR);

  int oppositeHue = (m_hue + m_oppositeHueOffset) % 255;

  if (!m_solid)
  {
    for (int i = 0; i < LED_COUNT; i++ )
    {
      if (i == indexR)
      {
        leds[i] = CHSV(m_hue, m_saturation, 255);
      }
      else if (i == indexB)
      {
        leds[i] = CHSV(oppositeHue, m_saturation, 255);
      }
      else
      {
        leds[i] = CHSV(0, 0, 0);
      }
    }
  }
  else
  {
    leds[indexR] = CHSV(m_hue, m_saturation, 255);
    leds[indexB] = CHSV(oppositeHue, m_saturation, 255);
  }
}

int FunkboxEffect::antipodalIndex(int i)
{
  int iN = i + m_topIndex;

  if (i >= m_topIndex)
  {
    iN = ( i + m_topIndex ) % LED_COUNT;
  }

  return iN;
}