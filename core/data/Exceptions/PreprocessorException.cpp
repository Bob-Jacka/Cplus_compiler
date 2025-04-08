#include <BaseException.hpp>

class PreprocessorException : public BaseException {

public:
void WrongDirective();
};

void PreprocessorException::WrongDirective()
{
    //
}
