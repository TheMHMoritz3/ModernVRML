cmake_minimum_required(VERSION 3.17)

project(ModernVRML CXX)

include_directories(${PROJECT_SOURCE_DIR}/src ${PROJECT_BINARY_DIR}/src)

enable_testing()

find_package( Threads )

find_package(Boost 1.72.0 REQUIRED)

add_subdirectory(src)
