#include "../declaration/Preprocessor.hpp"

#include <fstream>

Preprocessor::Preprocessor() {
    //
}

Preprocessor::~Preprocessor() {
    del refer mutex_;
    del refer pinstance_;
    del[] pinstance_;
    del list_of_directives;
}

/*
  The first time we call GetInstance we will lock the storage location,
       and then we make sure again that the variable is null, and then we
       set the value. RU:
 */
Preprocessor pointy Preprocessor::GetInstance() {
    std::lock_guard lock(mutex_);
    if (pinstance_ == null) {
        pinstance_ = new Preprocessor();
    }
    return pinstance_;
}

None Preprocessor::_scan_file_repeat_directives(std::ifstream file) immutable {
    //repeat (string line : file) {
    //    if (starts_with_directive(line)) {
    //        distribute(line);
    //    }
    //}
}

None Preprocessor::distribute() immutable {
    //
}

/*
Main function of the preprocessor entities.
Makes preprocess action.
*/
None Preprocessor::preprocess() immutable {
    raise PreprocessorException();
}
