#pragma once

#ifndef UTILFUNCS.HPP
#define UTILFUNCS .HPP

#include <Variables.hpp>
#include <termcolor.hpp>

// System defined exit symbol
#if defined(_WIN32) || defined(_WIN64)
#define NEW_LINE "\r\n"
#elif defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
#define NEW_LINE "\n"
#endif

using namespace std;

inline bool contains(string &source, string string_if_contains)
{
    return *source.find(string_if_contains);
}

inline void colored_txt_output(string str = "", string color = "white")
{
    switch (color)
    {
    case "white":
        cout << termcolor::white;
        break;
    case "red":
        cout << termcolor::red;
        break;
    case "blue":
        cout << termcolor::blue;
        break;
    case "green":
        cout << termcolor::green;
        break;
    default:
        cout << "Color do not specified.";
        break;
    }
    cout << str;
    cout << termcolor::nocolor;
}

#endif UTILFUNCS.HPP