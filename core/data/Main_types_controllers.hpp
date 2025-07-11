#ifndef MAIN_TYPES_CONTROLLERS_HPP
#define MAIN_TYPES_CONTROLLERS_HPP

// Controllers dependencies.
#include "IMain_types.hpp"
#include "../functional/controllers_entities/declaration/File_access_controller.hpp"
#include "../functional/controllers_entities/declaration/Memory_controller.hpp"

/*
 Structure with controllers.
 */
struct Controllers final : IMainTypes {
private:
    FileAccessController *file_controller; //file controller entity
    MemoryController *mem_controller; //memory controller entity

public:
    /*
     Standard controllers constructor
     */
    Controllers() {
        file_controller = null;
        mem_controller = null;
    }

    /*
     Standard controllers destructor
     */

    ~Controllers() override {
        del file_controller;
        del mem_controller;
    }

    /*
     Method for destroying inner controllers
     */
    void destroy_entities() override {
        try {
            del this->file_controller;
            del this->mem_controller;
        } catch (std::exception &e) {
            utility::colored_txt_output("Error in destroying global controller entities.", utility::Color::red);
            throw e;
        }
    }

    /*
     Method for initializing controllers (file and memory controllers)
     */

    void init_entities() override {
        try {
            this->file_controller = FileAccessController::GetInstance();
            this->mem_controller = MemoryController::GetInstance();
        } catch (std::exception &e) {
            utility::colored_txt_output("Error in initializing global controller entities.", utility::Color::red);
            throw e;
        }
    }

    /*
     Error safety method for receive file controller
     */
    [[nodiscard]] var3 get_file_controller() const -> FileAccessController * {
        try {
            return this->file_controller;
        } catch (std::exception &e) {
            utility::colored_txt_output("Error in returning file controller", utility::Color::red);
            throw e;
        }
    }

    /*
     Error safety method for receive memory controller
     */
    [[nodiscard]] var3 get_memory_controller() const -> MemoryController * {
        try {
            return mem_controller;
        } catch (std::exception &e) {
            utility::colored_txt_output("Error in returning memory controller", utility::Color::red);
            throw e;
        }
    }
};

#endif
