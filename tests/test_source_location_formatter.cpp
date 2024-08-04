#include "source_location_formatter.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <string>

TEST(SourceLocationFormatter, BasicTest) {
    auto loc { std::source_location::current() };
    std::string result = std::format("Location: {}", loc);
    ASSERT_THAT(result, testing::StartsWith("Location: "))
        << "Literal included";
    ASSERT_THAT(result, testing::MatchesRegex(
        "^.*test_source_location_formatter\\.cpp.*$"
    )) << "File name included";
    // Known issue with gtest: https://github.com/google/googletest/issues/3084
    // TLDR: \\d doesn't work on MacOS or Linux, but [0-9] won't work on Windows
    ASSERT_THAT(result, testing::MatchesRegex("^.*[0-9]+,.+[0-9]+.*$"))
        << "Line and column numbers included";
    ASSERT_THAT(result, testing::MatchesRegex("^.*TestBody().*$"))
        << "Function name included";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

