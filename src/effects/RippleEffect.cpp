#include "effects/RippleEffect.h"

#define MAX_STEPS 16 // Case statement wouldn't allow a variable.

RippleEffect::RippleEffect() {}

void RippleEffect::executeFrame(struct CRGB (&leds)[LED_COUNT])
{
    for (int i = 0; i < LED_COUNT; i++) leds[i] = CHSV(m_bgCol++, 255, 15);  // Rotate background colour.
    
    switch (m_step)
    {
        case -1: // Initialize ripple variables.
            m_center = random(LED_COUNT);
            m_color = random8();
            m_step = 0;
            break;
        case 0:
            leds[m_center] = CHSV(m_color, 255, 255); // Display the first pixel of the ripple.
            m_step++;
            break;
        case MAX_STEPS: // At the end of the ripples.
            m_step = -1;
            break;
        default: // Middle of the ripples.
            leds[(m_center + m_step + LED_COUNT) % LED_COUNT] += CHSV(m_color, 255, m_myFade / m_step * 2);   // Simple wrap from Marc Miller
            leds[(m_center - m_step + LED_COUNT) % LED_COUNT] += CHSV(m_color, 255, m_myFade / m_step * 2);
            m_step++; // Next step.
            break;
    }
}