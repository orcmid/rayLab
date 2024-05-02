/* nfoPixels.h 0.0.1                UTF-8                         2024-05-01
 * -|----1----|----2----|----3----|----4----|----5----|----6----|----7----|--*
 *
 *                    STUB NFOPIXELS API DECLARATIONS
 *                    ===============================
 *
 *   This is a preliminary skeleton of the technique used to isolate platform
 *   (and windows.h) dependencies for run-time adaptation to DPI scaling
 *   and other characteristics of the desktop display being used.
 *
 *   Not all of these functions are currently implemented.  This is a stub
 *   while the ideas are being worked out and feasible solutions are found.
 *
 *   The nfoPixels API is intended to be simple, lightweight, and portable.
 *
 *   The nfoPixels operations are independent of graphical libraries, such as
 *   raylib.  nfoPixels depends only on native OS functions and there are no
 *   collisions with other libraries and uses of desktop displays.
 *
 *   IMPORTANT: nfoPixels is limited to use with pixel-unit graphical APIs
 *       and their drawing operations. It provides for scaling of pixel-unit
 *       parameters to automatically accomodate run-time differences of
 *       monitor DPI values in a single executable for a given platform.
 *
 *   DIFFICULTIES: There is a difference between pixel specifications of
 *       height and width expectations and pixel specification of coordinates.
 *       Although nfoPixels functions can be used to correctly scale either
 *       type of pixel number, the application does have to be aware
 *       that some values provided by graphical operations may need to be
 *       "descaled" to the DpiAssumption.
 *
 *       nfoPixel protects against scaled values for lengths and coordinates
 *       that would be out of the actual monitor's range by clamping some
 *       scaled values to remain within the actual monitor's range.
 *
 *       it is also desirable to carry out some drawing operations in the
 *       actual screen resolution in order to gain as much smoothness as
 *       possible in the drawing and movement of shapes.
 *
 *       Guidance for these challenges will be investigated.  The goal is to
 *       avoid surprising and not-understood edge cases for users by having
 *       nfoPixels work as simple as possible but not invisibly.
 *
 *   PERFORMANCE CONSIDERATION: The pixel-unit translations for scaling are
 *       all carried out using integer arithmetic.  In cases where scaling
 *       is not needed, values will be returned unchanged. Scaling is also not
 *       over-precise although consistent and not more than 10% below the
 *       target DpiAssumption.  All rounding is toward 0 to avoid exceeding
 *       the specified bounds for the display widnow, whether full-screen or
 *       smaller.
 */

#ifdef __cplusplus
extern "C" {
#endif

int npxDpiDefault(void);
    // Return the system default DPI for desktop display devices.

int npxSetDpiAssumption(int dpi);
    //     dpi is the dpi that pixel-unit operations of the application
    //         are intended to apply to.  Otherwise, nfoPixels functions
    //         will default to an assumed npxDpiDefault() scaled by 1.
    //
    //  result is the actual DPI that nfoPixel is set to scale toward, but
    //         never less than npxDpiDefault().
    //
    // An application may be created under the assumption of a particular
    // DPI setting.  This function allows the application to specify what
    // that assumption is so that scaling to a different actual DPI can
    // be automated.
    //
    //  CAVEAT: nfoPixels only scales pixel measured-units up, never down.
    //
    //  CAVEAT: nfoPixels does not detect monitor changes and uses the
    //          current monitor (usually where the OS cursor is at the
    //          times npxSetDpiAssumption() and npxRecalibrate() are
    //          called.

int npxRecalibrate(void);
    // Recalibrate the nfoPixels scaling factor for the current monitor.
    // This is useful when the application is moved to a different monitor
    // or the monitor's DPI setting is changed.
    //
    //  result is the actual DPI that nfoPixel is now set to scale toward
    //         based on the current DpiAssumption.
    //
    //  CAVEAT: nfoPixels does not detect any changes in the current monitor.
    //          It also has no hand in how drawing needs to be quickly
    //          adjusted/re-done upon changes of display monitor and/or its
    //          characteristics.


#ifdef __cplusplus
}
#endif

/*
 *  0.0.1 2024-05-01T20:08Z Add some preliminary functions and comments.
 *  0.0.0 2024-01-05T19:02Z Demonstration Stub
 *
 *                   *** end of nfoPixels.h ***                      */
