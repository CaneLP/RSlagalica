#ifndef EXPRESSIONELEMENTNODE_H
#define EXPRESSIONELEMENTNODE_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <exception>

class ExpressionElementNode
{

public:
    ExpressionElementNode();
    virtual double value() = 0;
};

#endif // EXPRESSIONELEMENTNODE_H
