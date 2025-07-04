/*
Exception class for assembly generator
*/
class AssemblyGeneratorException final : public BaseException {
public:
    static int error_in_assembly_generation(); //general exception in assembly generator
    static int wrong_assembly_line();
};

int AssemblyGeneratorException::error_in_assembly_generation() {
    std::cerr << "Error in assembly generation occurred";
    return 0;
}

int AssemblyGeneratorException::wrong_assembly_line() {
    return 0;
}
