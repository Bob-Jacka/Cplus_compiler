#include <BaseException.hpp>

class LexerException : BaseException {

public:
    static int WrongValueType();
    static int WrongFunctionType();
    static int ErrorInOpenFile();
};

int LexerException::WrongValueType()
{
    std::cerr << "Wrong type error occurred";
    return 0;
}

int LexerException::WrongFunctionType()
{
    std::cerr << "Wrong function type error occurred";
    return 0;
}

int LexerException::ErrorInOpenFile() {
    std::cerr << "Error in opening file for analyze";
    return 0;
}
