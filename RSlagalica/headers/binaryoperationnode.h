#ifndef BINARYOPERATIONNODE_H
#define BINARYOPERATIONNODE_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <exception>
#include "headers/expressionelementnode.h"

class BinaryOperationNode: public ExpressionElementNode
{
private:

    char binary_op;

    ExpressionElementNode *left;
    ExpressionElementNode *right;

    BinaryOperationNode(const BinaryOperationNode& n);
    BinaryOperationNode();
    BinaryOperationNode &operator=(const BinaryOperationNode& n);

public:
    BinaryOperationNode(char op, ExpressionElementNode *l,
                        ExpressionElementNode *r);

    virtual double value();
};

#endif // BINARYOPERATIONNODE_H
