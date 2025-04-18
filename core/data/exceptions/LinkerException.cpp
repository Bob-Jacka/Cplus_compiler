#include <BaseException.hpp>

/*
    Occurs when error happens in linkage
    */
class LinkerException : BaseException {

public:
    void linkageError();
    void failedAddFileError();
};

void LinkerException::linkageError()
{
    throw "Error occurred in linkage process";
}

void LinkerException::failedAddFileError() {
    std::cerr << "Error occurred in adding file process";
}
