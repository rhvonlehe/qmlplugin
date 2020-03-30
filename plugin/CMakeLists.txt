find_package(Qt5 COMPONENTS Qml QuickCompiler REQUIRED)
set(CMAKE_AUTOMOC ON)

add_library(plugin SHARED)

target_include_directories(plugin PUBLIC .)

qtquick_compiler_add_resources(plugin_RESOURCES
    plugin.qrc
    )

target_sources(plugin
    PRIVATE
    Plugin.cpp
    ${plugin_RESOURCES}
    )

target_link_libraries(plugin
    PRIVATE
    plugin-if
    Qt5::Qml
    )

add_custom_command(TARGET plugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/qmldir ${CMAKE_CURRENT_BINARY_DIR}/qmldir
    )
