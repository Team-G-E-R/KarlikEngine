project(KarlikEngineCore)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

add_library(KarlikEngineCore ${SOURCES})
target_include_directories(KarlikEngineCore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_precompile_headers(KarlikEngineCore PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/pch.h")

target_compile_definitions(KarlikEngineCore PUBLIC GLEW_STATIC)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(KarlikEngineCore PUBLIC fmt::fmt)

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(KarlikEngineCore PUBLIC spdlog::spdlog)

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(KarlikEngineCore PUBLIC SDL3::SDL3)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(KarlikEngineCore PUBLIC OpenGL::GL)
target_link_libraries(KarlikEngineCore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/lib/glew32s.lib")
target_link_libraries(KarlikEngineCore PUBLIC debug "${CMAKE_CURRENT_SOURCE_DIR}/lib/Debug/Coral.Native.lib")
target_link_libraries(KarlikEngineCore PUBLIC optimized "${CMAKE_CURRENT_SOURCE_DIR}/lib/Release/Coral.Native.lib")
target_include_directories(KarlikEngineCore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

#imgui
find_package(imgui CONFIG REQUIRED)
target_link_libraries(KarlikEngineCore PUBLIC imgui::imgui)

# Box2D
find_package(Box2d REQUIRED)
target_link_libraries(KarlikEngineCore PUBLIC box2d::box2d)
