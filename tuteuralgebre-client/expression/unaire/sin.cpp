#include "sin.h"
#include <cmath>

Sin::Sin(Expression* exp)
: Unaire::Unaire(exp)
{
	Expression::addExpression(this);
}

Sin::~Sin()
{
    //dtor
}

double Sin::eval() const
{
    return sin(Unaire::eval());
}
