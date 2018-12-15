#ifndef __DEFINED_GRADIENTPALETTES_H
#define __DEFINED_GRADIENTPALETTES_H

#include <map>
#include "config.h"

class GradientPalettes
{
    public:
        static CRGBPalette16& get(String paletteName);

    private:
        static void initialize();

        static bool m_initialized;
        static std::map<String, CRGBPalette16> m_palettes;
};

#endif // __DEFINED_GRADIENTPALETTES_H