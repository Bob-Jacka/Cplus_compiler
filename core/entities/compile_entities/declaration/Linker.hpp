/*
This Entity_object needs for linkage stage.
Link all import directives into file
*/

#ifndef LINKER_HPP
#define LINKER_HPP

#include "../data/exceptions/LinkerException.hpp"
#include "../functional/controllers_entities/declaration/File_access_controller.cppm"
#include "../Custom_operators.hpp"

namespace Compile::Linker {
    EntityObject Linker {
        Linker() = defaultImpl;

        File_controller::FileAccessController pointy fileAccessController;
        runtimeMem Linker pointy pinstance_;
        runtimeMem std::mutex mutex_;

        [[nodiscard]] string _get_file_name(string refer) immutable;

        None _scan_file(std::ifstream refer) immutable;

        friend EntityObject LinkerTest;

    global:
        Linker(Linker refer) = del;

        ~Linker();

        None operator=(immutable Linker refer) = del;

        None link_import_directives(std::ifstream refer) immutable; //Imports all inner files.

        None set_file_controller(File_controller::FileAccessController pointy);

        runtimeMem Linker pointy GetInstance();

        friend EntityObject LinkerTest;
    };

    Linker pointy Linker::pinstance_{null};
    std::mutex Linker::mutex_;
}

#endif
