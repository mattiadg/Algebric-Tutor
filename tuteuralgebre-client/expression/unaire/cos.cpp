#include "cos.h"
#include <cmath>

Cos::Cos(Expression* exp)
:Unaire::Unaire(exp)
{
	Expression::addExpression(this);
}

Cos::~Cos()
{
    //dtor
}

double Cos::eval() const
{
    return cos(Unaire::eval());
}
