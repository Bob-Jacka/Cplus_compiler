#include <BaseException.hpp>

class PreprocessorException : BaseException {

public:
    static int wrongDirective(); //if directive is not defined by compiler
    static int wrongDirectiveLine();
};

int PreprocessorException::wrongDirective()
{
    std::cerr << "Wrong preprocessor directive found";
    return 0;
}
