#pragma once

#ifndef BASE_EXCEPTION.HPP
#define BASE_EXCEPTION.HPP

#include <exception>
#include <Variables.hpp>

class BaseException : public std::exception {
private:
    string message;

public:
    BaseException(const string& msg) : message(msg) {}
    
    const string what() const noexcept override {
        return message.c_str();
    }
};

#endif BASE_EXCEPTION.HPP