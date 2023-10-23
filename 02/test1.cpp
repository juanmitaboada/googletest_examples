#include <gtest/gtest.h>

// Hide main
#define TESTING

// Bring the app
extern "C" {
#include "./hello.c"
}

int i = 0;

class HelloTest: public testing::Test {
protected:
    void SetUp() override {}
};

TEST_F(HelloTest, Test01) {
    ASSERT_EQ(0, i);
    hello_loop(&i);
    ASSERT_EQ(10, i);
}

TEST_F(HelloTest, Test02) {
    ASSERT_EQ(10, i);
    hello_loop(&i);
    ASSERT_EQ(20, i);
}

TEST_F(HelloTest, Test03) {
    ASSERT_EQ(20, i);
    hello_loop(&i);
    ASSERT_EQ(30, i);
}
