#ifndef __OPERATOR_HPP__
#define __OPERATOR_HPP__

#include "base.hpp"
#include "op.hpp"
#include <cmath>

using namespace std;

class Operator: public Base {
    protected:
        Base* leftChild;
        Base* rightChild;
    public:
        Operator(Base* leftChild, Base* rightChild) : Base() {
            this->leftChild = leftChild;
            this->rightChild = rightChild;
        }
};

class Sub: public Operator {
    public:
        Sub(Base* leftChild, Base* rightChild) : Operator(leftChild, rightChild) {}
        virtual double evaluate() {
            return leftChild->evaluate() - rightChild->evaluate();
        }
        virtual string stringify() {
            string final = "";
            final += leftChild->stringify();
            final += " - ";
            final += rightChild->stringify();
            return final;
        }
};

#endif
