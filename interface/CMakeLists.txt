find_package(Qt5 COMPONENTS Core)

add_library(plugin-if INTERFACE)

target_include_directories(plugin-if INTERFACE .)

target_sources(plugin-if
    INTERFACE
    )

target_link_libraries(plugin-if
    INTERFACE
    Qt5::Core
    )
