/*
This class needs for linkage stage.
Link all import directives into file
*/

#ifndef LINKER_HPP
#define LINKER_HPP

#include "../../../data/exceptions/LinkerException.hpp"
#include "../../../functional/controllers_entities/declaration/File_access_controller.hpp"

#include "../static/CplusModel.hpp"

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

#endif