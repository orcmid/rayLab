/* nfoGetVer.c 0.0.1                UTF-8                          2023-10-14
 * -|----1----|----2----|----3----|----4----|----5----|----6----|----7----|--*

                        SIMPLE WINDOWS VERSION CHECK

   The program uses the Windows GetVersionExA function to obtain the reported
   version.  The presumption is that this function continues to be supported
   on Windows 10/11.

   However, the function might indicate Windows 8.1 when there is no
   application manifest, the default for console applications and simple
   raylib builds.
   */

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main(void)
{  fputs("nfoGetVer 0.0.1> Simple Version Check\n\n", stdout);

   // with assistance of GitHub Copilot
   OSVERSIONINFOEXA osvi;
   ZeroMemory(&osvi, sizeof(OSVERSIONINFOEXA));
   osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXA);

   if ( !GetVersionExA( (OSVERSIONINFOA* )&osvi) )
   {    fputs("        **** GetVersionExA failed ****\n\n", stdout);
        exit(EXIT_FAILURE);
   } // if};

   printf("dwMajorVersion: %d\n", osvi.dwMajorVersion);
   printf("dwMinorVersion: %d\n", osvi.dwMinorVersion);
   printf("dwBuildNumber: %d\n", osvi.dwBuildNumber);
   printf("dwPlatformId: %d\n", osvi.dwPlatformId);
   printf("szCSDVersion: %s\n", osvi.szCSDVersion);
   printf("wServicePackMajor: %d\n", osvi.wServicePackMajor);
   printf("wServicePackMinor: %d\n", osvi.wServicePackMinor);
   printf("wSuiteMask: %d\n", osvi.wSuiteMask);
   printf("wProductType: %d\n", osvi.wProductType);
   printf("wReserved: %d\n", osvi.wReserved);

} // main

/*
 *  0.0.1  2023-10-14T20:36Z Skeleton to confirm GetVersionExA function.
 *
 *                        *** end of nfoGetVer.c ***
 */
