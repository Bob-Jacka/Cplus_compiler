#include <BaseException.hpp>

class LinkerException : public BaseException {

    public:
    
    /*
    Occurs when error happens in linkage
    */
    void linkageError();
};

void LinkerException::linkageError()
{
    //
}
