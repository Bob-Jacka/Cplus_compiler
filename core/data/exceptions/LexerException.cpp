#include <BaseException.hpp>

class LexerException : public BaseException {

    public:
    void WrongValueType();
    void WrongFunctionType();
};

void LexerException::WrongValueType()
{
    std::cerr << "Wrong type error occurred";
}

void LexerException::WrongFunctionType()
{
    std::cerr << "Wrong function type error occurred";
}
