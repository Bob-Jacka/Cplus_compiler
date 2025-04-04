#pragma once

#ifndef LOAD_DATA.HPP
#define LOAD_DATA.HPP

#include <variables.hpp>

//Структура для параметров загрузки.
struct Load_parameter
{
    string is_assembler;
    string is_cplus_only;
};

Load_parameter load_parameter = Load_parameter{};

#endif LOAD_DATA.HPP