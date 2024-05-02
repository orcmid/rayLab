/* nfoPixels.h 0.0.3                UTF-8                         2024-05-02
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
 *   CHALLENGES: There is a difference between pixel specifications of
 *       height and width expectations and pixel specification of coordinates.
 *       Although nfoPixels functions can be used to correctly scale either
 *       type of pixel number, the application does have to be aware
 *       that some values returned by graphical-operations may need to be
 *       "descaled" to the DpiAssumption so the application developers do
 *       not have to lose their minds over this.
 *
 *       nfoPixel protects against scaled values for lengths and coordinates
 *       that would be out of the actual monitor's range by clamping some
 *       scaled values to remain within the actual monitor's range.
 *
 *       it is also desirable to carry out some drawing operations in the
 *       actual screen resolution in order to gain as much smoothness as
 *       possible in the drawing and movement of shapes.  This is where the
 *       application developer will have to cope with coordinate system
 *       differences/transformations that might be required.  nfoPixels will
 *       provide sufficient information to make these transformations as
 *       simple as possible.
 *
 *       Another situation to be conquered is the fact that some GPUs and
 *       monitors do some scaling automatically.  The result is generally
 *       unpleasant since the application is unaware that the result can be
 *       distorted.  We need a fail-safe around that.
 *
 *       Guidance for these challenges will be investigated.  The goal is to
 *       avoid surprising and not-understood edge cases for users by having
 *       nfoPixels work as simple as possible but not invisibly.
 *
 *   PERFORMANCE CONSIDERATION: The pixel-unit translations for scaling are
 *       all carried out using integer arithmetic.  In cases where scaling
 *       is not needed, values will be returned unchanged. Scaling is also not
 *       over-precise although consistent and with the visual display not more
 *       than 10% below the target DpiAssumption. All rounding is toward 0 to
 *       avoid exceeding the specified bounds for an application's display
 *       window, whether full-screen or smaller.
 */

#ifdef __cplusplus
extern "C" {
#endif

unsigned long npxDpiDefault(void);
    // Return the system default DPI for desktop display devices.  This is a
    // portability provision related to how application developers might be
    // accustomed to expect a particular automatic display quality.

unsigned long npxSetDpiAssumption(unsigned long dpi);
    //     dpi is the dpi that pixel-unit operations of the application
    //         are intended to apply to.  Otherwise, nfoPixels functions
    //         will default to npxDpiDefault() scaled by 1.
    //
    //  result is the actual DPI that nfoPixel is set to scale toward, but
    //         never less than npxDpiDefault().
    //
    //         If npxSetDpiAssumption() is not performed (yet), nfoPixels
    //         functions operate under the assumption of npxDpiDefault().
    //
    // An application may be created under the assumption of a particular
    // DPI setting.  This function allows the application to specify what
    // that assumption is so that scaling to a different actual DPI can
    // be automated.
    //
    //  CAVEAT: nfoPixels only scales pixel-measured units up, never down.
    //
    //  CAVEAT: nfoPixels does not detect monitor changes and uses the
    //          current monitor (usually where the OS cursor is whenever
    //          npxSetDpiAssumption() and npxRecalibrate() are performed.
    //
    //  WARNING: Although DPIs are generally much smaller than a platform's
    //           MAX_INT value, some of the usages of int instead of
    //           unsigned long operations of nfoPixels may be a problem.

unsigned long npxRecalibrate(void);
    // Recalibrate the nfoPixels scaling factor for the current monitor.
    // This is useful when the application is moved to a different monitor
    // or the monitor's DPI setting is changed.
    //
    //  result is the actual DPI that nfoPixel is now set to scale toward
    //         based on the existing DpiAssumption (possibly the default).
    //
    //  Performing npxSetDpiAssumption() is also a way to recalibrate the
    //  nfoPixels scaling factor for the (now) current monitor.
    //
    //  CAVEAT: nfoPixels does not detect dynamic changes in the current
    //          monitor.  It also has no hand in how drawing needs to be
    //          quickly adjusted/re-done upon changes of display monitor
    //          and/or its settings.

int npxH(int hAssumed);
int npxW(int wAssumed);

    //     hAssumed is the height in pixels that the application is
    //         assuming for a particular drawing parameter.
    //
    //     wAssumed is the width in pixels that the application is
    //         assuming for a particular drawing parameter.
    //
    //  result is the height or width in pixels that the application should
    //         use for the actual drawing operation on the current monitor.
    //
    //  Negative values of hAssumed and wAssumed are silently treated as 0.
    //
    //  EXAMPLE: With raylib, the initialization of a Window can be adapted
    //           to the actual monitor's DPI by using something like
    //
    //           InitWindow(npxW(800), npxH(600), "Hello, World!");
    //
    //           Note that the title bar of the window and the readability
    //           of "Hello, World!" are not handled by nfoPixels.
    //
    //  Although most displays have the same DPI in the horizontal and
    //  vertical directions, nfoPixels allows for there being differences,
    //  requiring different scalings.
    //
    //  CAVEAT: nfoPixels will clamp the results so that actual pixel
    //          dimensions of the assumed current monitor are not exceeded.
    //          This does not correct for the actual pixel dimensions of the
    //          window that the application is drawing to.
    //             Something needs to be done about that.
    //
    //  CAVEAT: To work well with raylib, int units are employed.  Although
    //          longs do not have to be larger than ints, it might be valuable
    //          to deal with actual scaled values being too high for signed
    //          ints.  There does not appear to be an easy remedy apart from
    //          having some alternative API functions and knowing when to use
    //          them.


#ifdef __cplusplus
}
#endif

/*
 *  0.0.3 2024-05-02T19:13Z Add npxH, npxW, with expanded commentary and use
 *        of unsigned long for potentially large values in DPI.
 *  0.0.2 2024-05-02T16:51Z Tweaking of comments
 *  0.0.1 2024-05-01T20:08Z Add some preliminary functions and comments.
 *  0.0.0 2024-01-05T19:02Z Demonstration Stub
 *
 *                   *** end of nfoPixels.h ***                      */
