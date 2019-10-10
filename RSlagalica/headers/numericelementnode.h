#ifndef NUMERICELEMENTNODE_H
#define NUMERICELEMENTNODE_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <exception>
#include "headers/expressionelementnode.h"

class NumericElementNode: public ExpressionElementNode
{

private:
    double number;
    NumericElementNode(const NumericElementNode& n);
    NumericElementNode();
    NumericElementNode&operator=(const NumericElementNode& n);
public:
    NumericElementNode(double val);
    virtual double value();
};

#endif // NUMERICELEMENTNODE_H
