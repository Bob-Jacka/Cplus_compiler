#pragma once

#ifndef UTILFUNCS.HPP
#define UTILFUNCS.HPP

#include <variables.hpp>
#include <termcolor.hpp>

// System defined exit symbol
#if defined(_WIN32) || defined(_WIN64)
    #define NEW_LINE "\r\n"
#elif defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    #define NEW_LINE "\n"
#endif

inline bool contains(string &source, string string_if_contains) {
    return *source.find(string_if_contains);
}

inline void colored_txt_output(string str) {
    // return termcolor::c
}


#endif UTILFUNCS.HPP