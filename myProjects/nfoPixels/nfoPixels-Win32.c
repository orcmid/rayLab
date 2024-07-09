/* nfoPixels-Win32.c 0.1.1          UTF-8                         2025-07-09
 * -|----1----|----2----|----3----|----4----|----5----|----6----|----7----|--*
 *
 *                   NFOPIXELS WIN32 STUB IMPLEMENTATION
 *                   ===================================
 *
 *   This is a small demonstration of the technique used to isolate platform
 *   (and windows.h) dependencies in nfoPixel, eliminating any (conflicting)
 *   use of platform-function names with libraries such as raylib.
 *
 *   First, the name of the file specifies the platform the header-defined
 *   functions are implemented for.  This one is intended for the Win32
 *   platform and employs windows.h.
 *
 *   Note that the header file, nfoPixels.h is used for all platforms. The
 *   compilation of the correct platform-specific implementation is achieved
 *   in the compilation of the appropriate nfoPixels-*.c and linking that
 *   object file into the executable.
 */

#include "nfoPixels.h"

#include <windows.h>
         // for USER_DEFAULT_SCREEN_DPI

unsigned npxDpiDefault(void)
  {
    return USER_DEFAULT_SCREEN_DPI;
    // the system default DPI for desktop display devices.
    // This is specific to the Windows case.
    }


/*
 *  0.1.1 2024-07-09T20:06Z Touch-up and match nfoPixels.h prototypes.
 *  0.1.0 2024-04-30T16:17Z Renaming and description of how platform
 *        dependency is isolated and distinguished.
 *  0.0.0 2024-01-05T19:19Z Demonstration Stub
 *
 *                *** end of nfoPixels-Win32.c ***                      */
