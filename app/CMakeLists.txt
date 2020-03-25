find_package(Qt5 COMPONENTS Core Gui Qml Widgets QuickCompiler REQUIRED)

add_executable(app)

qtquick_compiler_add_resources(RESOURCES
    app.qrc
    )

target_sources(app
    PRIVATE
    main.cpp
    ${RESOURCES}
    )

target_link_libraries(app
    PRIVATE
    plugin-if
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Qml
    )
