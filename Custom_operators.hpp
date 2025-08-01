/*
 Header file with my custom operators, style like Python or Java

 Before write your own language, change types in parent language
 */
#ifndef CUSTOM_OPERATORS_HPP
#define CUSTOM_OPERATORS_HPP

/**
 So, why I can't do this?
 */
#define elif else if //more convenience that else if
#define null nullptr //Java like style for null pointers
#define var3 auto //Kotlin like style to define variable, var1 and var2 are occupied by sh*ty inner lib
#define val2 const auto //Immutable Kotlin variable style
#define None void //Python like code style for nothing

//custom keywords
#define del delete //Python like delete operator
#define raise throw //Python like style in throwing exceptions
#define match switch //Python like switch
#define Generic template //I do not know what lang code style, but I like 'generic' word
#define except catch //Python style
#define self this //why not, in Python I can use this or self, or another word
#define stop break //why not
#define resume continue
#define immutable const //this variable or function does not mutate
#define repeat for //repeat some statement
#define defaultImpl default //stands for default implementation
#define runtimeMem static //memory that allocates only for runtime of the program
#define abstract virtual //virtual word means abstract function in abstract class

//Objects, because in C++ structs and classes almost identical, I use these definitions
#define DataObject struct
#define EntityObject class

//Value modifiers
#define noOptim volatile //compiler should not optimize variable with this modifier
#define optim inline //optimize function
#define refer & //macro for reference symbol
#define pointy * //pointer macro symbol

/**
 C+ code style in C++ code style
 */
#define global public
#define local private
#define inherited protected

#endif
