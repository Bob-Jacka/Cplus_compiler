#include <BaseException.hpp>

/*
    Occurs when error happens in linkage
    */
class LinkerException : BaseException {

public:
    static int linkageError();
    static int failedAddFileError();
};

int LinkerException::linkageError()
{
    std::cerr <<  "Error occurred in linkage process";
    return 0;
}

int LinkerException::failedAddFileError() {
    std::cerr << "Error occurred in adding file process";
    return 0;
}
