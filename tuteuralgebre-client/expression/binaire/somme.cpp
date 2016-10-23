#include "somme.h"

Somme::Somme(Expression *_value1, Expression *_value2):
    Binaire::Binaire(_value1, _value2)
{
	Expression::addExpression(this);
}

Somme::~Somme()
{
}

double Somme::eval() const
{
    return value1->eval()+value2->eval();
}
