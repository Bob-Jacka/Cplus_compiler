#include "BaseException.hpp"

/*
Exception class for different compiler modes
*/
class CompilerModeException final : public BaseException {
public:
    static int failed_to_compile_file();

    static int main_not_found();

    static int error_in_compile_strategy();

    static int error_in_vm_strategy();

    static int vm_is_not_available();
};

/*
 Throws error if failed to compile file
 Yes, it a little bit abstract...
 */
int CompilerModeException::failed_to_compile_file() {
    std::cerr << "Error occurred to compile program";
    return 0;
}

/*
 Throws error if main file was not found
 */
int CompilerModeException::main_not_found() {
    std::cerr << "Main file or function not found";
    return 0;
}

/*
 Throws error if error in compile strategy
 */
int CompilerModeException::error_in_compile_strategy() {
    std::cerr << "Error in compile strategy";
    return 0;
}

/*
 Throws error if error in vm strategy
 */
int CompilerModeException::error_in_vm_strategy() {
    std::cerr << "Error in virtual machine strategy";
    return 0;
}

/*
 Throws error if virtual machine strategy is not available
 */
int CompilerModeException::vm_is_not_available() {
    std::cerr << "VM strategy can not be available";
    return 0;
}
