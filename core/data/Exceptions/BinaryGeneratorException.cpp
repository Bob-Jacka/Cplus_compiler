#include <BaseException.hpp>

class BinaryGeneratorException : public BaseException {

public:
void ErrorInBinaryGeneration();
};

void BinaryGeneratorException::ErrorInBinaryGeneration()
{
    std::cerr << "Error occurred in binary generation process";
}
