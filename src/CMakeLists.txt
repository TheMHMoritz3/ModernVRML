include_directories(${PROJECT_BINARY_DIR}/src/)

SET(CMAKE_CXX_STANDARD 17)

add_library(VRMLParser
        Parser/vrml97_grammar.h
        Parser/vrml97_grammar.cpp
        Parser/x3d_vrml_grammar.h
        Parser/x3d_vrml_grammar.cpp)

if(WIN32)
    target_compile_features(VRMLParser PUBLIC cxx_std_17)
    set_property(TARGET VRMLParser PROPERTY CXX_STANDARD 17)
else()
    target_compile_features(VRMLParser PUBLIC cxx_std_17)
    set_property(TARGET VRMLParser PROPERTY CXX_STANDARD 17)
endif()

target_compile_options(VRMLParser PRIVATE
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:-Wall -Werror>
        $<$<CXX_COMPILER_ID:MSVC>:/W4>)

include_directories(${PROJECT_BINARY_DIR})

target_link_libraries(VRMLParser
        Threads::Threads)

set_target_properties(VRMLParser PROPERTIES VERSION ${PROJECT_VERSION})

set_target_properties(VRMLParser PROPERTIES SOVERSION 0)

target_include_directories(VRMLParser PRIVATE Parser/)


install(TARGETS VRMLParser
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})