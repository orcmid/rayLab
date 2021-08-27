<!-- index.md 0.0.0                UTF-8                          2021-08-27
              X210802: INSTALLING RAYLIB INSIDE WINDOWS PROJECTS
     -->

# Experiment X210802: Installing raylib Inside Windows Projects

## Synopsis

It's useful to include the raylib code inside of a project that relies on
raylib for graphical functions.  This will have the raylib code compiled along
with that of the containing project.  This streamlined operation eliminates
the complicated matching of compilation options between a project and
a separate (shared) library.  The cost of including unused raylib components
is minimal.

The raylib code should not be touched in the project.  It will simply be
carried inside the project so that the dependency is internal.  It will also
be convenient for updating to a newer raylib version and confirming that
the overall project continues to build properly.  This works best if the
raylib-depending project is also managed with git (and optionally, GitHub).

Using orcmid/rayLab for illustration, the goal is to have an arrangement
of a raylib release similar to how it appears within this Windows File
Explorer view.

![rayLab with raylib inside](X210802-2021-08-26-2014-TheResult.png)

<!-- 0.0.0 2021-08-27T18:45Z Draft placeholder of the confirmed setup.
     -->
