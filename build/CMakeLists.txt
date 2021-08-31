cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(intersec VERSION 1.0)

include_directories(${CMAKE_SOURCE_DIR})
file (GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/../src/*.cpp 
)

add_executable(intersec ${SRC_FILES})

target_include_directories(intersec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)