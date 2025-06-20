#pragma once

#ifndef BASE_EXCEPTION.HPP
#define BASE_EXCEPTION .HPP

#include <exception>
#include "Variables.hpp"
#include <utility>
#include <iostream>

class BaseException : std::exception {
protected:
    string exc_message;
    string calling_class;

public:
    BaseException() = default;

    ~BaseException() override = default;

    BaseException(string msg, string call_class) : exc_message(std::move(msg)), calling_class(std::move(call_class)) {
    }

    /*
       Base method for receiving message about error.
    */
    [[nodiscard]] string message() const noexcept {
        return exc_message;
    }

    /*
        Method for getting calling class of exception.
    */
    string get_calling_class() {
        return calling_class;
    }
};

#endif BASE_EXCEPTION.HPP
