#pragma once

#ifndef BASE_EXCEPTION.HPP
#define BASE_EXCEPTION .HPP

#include <exception>
#include <Variables.hpp>
#include <iostream>

class BaseException : std::exception
{
public:
    BaseException() {};
    virtual ~BaseException() {};

private:
    string message;
    string calling_class;

public:

    BaseException(const string &msg, const string &call_class) : message(msg), calling_class(call_class) {}

    /*
       Base method for receiving message about error.
    */
    string message() const noexcept
    {
        return message.c_str();
    }

    /*
        Method for getting calling class of exeption.
    */
    string get_calling_class() {
        return calling_class;
    }
};

#endif BASE_EXCEPTION.HPP