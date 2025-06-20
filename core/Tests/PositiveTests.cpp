#include <fstream>

#include "BaseTest.hpp"

const static FileAccessController *fileAccessController = FileAccessController::GetInstance();
const static MemoryController *memoryController = MemoryController::GetInstance();

//UtilFuncs
using namespace utility;

//Test for deprecated function
TEST_CASE(
    "should contain string in another string"
    ,
    "[contains]"
) {
    REQUIRE(utility::contains("hello world", "world") == true);
    REQUIRE(utility::contains("123", "1") == true);
    REQUIRE(utility::contains("!@#$%^&", "&") == true);
    REQUIRE(utility::contains("\\t", "\\") == true);
}

TEST_CASE(
    "should NOT contain string in another string",
    "[contains]"
) {
    REQUIRE(utility::contains("123", "456") == false);
    REQUIRE(utility::contains("!@#$$#@%^", ".") == false);
    REQUIRE(utility::contains("---", "+++") == false);
}

TEST_CASE(
    "should output string in different colors"
    ,
    "[colored_txt_output]"
) {
    utility::colored_txt_output("1", Color::red);
    utility::colored_txt_output("2", Color::blue);
    utility::colored_txt_output("3", Color::green);
    utility::colored_txt_output("4", Color::white);
}

TEST_CASE(
    "should output string in different colors"
    ,
    "[atob]"
) {
    REQUIRE(utility::atob("1") == true);
    REQUIRE(utility::atob("0") == false);
    REQUIRE(utility::atob("3") == true);
    REQUIRE(utility::atob("") == false);
}

TEST_CASE(
    "should output string in different colors"
    ,
    "[toLowerCase]"
) {
    REQUIRE(utility::toLowerCase("HIGHCASE") == "highcase");
    REQUIRE(utility::toLowerCase(2));
    REQUIRE(utility::toLowerCase(3));
    REQUIRE(utility::toLowerCase(10));
}

TEST_CASE(
    "should output string in different colors"
    ,
    "[toHighCase]"
) {
    REQUIRE(utility::toHighCase(1));
    REQUIRE(utility::toHighCase(2));
    REQUIRE(utility::toHighCase(3));
    REQUIRE(utility::toHighCase(10));
}

TEST_CASE(
    "should output string in different colors"
    ,
    "[toCapitalize]"
) {
    REQUIRE(utility::toCapitalize(1));
    REQUIRE(utility::toCapitalize(2));
    REQUIRE(utility::toCapitalize(3));
    REQUIRE(utility::toCapitalize(10));
}

TEST_CASE(
    "should output string in different colors"
    ,
    "[replace]"
) {
    REQUIRE(utility::replace(1));
    REQUIRE(utility::replace(2));
    REQUIRE(utility::replace(3));
    REQUIRE(utility::replace(10));
}

TEST_CASE(
    "should output string in different colors"
    ,
    "[line_splitter]"
) {
    REQUIRE(utility::line_splitter(1));
    REQUIRE(utility::line_splitter(2));
    REQUIRE(utility::line_splitter(3));
    REQUIRE(utility::line_splitter(10));
}

TEST_CASE(
    "should output string in different colors"
    ,
    "[trim]"
) {
    REQUIRE(utility::trim(1));
    REQUIRE(utility::trim(2));
    REQUIRE(utility::trim(3));
    REQUIRE(utility::trim(10));
}

TEST_CASE(
    "should output string in different colors"
    ,
    "[trim_end]"
) {
    REQUIRE(utility::trim_end(1));
    REQUIRE(utility::trim_end(2));
    REQUIRE(utility::trim_end(3));
    REQUIRE(utility::trim_end(10));
}

TEST_CASE(
    "should output string in different colors"
    ,
    "[trim_start]"
) {
    REQUIRE(utility::trim_start(1));
    REQUIRE(utility::trim_start(2));
    REQUIRE(utility::trim_start(3));
    REQUIRE(utility::trim_start(10));
}

