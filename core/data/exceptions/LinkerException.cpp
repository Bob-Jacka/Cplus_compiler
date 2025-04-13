#include <BaseException.hpp>

/*
    Occurs when error happens in linkage
    */
class LinkerException : public BaseException {

    public:
    void linkageError();
    void failedAddFileError();
};

void LinkerException::linkageError()
{
    std::cerr << "Error occurred in linkage process";
}

void LinkerException::failedAddFileError() {
    std::cerr << "Error occurred in adding file process";
}
