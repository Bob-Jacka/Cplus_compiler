#include "../BaseTest.hpp"
#include "../../entities/compile_entities/FriendClassesCompile.hpp"


//Assembly generator tests

// SCENARIO() {
//     GIVEN() {
//         THEN() {
//             WHEN() {
//             }
//         }
//     }
// }

// SCENARIO() {
//     GIVEN() {
//         THEN() {
//             WHEN() {
//             }
//         }
//     }
// }

// SCENARIO() {
//     GIVEN() {
//         THEN() {
//             WHEN() {
//             }
//         }
//     }
// }

// SCENARIO() {
//     GIVEN() {
//         THEN() {
//             WHEN() {
//             }
//         }
//     }
// }

// SCENARIO() {
//     GIVEN() {
//         THEN() {
//             WHEN() {
//             }
//         }
//     }
// }

// SCENARIO() {
//     GIVEN() {
//         THEN() {
//             WHEN() {
//             }
//         }
//     }
// }

// SCENARIO() {
//     GIVEN() {
//         THEN() {
//             WHEN() {
//             }
//         }
//     }
// }

// SCENARIO() {
//     GIVEN() {
//         THEN() {
//             WHEN() {
//             }
//         }
//     }
// }

// SCENARIO() {
//     GIVEN() {
//         THEN() {
//             WHEN() {
//             }
//         }
//     }
// }

// SCENARIO() {
//     GIVEN() {
//         THEN() {
//             WHEN() {
//             }
//         }
//     }
// }

// SCENARIO() {
//     GIVEN() {
//         THEN() {
//             WHEN() {
//             }
//         }
//     }
// }

// SCENARIO() {
//     GIVEN() {
//         THEN() {
//             WHEN() {
//             }
//         }
//     }
// }

// SCENARIO() {
//     GIVEN() {
//         THEN() {
//             WHEN() {
//             }
//         }
//     }
// }

//Binary generator tests

TEST_CASE(
    "should close opened file",
    "[close_file]"
) {
    //
}

//Preprocessor tests

TEST_CASE(
    "should close opened file",
    "[close_file]"
) {
    //
}

//Lexer tests

SCENARIO("should init keywords") {
    GIVEN("Compile entity - Lexer") {
        const auto lexer = make_unique<LexerTest>();
        THEN("Do magic") {
            lexer->do_test_init_keywords();
            WHEN("") {
                const auto tokens = lexer->do_get_tokens();
                REQUIRE(tokens->size() != 0);
                REQUIRE(tokens->at(1).value == "int");
                REQUIRE(tokens->at(2).value == "float");
                REQUIRE(tokens->at(3).value == "string");
            }
        }
    }
}

SCENARIO("should return is whitespace sym") {
    GIVEN("Compile entity - Lexer") {
        const auto lexer = make_unique<LexerTest>();
        THEN("Do magic") {
            auto res = lexer->do_test_is_whitespace(' ');
            WHEN("Check results") {
                REQUIRE(res);
            }
        }
    }
}

SCENARIO("should return is alpha") {
    GIVEN("Compile entity - Lexer") {
        const auto lexer = make_unique<LexerTest>();
        THEN("Do magic") {
            auto res = lexer->do_test_is_alpha('a');
            WHEN("Check results") {
                REQUIRE(res);
            }
        }
    }
}

SCENARIO("should return is digit 1") {
    GIVEN("Compile entity - Lexer") {
        const auto lexer = make_unique<LexerTest>();
        THEN("Do magic") {
            auto res = lexer->do_test_is_digit('1');
            WHEN("Check results") {
                REQUIRE(res);
            }
        }
    }
}

SCENARIO("should return is digit 2") {
    GIVEN("Compile entity - Lexer") {
        const auto lexer = make_unique<LexerTest>();
        THEN("Do magic") {
            auto res = lexer->do_test_is_digit('0');
            WHEN("Check results") {
                REQUIRE(res);
            }
        }
    }
}

SCENARIO("should return is alphanumeric 1") {
    GIVEN("Compile entity - Lexer") {
        const auto lexer = make_unique<LexerTest>();
        THEN("Do magic") {
            auto res = lexer->do_test_is_alphanumeric('1');
            WHEN("Check results") {
                REQUIRE(res);
            }
        }
    }
}

SCENARIO("should return is alphanumeric 2") {
    GIVEN("Compile entity - Lexer") {
        const auto lexer = make_unique<LexerTest>();
        THEN("Do magic") {
            auto res = lexer->do_test_is_alphanumeric('a');
            WHEN("Check results") {
                REQUIRE(res);
            }
        }
    }
}

SCENARIO("should return is get next word") {
    GIVEN("Compile entity - Lexer") {
        const auto lexer = make_unique<LexerTest>();
        THEN("Do magic") {
            auto res = lexer->do_test_get_next_word();
            WHEN("Check results") {
                REQUIRE(res != "");
            }
        }
    }
}

SCENARIO("should return is get next number") {
    GIVEN("Compile entity - Lexer") {
        const auto lexer = make_unique<LexerTest>();
        THEN("Do magic") {
            auto res = lexer->do_test_get_next_number();
            WHEN("Check results") {
                REQUIRE(res != "");
            }
        }
    }
}

SCENARIO("should return tokens vector") {
    GIVEN("Compile entity - Lexer") {
        const auto lexer = make_unique<LexerTest>();
        THEN("Do magic") {
            const auto res = lexer->do_get_tokens();
            WHEN("Check results") {
                REQUIRE(res->size() != 0);
                REQUIRE(res != nullptr);
            }
        }
    }
}

//Linker tests

SCENARIO("should get file name", "[__getFileName]") {
    GIVEN("Compile entity - linker") {
        const auto linker = make_unique<LinkerTest>();
        THEN("Do magic") {
            //
            WHEN("Check results") {
                //
            }
        }
    }
}

SCENARIO("should scan file", "[__scan_file]") {
    GIVEN("Compile entity - linker") {
        const auto linker = make_unique<LinkerTest>();
        auto input_file = ifstream("input.txt");
        THEN("Do magic") {
            linker->do_test_scan_file(input_file);
            WHEN("Check results") {
                //
            }
        }
    }
}

SCENARIO("should link directives", "[link_import_directives]") {
    GIVEN("Compile entity - linker") {
        const auto linker = make_unique<LinkerTest>();
        auto input_file = ifstream("input.txt");
        THEN("Do magic") {
            linker->do_test_import_directives(input_file);
            WHEN("Check results") {
                //
            }
        }
    }
}
