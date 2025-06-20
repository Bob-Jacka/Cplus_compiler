#include "BaseException.hpp"

class BinaryGeneratorException final : BaseException {
public:
    static int ErrorInBinaryGeneration(); //general exception
};

int BinaryGeneratorException::ErrorInBinaryGeneration() {
    std::cerr << "Error occurred in binary generation process";
    return 0;
}
