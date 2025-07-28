#include "BaseTest.hpp"

const FileAccessController *fileAccessController = FileAccessController::GetInstance();
const MemoryController *memoryController = MemoryController::GetInstance();

const static string test_file_1 = "test1.txt";


using namespace utility;

TEST_CASE("should Not contain int in another string", "[contains]") {
    REQUIRE(utility::contains("1", "gtbvt"));
}

SCENARIO("should Not open file two times") {
    GIVEN("Test file name") {
        const static string test_file_2 = "test2.txt";

        // Validate assumption of the GIVEN clause
        THEN("File should open one time, but not two times") {
            REQUIRE(fileAccessController->open_file(test_file_2));
            REQUIRE(fileAccessController->open_file(test_file_2));
        }
    }
}

TEST_CASE("should Not close file two times", "[contains]") {
    std::ifstream file;
    file.open(test_file_1);
    fileAccessController->close_file(file);
    fileAccessController->close_file(file);
}
