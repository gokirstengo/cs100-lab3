#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

//Op class tests
TEST(OpTest, OpEvaluatePositive) {
    Op* test1 = new Op(8);
    EXPECT_DOUBLE_EQ(test1->evaluate(), 8);
}

TEST(OpTest, OpEvaluateNegative) {
    Op* test2 = new Op(-8);
    EXPECT_DOUBLE_EQ(test2->evaluate(), -8);
}

TEST(OpTest, OpEvaluateZero) {
    Op* test3 = new Op(0);
    EXPECT_DOUBLE_EQ(test3->evaluate(), 0);
}

TEST(OpTest, OpStringPositive) {
    Op* test4 = new Op(1.1);
    EXPECT_EQ(test4->stringify(), "1.100000");
}

TEST(OpTest, OpStringNegative) {
    Op* test5 = new Op(-1.1);
    EXPECT_EQ(test5->stringify(), "-1.100000");
}
TEST(OpTest, OpStringZero) {
    Op* test6 = new Op(0);
    EXPECT_EQ(test6->stringify(), "0.000000");
}


#endif //__OP_TEST_HPP__
