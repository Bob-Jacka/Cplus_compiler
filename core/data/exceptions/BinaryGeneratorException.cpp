class BinaryGeneratorException final : public BaseException {
public:
    static int ErrorInBinaryGeneration(); //general exception
};

int BinaryGeneratorException::ErrorInBinaryGeneration() {
    std::cerr << "Error occurred in binary generation process";
    return 0;
}
