project(KarlikEngineEditor)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

add_executable(KarlikEngineEditor ${SOURCES})
set_target_properties(KarlikEngineEditor PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

target_precompile_headers(KarlikEngineEditor PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/pch.h")

target_link_libraries(KarlikEngineEditor PRIVATE KarlikEngineCore)
