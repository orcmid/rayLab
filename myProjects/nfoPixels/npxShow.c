/* npxShow.c 0.0.0                  UTF-8                         2024-01-05
 * -|----1----|----2----|----3----|----4----|----5----|----6----|----7----|--*
 *
 *                  SHOW nfoPIXEL INFORMATION FOR DESKTOP
 *                  =====================================
 *
 *   This is a small demonstration of the technique used to isolate platform
 *   (and windows.h) dependencies in nfoPixel, eliminating any (conflicting)
 *   use of platform-function names with libraries such as raylib.
 */

#include <stdio.h>
      /* for printf */

#include "nfoPixels.h"

int main(void)

    {  printf("\n\n    nfoPixel Default DPI: %d\n\n", npxDpiDefault());
       // an unadorned simple output for now, hat-tip to co-pilot.

       } /* main() */

/*
 *  0.0.0 2024-01-05T19:13Z Demonstration Stub
 *
 *                   *** end of npxShow.c ***                      */
