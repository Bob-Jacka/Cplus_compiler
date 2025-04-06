#include <exception>
#include <Variables.hpp>

class BaseException : public std::exception {
private:
    std::string message;

public:
    BaseException(const std::string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};