find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(app)

target_sources(app
    PRIVATE
    main.cpp
    )

target_link_libraries(app
    PRIVATE
    plugin-if
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    )
