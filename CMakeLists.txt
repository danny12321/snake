cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("snake")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)
#file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} src/Grid.cpp src/Grid.h src/grid/SnakeBody.cpp src/grid/SnakeBody.h src/Game.cpp src/Game.h src/grid/Candy.cpp src/grid/Candy.h src/grid/GridItem.cpp src/grid/GridItem.h src/Directions.h)
target_link_libraries(${CMAKE_PROJECT_NAME} ${CONAN_LIBS})