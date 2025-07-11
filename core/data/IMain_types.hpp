#ifndef IMAIN_TYPES_HPP
#define IMAIN_TYPES_HPP
#include "Util_funcs.hpp"

/*
 Class interface for main types structs.
 Defines same interface methods for init and destroy.
 Also include Util funcs header file.
 */
class IMainTypes {
public:
    /*
     Method for initializing entities of the main types
     */
    virtual void init_entities();

    /*
     Method for destroying entities of the main types
     */
    virtual void destroy_entities();

protected:
    IMainTypes();

    virtual ~IMainTypes();
};

#endif
