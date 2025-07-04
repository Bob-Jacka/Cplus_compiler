#include "BaseTest.hpp"

const static FileAccessController *fileAccessController = FileAccessController::GetInstance();
const static MemoryController *memoryController = MemoryController::GetInstance();

const static string test_file_1 = "test1.txt";
const static string test_file_2 = "test2.txt";
const static string test_file_3 = "test3.txt";
const static string test_file_4 = "test4.txt";

//UtilFuncs
using namespace utility;

//Test for deprecated function
TEST_CASE(
    "should contain string in another string",
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
    "should output string in different colors",
    "[colored_txt_output]"
) {
    colored_txt_output("1", Color::red);
    colored_txt_output("2", Color::blue);
    colored_txt_output("3", Color::green);
    colored_txt_output("4", Color::white);
}

TEST_CASE(
    "should output string in different colors",
    "[atob]"
) {
    REQUIRE(utility::atob("1") == true);
    REQUIRE(utility::atob("0") == false);
    REQUIRE(utility::atob("3") == true);
    REQUIRE(utility::atob("") == false);
}

TEST_CASE(
    "should output string in lower case",
    "[toLowerCase]"
) {
    REQUIRE(utility::to_lower_case("HIGHCASE") == "highcase");
    REQUIRE(utility::to_lower_case(2));
    REQUIRE(utility::to_lower_case(3));
    REQUIRE(utility::to_lower_case(10));
}

TEST_CASE(
    "should output string in high case",
    "[toHighCase]"
) {
    REQUIRE(utility::to_high_case(1));
    REQUIRE(utility::to_high_case(2));
    REQUIRE(utility::to_high_case(3));
    REQUIRE(utility::to_high_case(10));
}

TEST_CASE(
    "should output string in capitalize case",
    "[toCapitalize]"
) {
    REQUIRE(utility::to_capitalize("Hello"));
    REQUIRE(utility::to_capitalize("world"));
    REQUIRE(utility::to_capitalize("hello World"));
    REQUIRE(utility::to_capitalize("123"));
}

TEST_CASE(
    "should replace char symbol string with another symbol",
    "[replace]"
) {
    REQUIRE(utility::replace("Hello guy", "y", "1"));
    REQUIRE(utility::replace(2));
    REQUIRE(utility::replace(3));
    REQUIRE(utility::replace(10));
}

TEST_CASE(
    "should replace string with another string",
    "[replace]"
) {
    REQUIRE(utility::replace("Hello guys", "guys", "world"));
    REQUIRE(utility::replace(2));
    REQUIRE(utility::replace(3));
    REQUIRE(utility::replace(10));
}

TEST_CASE(
    "should split string",
    "[line_splitter]"
) {
    REQUIRE(utility::line_splitter("123trhbr", "3"));
    REQUIRE(utility::line_splitter(2));
    REQUIRE(utility::line_splitter(3));
    REQUIRE(utility::line_splitter(10));
}

TEST_CASE(
    "should trim string with another string on end and start",
    "[trim]"
) {
    REQUIRE(utility::trim("AAHelloAA", "AA"));
    REQUIRE(utility::trim("123 Hello world 123", "123"));
    REQUIRE(utility::trim("123.1 Hello world 123.1", "123.1"));
}

TEST_CASE(
    "should trim string with another string on end",
    "[trim_end]"
) {
    REQUIRE(utility::trim_end("Hello world guys", " guys"));
    REQUIRE(utility::trim_end("Hello world guys", "world guys"));
    REQUIRE(utility::trim_end("Hello world 123", " 123"));
}

TEST_CASE(
    "should trim string with another string on start",
    "[trim_start]"
) {
    REQUIRE(utility::trim_end("123 Hello world", "123 "));
}

TEST_CASE(
    "should replace all strings by given string",
    "[replaceStringAll]"
) {
    REQUIRE(utility::replace_string_all());
    REQUIRE(utility::replace_string_all());
    REQUIRE(utility::replace_string_all());
    REQUIRE(utility::replace_string_all());
}

TEST_CASE(
    "should replace string",
    "[replaceString]"
) {
    REQUIRE(utility::replace_string(1));
    REQUIRE(utility::replace_string(2));
    REQUIRE(utility::replace_string(3));
    REQUIRE(utility::replace_string(10));
}

