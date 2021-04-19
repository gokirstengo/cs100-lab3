#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "operator.hpp"

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
    Op* test5 = new Op(-1.12);
    EXPECT_EQ(test5->stringify(), "-1.120000");
}
TEST(OpTest, OpStringZero) {
    Op* test6 = new Op(0);
    EXPECT_EQ(test6->stringify(), "0");
}

//Rand class tests
TEST(RandTest, RandStayInRange) {
    Base* val = new Rand();

    EXPECT_LT(-1, val->evaluate());
    EXPECT_LT(val->evaluate(), 100);
}
TEST(RandTest, RnadStringify) {
    Base* val = new Rand();

    EXPECT_EQ(val->stringify(), to_string(static_cast<int>(val->evaluate())));
}

//Sub class test
TEST(SubTest, SubPositiveTest) {
    Base* leftChild = new Op(5);
    Base* rightChild = new Op(2);
    Base* minus = new Sub(leftChild, rightChild);

    EXPECT_EQ(minus->evaluate(), 3);
    EXPECT_EQ(minus->stringify(), "(5 - 2)");
}

TEST(SubTest, SubNegativeTest) {
    Base* leftChild = new Op(1);
    Base* rightChild = new Op(3);
    Base* minus = new Sub(leftChild, rightChild);

    EXPECT_EQ(minus->evaluate(), -2);
    EXPECT_EQ(minus->stringify(), "(1 - 3)");
}

TEST(SubTest, SubZeroTest) {
    Base* leftChild = new Op(7);
    Base* rightChild = new Op(7);
    Base* minus = new Sub(leftChild, rightChild);

    EXPECT_EQ(minus->evaluate(), 0);
    EXPECT_EQ(minus->stringify(), "(7 - 7)");                                     }

//Add class test
TEST(AddTest, AddPositiveTest) {
    Base* leftChild = new Op(5);
    Base* rightChild = new Op(5);
    Base* add = new Add(leftChild, rightChild);

    EXPECT_EQ(add->evaluate(), 10);
    EXPECT_EQ(add->stringify(), "(5 + 5)");
}

TEST(AddTest, AddNegativeTest) {
    Base* leftChild = new Op(1);
    Base* rightChild = new Op(-4);
    Base* add = new Add(leftChild, rightChild);

    EXPECT_EQ(add->evaluate(), -3);
    EXPECT_EQ(add->stringify(), "(1 + -4)");
}

TEST(AddTest, AddTwoNegativeTest) {
    Base* leftChild = new Op(-1);
    Base* rightChild = new Op(-4);
    Base* add = new Add(leftChild, rightChild);

    EXPECT_EQ(add->evaluate(), -5);
    EXPECT_EQ(add->stringify(), "(-1 + -4)");
}

TEST(AddTest, AddZeroTest) {
    Base* leftChild = new Op(7.777);
    Base* rightChild = new Op(0);
    Base* add = new Add(leftChild, rightChild);

    EXPECT_DOUBLE_EQ(add->evaluate(), 7.777);
    EXPECT_EQ(add->stringify(), "(7.777000 + 0)");
}

//Mult class tests
TEST(MultTest, MultPositiveTest) {
    Base* leftChild = new Op(5);
    Base* rightChild = new Op(5);
    Base* mult = new Mult(leftChild, rightChild);

    EXPECT_EQ(mult->evaluate(), 25);
    EXPECT_EQ(mult->stringify(), "(5 * 5)");
}

TEST(MultTest, MultNegativeTest) {
    Base* leftChild = new Op(2);
    Base* rightChild = new Op(-4);
    Base* mult = new Mult(leftChild, rightChild);

    EXPECT_EQ(mult->evaluate(), -8);
    EXPECT_EQ(mult->stringify(), "(2 * -4)");
}

TEST(MultTest, MultTwoDecimalTest) {
    Base* leftChild = new Op(0.5);
    Base* rightChild = new Op(0.125);
    Base* mult = new Mult(leftChild, rightChild);

    EXPECT_DOUBLE_EQ(mult->evaluate(), 0.062500);
    EXPECT_EQ(mult->stringify(), "(0.500000 * 0.125000)");
}

TEST(MultTest, MultTwoNegativeTest) {
    Base* leftChild = new Op(-3);
    Base* rightChild = new Op(-7);
    Base* mult = new Mult(leftChild, rightChild);

    EXPECT_EQ(mult->evaluate(), 21);
    EXPECT_EQ(mult->stringify(), "(-3 * -7)");
}

TEST(MultTest, MultZeroTest) {
    Base* leftChild = new Op(7.777);
    Base* rightChild = new Op(0);
    Base* mult = new Mult(leftChild, rightChild);

    EXPECT_DOUBLE_EQ(mult->evaluate(), 0);
    EXPECT_EQ(mult->stringify(), "(7.777000 * 0)");
}
#endif //__OP_TEST_HPP__
