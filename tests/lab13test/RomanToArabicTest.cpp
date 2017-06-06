//
// Created by mwypych on 01.06.17.
//
#include <string>
#include <MemLeakTest.h>
#include <gtest/gtest.h>
#include <Arabicroman.h>


using namespace arabicroman;


class RomanToArabicTest : public ::testing::Test {

};

TEST_F(RomanToArabicTest, ArabicToRomanWorksProperly) {
    EXPECT_EQ("CCCXXXIII", ArabicToRoman(333));
    EXPECT_EQ("XIII", ArabicToRoman(13));
    EXPECT_EQ("DCCLVIII", ArabicToRoman(758));
    EXPECT_EQ("CXXIII", ArabicToRoman(123));
    EXPECT_EQ("MMM", ArabicToRoman(3000));
}

TEST_F(RomanToArabicTest, NullValueArabicToRomanWorksProperly) {
    EXPECT_EQ("", ArabicToRoman(0));
}
