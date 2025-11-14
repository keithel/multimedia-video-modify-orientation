cmake_minimum_required(VERSION 3.19)
project(multimedia-video-modify-orientation LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Multimedia MultimediaWidgets)

qt_standard_project_setup()

add_subdirectory(qvideowidgetdesignerplugin)

qt_add_executable(multimedia-video-modify-orientation
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    rotationfiltersink.h rotationfiltersink.cpp
)

target_link_libraries(multimedia-video-modify-orientation
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Multimedia
        Qt::MultimediaWidgets
)

include(GNUInstallDirs)

install(TARGETS multimedia-video-modify-orientation
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET multimedia-video-modify-orientation
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
