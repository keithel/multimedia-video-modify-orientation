# qvideowidgetdesignerplugin

A plugin for Qt Designer adding QVideoWidget to the Widget Box

## Building

To build, open the parent project CMakeLists.txt file with Qt Creator, select your Qt, and build.

Make sure that you are building with Qt 6 (or the major version that Qt Creator is built against if
this is being read after Qt 7 is released).

## Installing

To install this, you need to copy the generated libQVideoWidgetDesignerPlugin.so (or
QVideoWidgetDesignerPlugin.dll if you are on windows -- **untested**) to `<path where Qt Creator is
installed>/lib/Qt/plugins/designer`.

Additionally, you need to copy the Qt Multimedia and Qt Multimedia Widgets libraries to the same
directory, as Qt Creator does not use Qt Multimedia normally, and doesn't package it.
The two library files to copy are:
* libQt6Multimedia.so.6
* libQt6MultimediaWidgets.so.6

Qt Creator is installed by default by the Qt Installer you get from https://qt.io in the directory
`~/Qt/Tools/QtCreator` on Linux and macOS, or `C:/Qt/Tools/QtCreator` on Windows.


