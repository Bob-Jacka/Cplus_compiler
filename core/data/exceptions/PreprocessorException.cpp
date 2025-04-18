#include <BaseException.hpp>

class PreprocessorException : BaseException {

public:
void WrongDirective();
};

void PreprocessorException::WrongDirective()
{
    std::cerr << "Wrong preprocessor directive found";
}
