#include <BaseException.hpp>

class BinaryGeneratorException : BaseException {

public:
    void ErrorInBinaryGeneration();
};

void BinaryGeneratorException::ErrorInBinaryGeneration()
{
    std::cerr << "Error occurred in binary generation process";
}
