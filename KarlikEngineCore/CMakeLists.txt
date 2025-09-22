project(KarlikEngineCore)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

add_executable(KarlikEngineCore ${SOURCES})
target_precompile_headers(KarlikEngineCore PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/pch.h")

target_compile_definitions(KarlikEngineCore PRIVATE GLEW_STATIC)

target_link_libraries(KarlikEngineCore PUBLIC SDL3::SDL3)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(KarlikEngineCore PRIVATE OpenGL::GL)
target_link_libraries(KarlikEngineCore PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/lib/glew32s.lib")
target_include_directories(KarlikEngineCore PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
