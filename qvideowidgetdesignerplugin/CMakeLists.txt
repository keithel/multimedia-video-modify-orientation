find_package(Qt6 6.5 REQUIRED COMPONENTS Widgets Designer MultimediaWidgets)

qt_add_plugin(QVideoWidgetDesignerPlugin
    qvideowidgetdesignerplugin.h
    qvideowidgetdesignerplugin.cpp
)

qt_add_resources(QVideoWidgetDesignerPlugin
    PREFIX "/"
    FILES
        "images/qvideowidget.png"
)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(LIB_RPATH "\$ORIGIN")
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(LIB_RPATH "@loader_path")
else()
    set(LIB_RPATH "")
endif()

if(NOT "${LIB_RPATH}" STREQUAL "")
    set_target_properties(QVideoWidgetDesignerPlugin PROPERTIES
        INSTALL_RPATH "${LIB_RPATH}"
        BUILD_WITH_INSTALL_RPATH TRUE
    )
endif()

target_link_libraries(QVideoWidgetDesignerPlugin PRIVATE
    Qt::Widgets
    Qt::Designer
    Qt::MultimediaWidgets
)
