#include "../BaseTest.hpp"
#include "../../entities/VM/GarbageCollector/ParallelCollector.cpp"
#include "../../entities/VM/GarbageCollector/CollectorWithStop.cpp"

//Virtual machine tests

TEST_CASE(
    "should close opened file",
    "[close_file]"
) {
    REQUIRE(utility::convert_to_string(1));
    REQUIRE(utility::convert_to_string(2));
    REQUIRE(utility::convert_to_string(3));
    REQUIRE(utility::convert_to_string(10));
}

//Virtual machine console tests

TEST_CASE(
    "should close opened file",
    "[close_file]"
) {
    REQUIRE(utility::convert_to_string(1));
    REQUIRE(utility::convert_to_string(2));
    REQUIRE(utility::convert_to_string(3));
    REQUIRE(utility::convert_to_string(10));
}

//Garbage collector - with stop tests

SCENARIO("Garbage collector - parallel collector") {
    GIVEN("An empty string") {
        CollectorWithStop *collector = CollectorWithStop::GetInstance();

        THEN() {
            WHEN() {
            }
        }
    }
}

TEST_CASE(
    "should close opened file",
    "[close_file]"
) {
    REQUIRE(utility::convert_to_string(1));
    REQUIRE(utility::convert_to_string(2));
    REQUIRE(utility::convert_to_string(3));
    REQUIRE(utility::convert_to_string(10));
}

//Garbage collector - parallel collector

SCENARIO("Garbage collector - parallel collector") {
    GIVEN("An empty string") {
        ParallelCollector *collector = ParallelCollector::GetInstance();
        THEN() {
            WHEN() {
            }
        }
    }
}

TEST_CASE(
    "should close opened file",
    "[close_file]"
) {
    REQUIRE(utility::convert_to_string(1));
    REQUIRE(utility::convert_to_string(2));
    REQUIRE(utility::convert_to_string(3));
    REQUIRE(utility::convert_to_string(10));
}
