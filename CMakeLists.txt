cmake_minimum_required(VERSION 3.19)
project(multimedia-video-modify-orientation LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Quick Multimedia MultimediaWidgets)

qt_standard_project_setup()

add_subdirectory(qvideowidgetdesignerplugin)

qt_add_executable(multimedia-video-modify-orientation
    WIN32 MACOSX_BUNDLE
    appconfig.h
    appconfig.cpp
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    rotationfiltersink.h
    rotationfiltersink.cpp
)

set(QML_IMPORT_PATH ${CMAKE_CURRENT_BINARY_DIR}/multimedia-video-modify-orientation )

qt_add_qml_module(multimedia-video-modify-orientation
    URI multimediaVideoModifyOrientation
    VERSION 1.0
    QML_FILES
        Main.qml
        RotatedVideoItem.qml
)

target_link_libraries(multimedia-video-modify-orientation
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Quick
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
