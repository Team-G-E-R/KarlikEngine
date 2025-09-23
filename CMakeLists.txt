cmake_minimum_required(VERSION 3.21)
project(KarlikEngine)

set(CMAKE_CXX_STANDARD 23)
set(SDL_SHARED OFF)
set(SDL_STATIC ON)

add_subdirectory(KarlikEngineCore)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT KarlikEngineCore)
