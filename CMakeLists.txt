cmake_minimum_required(VERSION 3.19)
project(2D_Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(2D_Game main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.5.1/include)

target_link_libraries(2D_Game sfml-system sfml-window sfml-graphics sfml-audio)