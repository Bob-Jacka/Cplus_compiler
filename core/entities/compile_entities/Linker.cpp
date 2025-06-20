/*
This class needs for linkega stage.
*/

#include <mutex>
#include "core/data/Variables.hpp"
#include "core/data/exceptions/LinkerException.cpp"
#include "core/functional/FileAccessController.cpp"
#include "static/CplusModel.hpp"

class Linker {
    Linker() = default;

    static Linker *pinstance_;
    static std::mutex mutex_;

    [[nodiscard]] string __getFileName(const string &line) const;

    void __scan_file(ifstream &input_file) const;

public:
    Linker(Linker &other) = delete;

    ~Linker();

    void operator=(const Linker &) = delete;

    void link_import_directives(ifstream &) const; //Imports all inner files.

    static Linker *GetInstance();
};

Linker *Linker::pinstance_{nullptr};
std::mutex Linker::mutex_;

/*
 * The first time we call GetInstance we will lock the storage location,
 *      and then we make sure again that the variable is null, and then we
 *      set the value.
 */
Linker *Linker::GetInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new Linker();
    }
    return pinstance_;
}

Linker::~Linker() {
    delete&mutex_;
}

#define EMPT_STR ""

string Linker::__getFileName(const string &line) const {
    return utility::replaceStringAll(
        utility::replaceStringAll(utility::replaceString(line, IMPORT, EMPT_STR), "<", EMPT_STR), ">", EMPT_STR);
}

void Linker::__scan_file(ifstream &input_file) const {
    string line;
    auto include_directive_func = [](string line) -> string {
        return utility::contains(line, IMPORT) ? line : EMPT_STR;
    };
    while (getline(input_file, line)) {
        if (include_directive_func(line) != EMPT_STR) {
            string file_name_to_include = this->__getFileName(line);
            cout << "Found file to include: " << file_name_to_include << endl;
            controllers->file_controller.copy_file(file_name_to_include, input_file);
        }
    }
}

/*
Main function of linker entities.
*/
void Linker::link_import_directives(ifstream &file_name) const {
    try {
        this->__scan_file(file_name);
    } catch (std::exception &e) {
        (new LinkerException())->linkageError();
    }
}
