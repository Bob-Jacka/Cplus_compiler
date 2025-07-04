/*
 Header file with useful aliases
 */

#pragma once

#include <string>

//Some user defined types.

using file = std::ifstream;
using out_file = std::ofstream;
using string = std::string; //alias for strings if you do not want to use 'using namespace std;'
using const_string = const std::string;
using const_int = const int;
using cstr = const std::string;

using c_string = char *;
using cconst_string = const char *;
