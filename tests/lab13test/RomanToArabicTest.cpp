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

TEST_F(RomanToArabicTest , ArabicToRomanWorksProperly) {
    EXPECT_EQ("CCCXXXIII", RomanToArabic(333));
    EXPECT_EQ("XIII", RomanToArabic(13));
    EXPECT_EQ("DCCLVIII", RomanToArabic(758));
    EXPECT_EQ("CXXIII", RomanToArabic(123));
    EXPECT_EQ("MMM",RomanToArabic(3000));
}

TEST_F(RomanToArabicTest , NullValueArabicToRomanWorksProperly) {
    EXPECT_EQ("", RomanToArabic(0));
}
