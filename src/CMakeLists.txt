include_directories(${PROJECT_BINARY_DIR}/src/)

SET(CMAKE_CXX_STANDARD 17)

add_library(VRMLParser
        Parser/Shape.cpp
        Parser/Shape.h
        Parser/IComponent.h
        Parser/WorldInfo.cpp
        Parser/WorldInfo.h
        Parser/Document.cpp
        Parser/Document.h
        Parser/Appearance.cpp
        Parser/Appearance.h
        Parser/Material.cpp
        Parser/Material.h
        Parser/Geometry.cpp
        Parser/Geometry.h
        Parser/Vector.h
        Parser/Variable.h
        Parser/Coordinate.cpp
        Parser/Coordinate.h)

if(WIN32)
    target_compile_features(VRMLParser PUBLIC cxx_std_17)
    set_property(TARGET VRMLParser PROPERTY CXX_STANDARD 17)
else()
    target_compile_features(VRMLParser PUBLIC cxx_std_17)
    set_property(TARGET VRMLParser PROPERTY CXX_STANDARD 17)
endif()

target_compile_options(VRMLParser PRIVATE
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:-Wall>
        $<$<CXX_COMPILER_ID:MSVC>:/W4>)

include_directories(${PROJECT_BINARY_DIR})

target_link_libraries(VRMLParser
        Threads::Threads)

#set_target_properties(VRMLParser PROPERTIES VERSION ${PROJECT_VERSION})

#set_target_properties(VRMLParser PROPERTIES SOVERSION 0)

target_include_directories(VRMLParser PRIVATE Parser/)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/Parser/
        DESTINATION include/VRMLParser
        FILES_MATCHING PATTERN "*.h*")

install(TARGETS VRMLParser
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})