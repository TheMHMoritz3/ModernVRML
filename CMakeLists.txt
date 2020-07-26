cmake_minimum_required(VERSION 3.15)

project(ModernVRML VERSION 0.0.1 DESCRIPTION "mylib description")

include(GNUInstallDirs)

enable_testing()

find_package( Threads )

if(!WIN32)
    find_package(Boost 1.72.0 REQUIRED)
endif()

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}" ${CMAKE_MODULE_PATH})

include_directories(${PROJECT_SOURCE_DIR}/src ${PROJECT_BINARY_DIR}/src)

add_subdirectory(src)


configure_file(ModernVRML.pc.in ${CMAKE_BINARY_DIR}/ModernVRML.pc)
install(FILES ${CMAKE_BINARY_DIR}/ModernVRML.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
