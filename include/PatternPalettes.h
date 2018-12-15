#ifndef __DEFINED_PATTERNPALETTES_H
#define __DEFINED_PATTERNPALETTES_H

#include <map>
#include "config.h"

class PatternPalettes
{
    public:
        static CRGBPalette16& get(String paletteName);

    private:
        static CRGBPalette16 createStripedPalette(CRGB A, CRGB AB, CRGB B, CRGB BA, int numA, int numAB, int numB, int numBA);
        static void initialize();

        static bool m_initialized;
        static std::map<String, CRGBPalette16> m_palettes;
};

#endif // __DEFINED_PATTERNPALETTES_H