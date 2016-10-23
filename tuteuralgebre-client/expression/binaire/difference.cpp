#include "difference.h"

Difference::Difference(Expression *_value1, Expression *_value2):
    Binaire::Binaire(_value1, _value2)
{
	Expression::addExpression(this);
}

Difference::~Difference()
{
}

double Difference::eval() const
{
    return value1->eval()-value2->eval();
}

