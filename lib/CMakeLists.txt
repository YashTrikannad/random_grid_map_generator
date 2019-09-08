add_library(generator INTERFACE)

target_sources(generator INTERFACE generator.h)

target_include_directories(generator INTERFACE
        "${PROJECT_SOURCE_DIR}/lib"
        )