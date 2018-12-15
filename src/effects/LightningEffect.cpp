#include "effects/LightningEffect.h"

LightningEffect::LightningEffect() {}

void LightningEffect::resetEffect()
{
    m_counter = 0;
}

void LightningEffect::executeFrame(struct CRGB (&leds)[LED_COUNT])
{
    m_counter++;

    if (m_counter < 2)
    {
        //Resets strip if previous animation was running
        FastLED.clear();
        FastLED.show();
    }

    m_ledStart = random8(LED_COUNT); // Determine starting location of flash
    m_ledLen = random8(LED_COUNT - m_ledStart);  // Determine length of flash (not to go beyond NUM_LEDS-1)

    for (int flashCounter = 0; flashCounter < random8(3, m_flashes); flashCounter++)
    {
        if (flashCounter == 0) m_dimmer = 5; // the brightness of the leader is scaled down by a factor of 5
        else m_dimmer = random8(1, 3);       // return strokes are brighter than the leader
    
        fill_solid(leds + m_ledStart, m_ledLen, CHSV(255, 0, 255 / m_dimmer));

        FastLED.show(); // Show a section of LED's
        FastLED.delay(random8(4, 10)); // each flash only lasts 4-10 milliseconds
      
        fill_solid(leds + m_ledStart, m_ledLen, CHSV(255, 0, 0)); // Clear the section of LED's
        FastLED.show();

        if (flashCounter == 0) FastLED.delay(150);   // longer delay until next flash after the leader
        FastLED.delay(50 + random8(100)); // shorter delay between strokes
    }

    FastLED.delay(random8(m_frequency) * 100);        // delay between strikes
}