/*
This class needs for linkage stage.
Link all import directives into file
*/

#include "../data/exceptions/LinkerException.cpp"
#include "../functional/controllers_entities/FileAccessController.cpp"
#include "../../static/CplusModel.hpp"

class Linker {
    Linker() = default;

    FileAccessController *fileAccessController;
    static Linker *pinstance_;
    static std::mutex mutex_;

    [[nodiscard]] string _get_file_name(string &line) const;

    void _scan_file(ifstream &input_file) const;

    friend class LinkerTest;

public:
    Linker(Linker &other) = delete;

    ~Linker();

    void operator=(const Linker &) = delete;

    void link_import_directives(ifstream &) const; //Imports all inner files.

    void set_file_controller(FileAccessController *);

    static Linker *GetInstance();

    friend class LinkerTest;
};

Linker *Linker::pinstance_{nullptr};
std::mutex Linker::mutex_;

/*
 * The first time we call GetInstance we will lock the storage location,
 *      and then we make sure again that the variable is null, and then we
 *      set the value.
 */
Linker *Linker::GetInstance() {
    std::lock_guard lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new Linker();
    }
    return pinstance_;
}

Linker::~Linker() {
    delete&mutex_;
}

#define EMPT_STR ""

string Linker::_get_file_name(string &line) const {
    return utility::replace_string_all(
        utility::replace_string_all(utility::replace_string(line, IMPORT, EMPT_STR), "<", EMPT_STR), ">", EMPT_STR);
}

/*
 Method for scanning file for import directives
 input_file - file to scan
 */
void Linker::_scan_file(ifstream &input_file) const {
    string line;
    auto include_directive_func = [](string lambda_line) -> string {
        return utility::contains(lambda_line, IMPORT) ? lambda_line : EMPT_STR;
    };
    while (getline(input_file, line)) {
        if (include_directive_func(line) != EMPT_STR) {
            string file_name_to_include = this->_get_file_name(line);
            cout << "Found file to include: " << file_name_to_include << endl;
            fileAccessController->copy_file(file_name_to_include, "");
        }
    }
}

/*
Main function of linker entities.
file_name - name of the file to link import directives
*/
void Linker::link_import_directives(ifstream &file_name) const {
    if (fileAccessController != nullptr) {
        try {
            this->_scan_file(file_name);
        } catch ([[maybe_unused]] std::exception &e) {
            throw LinkerException::linkage_error();
        }
    } else {
        throw LinkerException::no_file_controller_to_link_import_directives();
    }
}

/*
 Setter method for file controller
 */
void Linker::set_file_controller(FileAccessController *fileAccessController) {
    this->fileAccessController = fileAccessController;
}