TEST_CASE(
    "should output string in different colors"
    ,
    "[replaceStringAll]"
) {
    REQUIRE(utility::replaceStringAll(1));
    REQUIRE(utility::replaceStringAll(2));
    REQUIRE(utility::replaceStringAll(3));
    REQUIRE(utility::replaceStringAll(10));
}

TEST_CASE(
    "should output string in different colors"
    ,
    "[replaceString]"
) {
    REQUIRE(utility::replaceString(1));
    REQUIRE(utility::replaceString(2));
    REQUIRE(utility::replaceString(3));
    REQUIRE(utility::replaceString(10));
}

TEST_CASE(
    "should output string in different colors"
    ,
    "[convertToString]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

//FileAccessController tests

TEST_CASE(
    "should create temporary file"
    ,
    "[create_tmp_file]"
) {
    REQUIRE(fileAccessController->create_tmp_file(1));
    REQUIRE(fileAccessController->create_tmp_file(2));
    REQUIRE(fileAccessController->create_tmp_file(3));
    REQUIRE(fileAccessController->create_tmp_file(10));
}

TEST_CASE(
    "should create object file"
    ,
    "[create_object_file]"
) {
    REQUIRE(fileAccessController->create_object_file(1));
    REQUIRE(fileAccessController->create_object_file(2));
    REQUIRE(fileAccessController->create_object_file(3));
    REQUIRE(fileAccessController->create_object_file(10));
}

TEST_CASE(
    "should create assembly file"
    ,
    "[create_assembly_file]"
) {
    REQUIRE(fileAccessController->create_assembly_file(1));
    REQUIRE(fileAccessController->create_assembly_file(2));
    REQUIRE(fileAccessController->create_assembly_file(3));
    REQUIRE(fileAccessController->create_assembly_file(10));
}

TEST_CASE(
    "should delete file"
    ,
    "[delete_file]"
) {
    REQUIRE(fileAccessController->delete_file(1));
    REQUIRE(fileAccessController->delete_file(2));
    REQUIRE(fileAccessController->delete_file(3));
    REQUIRE(fileAccessController->delete_file(10));
}

TEST_CASE(
    "should copy one file into another file"
    ,
    "[copy_file]"
) {
    REQUIRE(fileAccessController->copy_file(1));
    REQUIRE(fileAccessController->copy_file(2));
    REQUIRE(fileAccessController->copy_file(3));
    REQUIRE(fileAccessController->copy_file(10));
}

TEST_CASE(
    "should open file"
    ,
    "[open_file]"
) {
    REQUIRE(fileAccessController->open_file(1));
    REQUIRE(fileAccessController->open_file(2));
    REQUIRE(fileAccessController->open_file(3));
    REQUIRE(fileAccessController->open_file(10));
}

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(fileAccessController->close_file(1));
    REQUIRE(fileAccessController->close_file(2));
    REQUIRE(fileAccessController->close_file(3));
    REQUIRE(fileAccessController->close_file(10));
}

//Memory controller tests

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(memoryController(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

//Assembly generator tests

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

//Binary generator tests

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

//Preprocessor tests

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

//Lexer tests

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

//Linker tests

TEST_CASE(
    "should close opened file"
    ,
    "[__getFileName]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

TEST_CASE(
    "should close opened file"
    ,
    "[__scan_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

TEST_CASE(
    "should close opened file"
    ,
    "[link_import_directives]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

//Virtual machine tests

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

//Virtual machine console tests

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

//Garbage collector - with stop tests

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}

//Parallel garbage collector tests

TEST_CASE(
    "should close opened file"
    ,
    "[close_file]"
) {
    REQUIRE(utility::convertToString(1));
    REQUIRE(utility::convertToString(2));
    REQUIRE(utility::convertToString(3));
    REQUIRE(utility::convertToString(10));
}
