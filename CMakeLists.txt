cmake_minimum_required(VERSION 3.5.0)
project(Snake VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()


set(SDL2_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake/SDL2)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
add_executable(Snake main.cpp)
target_link_libraries(Snake ${SDL2_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
