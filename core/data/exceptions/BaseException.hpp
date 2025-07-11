#ifndef BASE_EXCEPTION_HPP
#define BASE_EXCEPTION_HPP

#include <exception>
#include "../Variables.hpp"
#include <utility>
#include <ostream>
#include <iostream>
#include "../Custom_operators.hpp"

/*
 Base class for exceptions in C+ compiler
 */
class BaseException : std::exception {
inherited:
    string exc_message;
    string calling_class;

global:
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

#endif
