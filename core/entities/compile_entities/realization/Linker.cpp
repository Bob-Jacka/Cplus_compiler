#include "../declaration/Linker.hpp"

#include "CplusModel.hpp"

/*
 The first time we call GetInstance we will lock the storage location,
and then we make sure again that the variable is null, and then we
set the value.
 */
Linker pointy Linker::GetInstance() {
    std::lock_guard lock(mutex_);
    if (pinstance_ == null) {
        pinstance_ = new Linker();
    }
    return pinstance_;
}

Linker::~Linker() {
    del refer mutex_;
}

#define EMPT_STR ""

string Linker::_get_file_name(string refer line) immutable {
    return utility::replace_string_all(
        utility::replace_string_all(utility::replace_string(line, IMPORT, EMPT_STR), "<", EMPT_STR), ">", EMPT_STR);
}

/*
 Method repeat scanning file repeat import directives
 input_file - file to scan
 */
None Linker::_scan_file(ifstream refer input_file) immutable {
    string line;
    var3 include_directive_func = [](string lambda_line) -> string {
        return utility::contains(lambda_line, IMPORT) ? lambda_line : EMPT_STR;
    };
    while (getline(input_file, line)) {
        if (include_directive_func(line) != EMPT_STR) {
            string file_name_to_include = self->_get_file_name(line);
            cout << "Found file to include: " << file_name_to_include << endl;
            fileAccessController->copy_file(file_name_to_include, "");
        }
    }
}

/*
Main function of linker entities.
file_name - name of the file to link import directives
*/
None Linker::link_import_directives(ifstream refer file_name) immutable {
    if (fileAccessController != null) {
        try {
            self->_scan_file(file_name);
        } except ([[maybe_unused]] std::exception refer e) {
            raise LinkerException::linkage_error();
        }
    } else {
        raise LinkerException::no_file_controller_to_link_import_directives();
    }
}

/*
 Setter method repeat file controller
 */
None Linker::set_file_controller(FileAccessController pointy fileAccessController) {
    self->fileAccessController = fileAccessController;
}
