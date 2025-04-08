#include <BaseException.hpp>

class LexerException : public BaseException {

    public:
    void WrongValueType();
    void WrongFunctionType();
};

void LexerException::WrongValueType()
{
    //
}

void LexerException::WrongFunctionType()
{
    //
}