TEST_CASE(
    "should output string in different colors",
    "[convert_to_string]"
) {
    REQUIRE(utility::convert_to_string(1));
    REQUIRE(utility::convert_to_string(2));
    REQUIRE(utility::convert_to_string(3));
    REQUIRE(utility::convert_to_string(10));
}

//FileAccessController tests

TEST_CASE(
    "should create temporary file",
    "[create_tmp_file]"
) {
    REQUIRE(fileAccessController->create_tmp_file(1));
    REQUIRE(fileAccessController->create_tmp_file(2));
    REQUIRE(fileAccessController->create_tmp_file(3));
    REQUIRE(fileAccessController->create_tmp_file(10));
}

TEST_CASE(
    "should create object file",
    "[create_object_file]"
) {
    REQUIRE(fileAccessController->create_object_file(1));
    REQUIRE(fileAccessController->create_object_file(2));
    REQUIRE(fileAccessController->create_object_file(3));
    REQUIRE(fileAccessController->create_object_file(10));
}

TEST_CASE(
    "should create assembly file",
    "[create_assembly_file]"
) {
    REQUIRE(fileAccessController->create_assembly_file(1));
    REQUIRE(fileAccessController->create_assembly_file(2));
    REQUIRE(fileAccessController->create_assembly_file(3));
    REQUIRE(fileAccessController->create_assembly_file(10));
}

TEST_CASE(
    "should delete file",
    "[delete_file]"
) {
    REQUIRE(fileAccessController->delete_file(1));
    REQUIRE(fileAccessController->delete_file(2));
    REQUIRE(fileAccessController->delete_file(3));
    REQUIRE(fileAccessController->delete_file(10));
}

TEST_CASE(
    "should copy one file into another file",
    "[copy_file]"
) {
    REQUIRE(fileAccessController->copy_file(1));
    REQUIRE(fileAccessController->copy_file(2));
    REQUIRE(fileAccessController->copy_file(3));
    REQUIRE(fileAccessController->copy_file(10));
}

SCENARIO("should open files") {
    GIVEN("Test file names") {
        const static string test_file_1 = "test1.txt";
        const static string test_file_2 = "test2.txt";
        const static string test_file_3 = "test3.txt";
        const static string test_file_4 = "test4.txt";

        THEN("Execute methods") {
            REQUIRE(fileAccessController->open_file(test_file_1));
            REQUIRE(fileAccessController->open_file(test_file_2));
            REQUIRE(fileAccessController->open_file(test_file_3));
            REQUIRE(fileAccessController->open_file(test_file_4));
        }
    }
}

SCENARIO("should close opened files") {
    GIVEN("Test file names") {
        const static string test_file_1 = "test1.txt";
        const static string test_file_2 = "test2.txt";
        const static string test_file_3 = "test3.txt";
        const static string test_file_4 = "test4.txt";

        ifstream *test_file1;
        ifstream *test_file2;
        ifstream *test_file3;
        ifstream *test_file4;

        THEN("Execute methods") {
            test_file1 = fileAccessController->open_file(test_file_1);
            REQUIRE(test_file1);

            test_file2 = fileAccessController->open_file(test_file_2);
            REQUIRE(test_file2);

            test_file3 = fileAccessController->open_file(test_file_3);
            REQUIRE(test_file3);

            test_file4 = fileAccessController->open_file(test_file_4);
            REQUIRE(test_file4);

            WHEN("Execute methods") {
                REQUIRE(fileAccessController->close_file(test_file1));
                REQUIRE(fileAccessController->close_file(test_file2));
                REQUIRE(fileAccessController->close_file(test_file3));
                REQUIRE(fileAccessController->close_file(test_file4));
            }
        }
    }
}

//Memory controller tests

SCENARIO("should create 2d array with ints and then kill them all") {
    GIVEN("init arrays") {
        int **array1;
        int **array2;
        int **array3;

        THEN("Use functions to test") {
            array1 = memoryController->create_2d_array();
            array2 = memoryController->create_2d_array();
            array3 = memoryController->create_2d_array();

            REQUIRE(array1);
            REQUIRE(array2);
            REQUIRE(array3);

            WHEN("Delete arrays in last section") {
                REQUIRE(memoryController->kill_2d_array(array1));
                REQUIRE(memoryController->kill_2d_array(array2));
                REQUIRE(memoryController->kill_2d_array(array3));
            }
        }
    }
}
