/* nfoGetVHelper.c 0.0.1            UTF-8                          2023-10-14
 * -|----1----|----2----|----3----|----4----|----5----|----6----|----7----|--*

                       SIMPLE WINDOWS VERSION CHECK #2

   The program uses the Windows VersionHelpers functions to confirm that
   Windows Version 7 or better is present.  This does not establish that
   anything more recent than Windows 8 is present because of this program
   (and basic raylib apps) not having version-specifying manifests.

   The presumption is that Windows Version Helpers will continue to be
   provided even if GetVersion is deprecated sometime at or beyond Windows 11.
      */

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <VersionHelpers.h>

int main(void)
{  fputs("nfoGetVHelper 0.0.1> Simple Version Helper Check\n\n", stdout);

   if (IsWindows7OrGreater())
        fputs("    Windows 7 or better is present.\n\n", stdout);
   else fputs("    Windows 7 or better is not present.\n\n", stdout);

   }

/*
 *  0.0.1  2023-10-14T22:03Z Skeleton to confirm Version Helper function.
 *
 *                 *** end of nfoGetVHelper.c ***
 */
