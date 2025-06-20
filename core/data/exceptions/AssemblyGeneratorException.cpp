#include "BaseException.hpp"

/*
Exception class for assembly generator
*/
class AssemblyGeneratorException final : BaseException {
public:
    static int errorInAssemblyGeneration(); //general exception in assembly generator
    static int wrongAssemblyLine();
};

int AssemblyGeneratorException::errorInAssemblyGeneration() {
    std::cerr << "Error in assembly generation occurred";
    return 0;
}

int AssemblyGeneratorException::wrongAssemblyLine() {
    return 0;
}
