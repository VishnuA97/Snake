cmake_minimum_required(VERSION 3.5.0)
project(Snake VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()


set(SDL2_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake/SDL2)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB_RECURSE MY_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(Snake ${MY_SRC} )

target_link_libraries(Snake ${SDL2_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
