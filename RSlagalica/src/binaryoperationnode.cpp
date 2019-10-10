#include "headers/binaryoperationnode.h"

BinaryOperationNode::BinaryOperationNode(char op,
                                                ExpressionElementNode *l, ExpressionElementNode *r) :
    binary_op(op), left(l), right(r)
{
}
double BinaryOperationNode::value()
{
    // To get the value, compute the value of the left and
    // right operands, and combine them with the operator.
    double leftVal = left->value();

    double rightVal = right->value();

    double result;

    switch (binary_op)
    {

    case '+':
        result = leftVal + rightVal;
        break;

    case '-':
        result = leftVal - rightVal;
        break;

    case '*':
        result = leftVal * rightVal;
        break;

    case '/':
        result = leftVal / rightVal;
        break;
    }

    return result;
}
