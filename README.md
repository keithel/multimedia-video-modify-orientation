# Qt Multimedia Video - Modify Orientation Example

This is an example showing how to rotate Qt Multimedia video in both a Qt Widgets application, and a
Qt Quick application.

## How to Build

To build this example, install Qt 6.2+ (Qt 6.8+ recommended) on your machine - you can get it from
https://qt.io/ or by installing it from your package manager on Linux.

Qt Creator is also recommended, but you can build it without Qt Creator.

If you use Qt Creator, simply open up the CMakeLists.txt project file,
Select a Qt version >= Qt 6.2, when the new Qt Multimedia was introduced.

If you are not using Qt Creator, create a directory to hold the build and change to it
(`mkdir build; cd build`)

Run `qt-cmake` from the `<Qt base>/<Qt version>/<compilerver>/bin` directory, handing it the
directory where the CMake project file is:
`qt-cmake ..`

Build it using cmake:
`cmake --build .`

You should now have an executable `multimedia-video-modify-orientation` at the base of the `build`
directory.

## Prerequisites for running

You need to have a video to play. You can pass one on the command line, or you can use the default
`big_buck_bunny_1080p_h264.mov`. If you want to play Big Buck Bunny, you must download it - I have
not included it.

You can find it at: https://download.blender.org/peach/bigbuckbunny_movies/

## Running the example

To run, just start the executable without arguments. If you want to play your own video, you can
supply a path or URL to it on the command line.

## What is qvideowidgetdesignerplugin ?

`qvideowidgetdesignerplugin` is a plugin for Qt Designer - the wysiwyg Qt Widgets designer adding
the Qt Multimedia `QVideoWidget` to the Widget Box, So that it can be dragged, dropped, and
manipulated easily in the Qt Designer user interface. More information in [its README.md file]
(qvideowidgetdesignerplugin/README.md).
