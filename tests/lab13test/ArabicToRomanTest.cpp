//
// Created by mwypych on 01.06.17.
//

//
// Created by mwypych on 29.05.17.
//
#include <string>
#include <MemLeakTest.h>
#include <gtest/gtest.h>
#include <Arabicroman.h>


using namespace arabicroman;


class ArabicToRomanTest : public ::testing::Test {

};

TEST_F(ArabicToRomanTest, ArabicToRomanWorksProperly) {
    EXPECT_EQ(3, ArabicToRoman("III"));
    EXPECT_EQ(30, ArabicToRoman("XXX"));
    EXPECT_EQ(4, ArabicToRoman("IV"));
    EXPECT_EQ(23, ArabicToRoman("XXIII"));
    EXPECT_EQ(45, ArabicToRoman("VL"));
}

TEST_F(ArabicToRomanTest, EmptyArabicToRomanWorksProperly) {
    EXPECT_EQ(0, ArabicToRoman(""));
}
