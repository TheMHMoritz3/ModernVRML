include_directories(${PROJECT_BINARY_DIR}/src/)

SET(CMAKE_CXX_STANDARD 17)

add_library(VRMLParser
        Parser/local/component.h
        Parser/local/component.cpp
        Parser/local/conf.h
        Parser/local/conf.cpp
        Parser/local/error.h
        Parser/local/error.cpp
        Parser/local/externproto.h
        Parser/local/externproto.cpp
        Parser/local/field_value_types.h
        Parser/local/float.h
        Parser/local/node_metatype_registry_impl.h
        Parser/local/node_metatype_registry_impl.cpp
        Parser/local/parse_vrml.h
        Parser/local/parse_vrml.cpp
        Parser/local/proto.h
        Parser/local/proto.cpp
        Parser/local/uri.h
        Parser/local/uri.cpp
        Parser/local/xml_reader.h
        Parser/local/xml_reader.cpp
        Parser/vrml97_grammar.h
        Parser/vrml97_grammar.cpp
        Parser/x3d_vrml_grammar.h
        Parser/x3d_vrml_grammar.cpp
        Parser/browser.h
        Parser/browser.cpp
        Parser/script.h
        Parser/script.cpp
        Parser/bad_url.h
        Parser/bad_url.cpp
        Parser/basetypes.h
        Parser/basetypes.cpp
        Parser/bounding_volume.h
        Parser/bounding_volume.cpp
        Parser/event.h
        Parser/exposedfield.h
        Parser/exposedfield.cpp
        Parser/field_value.h
        Parser/field_value.cpp
        Parser/frustum.h
        Parser/frustum.cpp
        Parser/node.h
        Parser/node.cpp
        Parser/node_impl_util.h
        Parser/node_impl_util.cpp
        Parser/openvrml-common.h
        Parser/rendering_context.h
        Parser/rendering_context.cpp
        Parser/scene.h
        Parser/scene.cpp
        Parser/viewer.h
        Parser/viewer.cpp
        Parser/local/dl.h
        Parser/local/dl.cpp
        )

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