#include <gtest/gtest.h>

// Hide main
#define TESTING

// Bring the app
extern "C" {
#include "./hello.h"
}

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

/*
int i;

class HelloTest: public testing::Test {
protected:
    void SetUp() override { i = 0; }
};

TEST_F(HelloTest, Test01) {
    ASSERT_EQ(0, i);
    hello_loop(&i);
    ASSERT_EQ(10, i);
    hello_loop(&i);
    ASSERT_EQ(20, i);
}
*/
