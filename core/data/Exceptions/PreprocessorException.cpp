#include <BaseException.hpp>

class PreprocessorException : public BaseException {

public:
void WrongDirective();
};

void PreprocessorException::WrongDirective()
{
    std::cerr << "Wrong preprocessor directive found";
}
