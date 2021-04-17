
#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

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

#endif //__OP_HPP__
