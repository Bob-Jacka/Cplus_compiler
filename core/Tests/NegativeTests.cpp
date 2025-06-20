#include "BaseTest.hpp"

const FileAccessController *fileAccessController = FileAccessController::GetInstance();
const MemoryController *memoryController = MemoryController::GetInstance();

using namespace utility;

TEST_CASE("should not contain int in another string", "[contains]") {
    REQUIRE(utility::contains(utility::contains(1, "gtbvt")));
}
