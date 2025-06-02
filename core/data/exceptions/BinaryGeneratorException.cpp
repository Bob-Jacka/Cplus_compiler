#include <BaseException.hpp>

class BinaryGeneratorException : BaseException {

public:
    static int ErrorInBinaryGeneration(); //general exception
};

int BinaryGeneratorException::ErrorInBinaryGeneration()
{
    std::cerr << "Error occurred in binary generation process";
    return 0;
}
