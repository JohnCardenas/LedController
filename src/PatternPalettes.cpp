#include "PatternPalettes.h"

/**
 * Class code follows.
 */
bool PatternPalettes::m_initialized = false;
std::map<String, CRGBPalette16> PatternPalettes::m_palettes;

void PatternPalettes::initialize()
{
    if (m_initialized == false)
    {
        m_palettes["Candy Cane"]   = createStripedPalette(CRGB::Red,        0,              CRGB::White,      0,   8, 0, 8, 0);
        m_palettes["Hail"]         = createStripedPalette(CRGB::Blue,       0,              CRGB::Yellow,     0,   8, 0, 8, 0);
        m_palettes["Halloween"]    = createStripedPalette(CRGB::DarkOrange, 0,              CRGB::Indigo,     0,   8, 0, 8, 0);
        m_palettes["Holly Jolly"]  = createStripedPalette(CRGB::Red,        0,              CRGB::Green,      0,   8, 0, 8, 0);
        m_palettes["Independence"] = createStripedPalette(CRGB::FireBrick,  CRGB::Cornsilk, CRGB::MediumBlue, 0,   5, 5, 6, 0);
        m_palettes["Thanksgiving"] = createStripedPalette(CRGB::OrangeRed,  CRGB::Olive,    CRGB::Maroon,     0,   7, 3, 6, 0);

        m_initialized = true;
    }
}

CRGBPalette16& PatternPalettes::get(String paletteName)
{
    if (m_initialized == false)
        PatternPalettes::initialize();
    
    if (m_palettes.find(paletteName) != m_palettes.end())
    {
        return m_palettes[paletteName];
    }
    else
    {
        CRGBPalette16 emptyPalette;
        return emptyPalette;
    }
}

CRGBPalette16 PatternPalettes::createStripedPalette(CRGB A, CRGB AB, CRGB B, CRGB BA, int numA, int numAB, int numB, int numBA)
{
    CRGBPalette16 palette;

    // Return an empty palette if we don't have 16 colors
    if (numA + numAB + numB + numBA != 16)
        return palette;
    
    int paletteIndex = 0;

    for (int i = 0; i < numA;  i++) { palette[paletteIndex++] = A;  }
    for (int i = 0; i < numAB; i++) { palette[paletteIndex++] = AB; }
    for (int i = 0; i < numB;  i++) { palette[paletteIndex++] = B;  }
    for (int i = 0; i < numBA; i++) { palette[paletteIndex++] = BA; }

    return palette;
}