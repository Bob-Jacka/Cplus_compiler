#ifndef MAIN_TYPES_CONTROLLERS_HPP
#define MAIN_TYPES_CONTROLLERS_HPP

// Controllers dependencies.
#include "../functional/controllers_entities/declaration/File_access_controller.hpp"
#include "../functional/controllers_entities/declaration/Memory_controller.hpp"
#include "../static/Util_funcs.hpp"

/*
 Structure with controllers.
 */
struct Controllers {
private:
    FileAccessController *file_controller; //file controller entity
    MemoryController *mem_controller; //memory controller entity

public:
    /*
     Standard controllers constructor
     */
    Controllers() {
        file_controller = nullptr;
        mem_controller = nullptr;
    }

    /*
     Standard controllers destructor
     */
    ~Controllers() {
        delete file_controller;
        delete mem_controller;
    }

    /*
     Method for initializing controllers (file and memory controllers)
     */
    void init_controllers() {
        try {
            this->file_controller = FileAccessController::GetInstance();
            this->mem_controller = MemoryController::GetInstance();
        } catch (std::exception &e) {
            colored_txt_output("Error in initializing global controller entities.", Color::red);
            throw e;
        }
    }

    /*
     Method for destroying inner controllers
     */
    void destroy_controllers() const {
        try {
            delete this->file_controller;
            delete this->mem_controller;
        } catch (std::exception &e) {
            colored_txt_output("Error in destroying global controller entities.", Color::red);
            throw e;
        }
    }

    /*
     Error safety method for receive file controller
     */
    [[nodiscard]] auto get_file_controller() const -> FileAccessController * {
        try {
            return this->file_controller;
        } catch (std::exception &e) {
            colored_txt_output("Error in returning file controller", Color::red);
            throw e;
        }
    }

    /*
     Error safety method for receive memory controller
     */
    [[nodiscard]] auto get_memory_controller() const -> MemoryController * {
        try {
            return mem_controller;
        } catch (std::exception &e) {
            colored_txt_output("Error in returning memory controller", Color::red);
            throw e;
        }
    }
};

#endif
