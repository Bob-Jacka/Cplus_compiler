/*
    Occurs when error happens in linkage
*/
class LinkerException final : public BaseException {
public:
    static int linkage_error();

    static int failed_add_file_error();

    static int no_file_controller_to_link_import_directives();
};

int LinkerException::linkage_error() {
    std::cerr << "Error occurred in linkage process";
    return 1;
}

int LinkerException::failed_add_file_error() {
    std::cerr << "Error occurred in adding file process";
    return 1;
}

int LinkerException::no_file_controller_to_link_import_directives() {
    std::cerr << "Error occurred in adding directories";
    return 1;
}