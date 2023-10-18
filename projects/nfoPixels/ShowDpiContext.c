/* ShowDPIContext.c 1.0.0           UTF-8                         2023-10-18
 * -|----1----|----2----|----3----|----4----|----5----|----6----|----7----|--*
 *
 *             SHOW DPI CONTEXT INFORMATION FOR WINDOWS
 *             ========================================
 *
 *      Program to report on selected compiler definitions that were
 *      set or not when it was compiled.
 *
 *      Compile this program as a console application in any configura-
 *      tion of a C Language compiler.  Execution of the program prints a
 *      a list of selected pre-processor variables with either their
 *      value, the notation "is defined" or the notation "undefined".
 *
 *   Further details and additional customizations are available at
 *   <https://orcmid.github.io/nfoTools/dev/D230201>.
 */

#include <stdio.h>
      /* for stdout, fputs() and fputc() */
#include <string.h>
      /* for strlen() */

#include <windows.h>
         /* for DPI_AWARENESS_CONTEXT_... and WM_DPICHANGED */

#define TV(X) #X ""
      /* Always produce a string, even when X is empty */

#define SHOW(X, SP) fputs(SP #X " ", stdout);  \
                    fputs( ( tv = TV(X), \
                             strlen(tv) == 0 \
                                ? "is defined" \
                                : strcmp(tv, #X) == 0 \
                                     ? "undefined" \
                                     : TV(=X) ), \
                           stdout); \
                    fputc('\n', stdout);

      /* See the <https://orcmid.github.io/nfoTools/dev/D230201>
         documentation for ways to compile the program and to discover
         the settings that were applied at compile time.

         **** IMPORTANT: The handling of TV(X) and #-stringification
              is not portable among all compilers.  The usage has been
              confirmed only with recent VC/C++ compilers.
         */

#ifdef _MSC_VER
#pragma warning(disable: 4003)
   /* Do not warn about TV(x) when not enough parameters (i.e., x empty) */
#endif


int main(void)
   {/* Report the status of predefined pre-processor variables that
       were defined or not when this program was compiled.
       */

       char *tv;  /* pointer to the token value string */

       fputs(  "\nShowDpiContext> 1.0.0 "
               "Inspection for DPI Context Information\n\n",
              stdout);

       SHOW(USER_DEFAULT_SCREEN_DPI, "                     ");
       SHOW(WM_DPICHANGED, "                               ");
       SHOW(DPI_AWARENESS_CONTEXT, "                       ");
       SHOW(DPI_AWARENESS_CONTEXT_UNAWARE, "               ");
       SHOW(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE, "          ");
       SHOW(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE, "     ");
       SHOW(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2, "  ");
       SHOW(DPI_AWARENESS_CONTEXT_UNAWARE_GDISCALED, "     ");


       fputs("\n  Only when compiled as C++:\n", stdout);
       SHOW(__cplusplus, "             ");
       SHOW(_MSVC_LANG, "              "); // VC/C++ specific

       /* This is the initial list on behalf of nfoPixel development.
          */

       DPI_AWARENESS_CONTEXT dpiContext = GetThreadDpiAwarenessContext();
                // It's a HANDLE type.

       DPI_AWARENESS dpiHere
                        = GetAwarenessFromDpiAwarenessContext(dpiContext);

       switch (dpiHere)
          {
          case DPI_AWARENESS_UNAWARE:
             fputs("\n  DPI_AWARENESS_UNAWARE\n", stdout);
             break;
          case DPI_AWARENESS_SYSTEM_AWARE:
             fputs("\n  DPI_AWARENESS_SYSTEM_AWARE\n", stdout);
             break;
          case DPI_AWARENESS_PER_MONITOR_AWARE:
             fputs("\n  DPI_AWARENESS_PER_MONITOR_AWARE\n", stdout);
             break;
          default:
             fputs("\n  DPI_AWARENESS_UNKNOWN\n", stdout);
             break;
          }
       return 0;

       } /* main() */


/*
 *  1.0.0  2023-10-18T02:50Z Initial version
 *
 *                   *** end of ShowDpiContext.c ***                      */
