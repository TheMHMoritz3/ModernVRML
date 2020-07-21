cmake_minimum_required(VERSION 3.17)

project(ModernVRML VERSION 0.0.1 DESCRIPTION "mylib description")

include(GNUInstallDirs)
include_directories(${PROJECT_SOURCE_DIR}/src ${PROJECT_BINARY_DIR}/src)

enable_testing()

find_package( Threads )

find_package(Boost 1.72.0 REQUIRED)

add_subdirectory(src)

configure_file(ModernVRML.pc.in ${CMAKE_BINARY_DIR}/ModernVRML.pc)
install(FILES ${CMAKE_BINARY_DIR}/ModernVRML.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)