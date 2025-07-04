class PreprocessorException final : public BaseException {
public:
    static int wrongDirective(); //if directive is not defined by compiler
    static int wrongDirectiveLine();
};

int PreprocessorException::wrongDirective() {
    std::cerr << "Wrong preprocessor directive found";
    return 0;
}

int PreprocessorException::wrongDirectiveLine() {
    std::cerr << "Wrong preprocessor directive line found";
    return 0;
}
