#pragma once

#ifdef _WIN32
#ifdef VRMLParser_EXPORTS
#define PARSER_EXPORT __declspec(dllexport)
#else
#define PARSER_EXPORT __declspec(dllimport)
#endif // VRMLParser_EXPORTS
#else
#define PARSER_EXPORT
#endif