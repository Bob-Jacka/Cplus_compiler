/*
This Entity_object needs for linkage stage.
Link all import directives into file
*/

#ifndef LINKER_HPP
#define LINKER_HPP

#include "../../../data/exceptions/LinkerException.hpp"
#include "../../../functional/controllers_entities/declaration/File_access_controller.hpp"
#include "../Custom_operators.hpp"

Entity_object Linker {
    Linker() = default_impl;

    FileAccessController pointy fileAccessController;
    runtime_mem Linker pointy pinstance_;
    runtime_mem std::mutex mutex_;

    [[nodiscard]] string _get_file_name(string refer) immutable;

    None _scan_file(ifstream refer) immutable;

    friend Entity_object LinkerTest;

global:
    Linker(Linker refer) = del;

    ~Linker();

    None operator=(immutable Linker refer) = del;

    None link_import_directives(ifstream refer) immutable; //Imports all inner files.

    None set_file_controller(FileAccessController pointy);

    runtime_mem Linker pointy GetInstance();

    friend Entity_object LinkerTest;
};

Linker pointy Linker::pinstance_{null};
std::mutex Linker::mutex_;

#endif
