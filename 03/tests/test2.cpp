#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hide main
#define TESTING

/*
 *  Define patterns for testing
 */
#define TEST_A "abc"
#define MATCH_A "A9993E36 4706816A BA3E2571 7850C26C 9CD0D89D"
#define TESTB_1 "abcdbcdecdefdefgefghfghighij"
#define TESTB_2 "hijkijkljklmklmnlmnomnopnopq"
#define TEST_B TESTB_1 TESTB_2
#define MATCH_B "84983E44 1C3BD26E BAAE4AA1 F95129E5 E54670F1"
#define TEST_C "a"
#define MATCH_C "34AA973C D4C4DAA4 F61EEB2B DBAD2731 6534016F"  // 1 million 'a'

// Bring the app
extern "C" {
#include "../src/sha1.c"  // NOLINT(build/include)
}

class TripleDESTest: public testing::Test {
protected:
    void SetUp() override {}
};

void test_eq(const char *a, const char *b) {
    // Prepare the HASH
    SHA1Context sha;
    SHA1Reset(&sha);
    SHA1Input(&sha, (const unsigned char *) a, strlen(a));

    if (!SHA1Result(&sha)) {
        // SHA1 algorithm has failed!
        fprintf(
            stderr, "ERROR-- could not compute message digest for '%s'\n", a);
        FAIL();
    } else {
        // Get the HASH
        char buf[45] = "";
        for (int i = 0; i < 5; i++) {
            snprintf(buf + (i * 9),
                     10,
                     "%X ",
                     sha.Message_Digest[i]);  // NOLINT(runtime/printf)
        }
        buf[44] = 0;

        // Verify the HASH
        EXPECT_STREQ(buf, b);
    }
}

TEST_F(TripleDESTest, TestBasic) {
    test_eq(TEST_A, MATCH_A);
    test_eq(TEST_B, MATCH_B);
}

TEST_F(TripleDESTest, TestMulti) {
    SHA1Context sha;
    SHA1Reset(&sha);
    for (int i = 1; i <= 1000000; i++) {
        SHA1Input(&sha, (const unsigned char *) TEST_C, 1);
    }

    if (!SHA1Result(&sha)) {
        fprintf(stderr, "ERROR-- could not compute message digest\n");
        FAIL();
    } else {
        // Get the HASH
        char buf[45] = "";
        for (int i = 0; i < 5; i++) {
            snprintf(buf + (i * 9),
                     10,
                     "%X ",
                     sha.Message_Digest[i]);  // NOLINT(runtime/printf)
        }
        buf[44] = 0;

        // Verify the HASH
        EXPECT_STREQ(buf, MATCH_C);
    }
}
