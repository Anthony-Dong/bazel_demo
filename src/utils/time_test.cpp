#include <gtest/gtest.h>
#include "src/utils/time.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

TEST(UnixTime, BasicAssertions) {
    EXPECT_EQ(Example::Utils::UnixTime(0), "1970-01-01T00:00:00+00:00");
}