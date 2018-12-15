#include "effects/CyclonRainbowEffect.h"

CyclonRainbowEffect::CyclonRainbowEffect() {}

void CyclonRainbowEffect::executeFrame(struct CRGB (&leds)[LED_COUNT])
{
    //Single Dot Down
  
    // First slide the led in one direction
    for(int i = 0; i < LED_COUNT; i++)
    {
        // Set the i'th led to red 
        leds[i] = CHSV(m_hue++, 255, 255);

        // Show the leds
        FastLED.show(); 

        // now that we've shown the leds, reset the i'th led to black
        // leds[i] = CRGB::Black;
        fadeAll(leds);

        // Wait a little bit before we loop around and do it again
        FastLED.delay(10);
    }

    for(int i = (LED_COUNT)-1; i >= 0; i--)
    {
        // Set the i'th led to red 
        leds[i] = CHSV(m_hue++, 255, 255);

        // Show the leds
        FastLED.show();

        // now that we've shown the leds, reset the i'th led to black
        // leds[i] = CRGB::Black;
        fadeAll(leds);

        // Wait a little bit before we loop around and do it again
        FastLED.delay(10);
    }
}

void CyclonRainbowEffect::fadeAll(struct CRGB (&leds)[LED_COUNT])
{
    for(int i = 0; i < LED_COUNT; i++)
    {
        leds[i].nscale8(250);
    }
}