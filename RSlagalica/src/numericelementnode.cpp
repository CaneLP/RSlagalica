#include "headers/numericelementnode.h"

NumericElementNode::NumericElementNode(double val) :
    number(val)
{
}

inline double NumericElementNode::value()
{
    return number;
}
