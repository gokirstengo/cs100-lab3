
#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <ctime>

using namespace std;

class Op : public Base {
    protected:
        double value;
    public:
        Op(double value) : Base() {this->value = value; }
        virtual double evaluate() { return value; }
        virtual std::string stringify()
        { 
	    int i = value;
            if((value - i) > 0.000001 || (i - value) > 0.000001)
            {
                return std::to_string(value);
            }
            else
            {
                return std::to_string(i);
            }
	}
};

class Rand : public Base {
    private:
        double value;
    public:
        Rand() : Base() {
	    srand(time(0));
	    value = rand() % 100;
        }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { 
            if (value == static_cast<int>(value)) {
                return to_string(static_cast<int>(value)); 
            }
            else {
                return to_string(value);
            }
        }
};
#endif //__OP_HPP__
