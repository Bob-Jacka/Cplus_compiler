#include <BaseException.hpp>

class LexerException : BaseException {

public:
    void WrongValueType();
    void WrongFunctionType();
    void ErrorInOpenFile();
};

void LexerException::WrongValueType()
{
    std::cerr << "Wrong type error occurred";
}

void LexerException::WrongFunctionType()
{
    std::cerr << "Wrong function type error occurred";
}

void LexerException::ErrorInOpenFile() {
    std::cerr << "Error in opening file for analyze";
}
