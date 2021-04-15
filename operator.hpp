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

#endif
