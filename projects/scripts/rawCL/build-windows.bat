@echo off
REM build-windows.bat 0.0.2 for raylib build demonstration test
REM must have x64 Native Command Prompt (preferred) and navigate here
REM    to perform the batch script and all the building it does.
REM Change your executable name here
set GAME_NAME=app/app.exe

REM Set your sources here (relative paths!)
REM Example with two source folders:
REM set SOURCES=src\*.c src\submodule\*.c
set SOURCES=*.c

REM Set your raylib\src location here (relative path!)
set RAYLIB_SRC=..\..\..\raylib\src


REM Consider 3 compiler invocations: building raylib (which
REM is maybe not done), building
REM src/*.c files, and linking together those two.



:BUILD
REM Directories
set "ROOT_DIR=%CD%"
set "SOURCES=!ROOT_DIR!\!SOURCES!"
set "RAYLIB_SRC=!ROOT_DIR!\!RAYLIB_SRC!"

REM Flags
set OUTPUT_FLAG=/Fe: "!GAME_NAME!"
set COMPILATION_FLAGS=/O1 /GL
set WARNING_FLAGS=
set SUBSYSTEM_FLAGS=/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup
set LINK_FLAGS=/link /LTCG kernel32.lib user32.lib shell32.lib winmm.lib gdi32.lib opengl32.lib
set OUTPUT_DIR=builds\windows-msvc
REM Debug changes to flags


REM Display what we're doing
IF DEFINED BUILD_DEBUG (
  IF NOT DEFINED QUIET echo COMPILE-INFO: Compiling in debug mode, flags: !COMPILATION_FLAGS! !WARNING_FLAGS!
) ELSE (
  IF NOT DEFINED QUIET echo COMPILE-INFO: Compiling in release mode, flags: !COMPILATION_FLAGS! /link /LTCG
)

REM Create the temp directory for raylib
set "TEMP_DIR=temp\release"
IF DEFINED BUILD_DEBUG (
  set "TEMP_DIR=temp\debug"
)



REM Build raylib if it hasn't been cached in TEMP_DIR
IF NOT EXIST !TEMP_DIR!\ (
  mkdir !TEMP_DIR!
  cd !TEMP_DIR!
  REM Raylib's src folder
  set "RAYLIB_DEFINES=/D_DEFAULT_SOURCE /DPLATFORM_DESKTOP /DGRAPHICS_API_OPENGL_33"
  set RAYLIB_C_FILES="!RAYLIB_SRC!\core.c" "!RAYLIB_SRC!\shapes.c" "!RAYLIB_SRC!\textures.c" "!RAYLIB_SRC!\text.c" "!RAYLIB_SRC!\models.c" "!RAYLIB_SRC!\utils.c" "!RAYLIB_SRC!\raudio.c" "!RAYLIB_SRC!\rglfw.c"
  set RAYLIB_INCLUDE_FLAGS=/I"!RAYLIB_SRC!" /I"!RAYLIB_SRC!\external\glfw\include"

  IF DEFINED REALLY_QUIET (
    cl.exe /w /c !RAYLIB_DEFINES! !RAYLIB_INCLUDE_FLAGS! !COMPILATION_FLAGS! !RAYLIB_C_FILES! > NUL 2>&1 || exit /B
  ) ELSE (
    cl.exe /w /c !VERBOSITY_FLAG! !RAYLIB_DEFINES! !RAYLIB_INCLUDE_FLAGS! !COMPILATION_FLAGS! !RAYLIB_C_FILES! || exit /B
  )
  IF NOT DEFINED QUIET echo COMPILE-INFO: Raylib compiled into object files in: !TEMP_DIR!\

  REM Out of the temp directory
  cd !ROOT_DIR!
)

REM Move to the build directory
IF NOT EXIST !OUTPUT_DIR! mkdir !OUTPUT_DIR!
cd !OUTPUT_DIR!

REM Build the actual game
IF NOT DEFINED QUIET echo COMPILE-INFO: Compiling game code.
IF DEFINED REALLY_QUIET (
  cl.exe !VERBOSITY_FLAG! !COMPILATION_FLAGS! !WARNING_FLAGS! /c /I"!RAYLIB_SRC!" !SOURCES! > NUL 2>&1 || exit /B
  cl.exe !VERBOSITY_FLAG! !OUTPUT_FLAG! "!ROOT_DIR!\!TEMP_DIR!\*.obj" *.obj !LINK_FLAGS! !SUBSYSTEM_FLAGS! > NUL 2>&1 || exit /B
) ELSE (
  cl.exe !VERBOSITY_FLAG! !COMPILATION_FLAGS! !WARNING_FLAGS! /c /I"!RAYLIB_SRC!" !SOURCES! || exit /B
  cl.exe !VERBOSITY_FLAG! !OUTPUT_FLAG! "!ROOT_DIR!\!TEMP_DIR!\*.obj" *.obj !LINK_FLAGS! !SUBSYSTEM_FLAGS! || exit /B
)
del *.obj
IF NOT DEFINED QUIET echo COMPILE-INFO: Game compiled into an executable in: !OUTPUT_DIR!\

REM Run upx
IF DEFINED UPX_IT (
  IF NOT DEFINED QUIET echo COMPILE-INFO: Packing !GAME_NAME! with upx.
  upx !GAME_NAME! > NUL 2>&1
)

REM Finally, run the produced executable
IF DEFINED RUN_AFTER_BUILD (
  IF NOT DEFINED QUIET echo COMPILE-INFO: Running.
  IF DEFINED REALLY_QUIET (
    !GAME_NAME! > NUL 2>&1
  ) ELSE (
    !GAME_NAME!
  )
)

REM Back to development directory
cd !ROOT_DIR!

IF NOT DEFINED QUIET echo COMPILE-INFO: All done.
