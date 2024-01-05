/* nfoPixels.c 0.0.0                UTF-8                         2024-01-05
 * -|----1----|----2----|----3----|----4----|----5----|----6----|----7----|--*
 *
 *                    STUB NFOPIXELS STUB DEFINITIONS
 *                    ===============================
 *
 *   This is a small demonstration of the technique used to isolate platform
 *   (and windows.h) dependencies in nfoPixel, eliminating any (conflicting)
 *   use of platform-function names with libraries such as raylib.
 */

#include "nfoPixels.h"

#include <windows.h>
         // for USER_DEFAULT_SCREEN_DPI

int npxDpiDefault(void)
  {
    return USER_DEFAULT_SCREEN_DPI;
    // the system default DPI for desktop display devices.
    // This is specific to the Windows case.
    }


/*
 *  0.0.0 2024-01-05T19:19Z Demonstration Stub
 *
 *                   *** end of nfoPixels.c ***                      */
