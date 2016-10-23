#include "division.h"

Division::Division(Expression *_value1, Expression *_value2):
    Binaire::Binaire(_value1, _value2)
{
	Expression::addExpression(this);
}

Division::~Division()
{
}

double Division::eval() const
{
    return value1->eval()/value2->eval();
}

