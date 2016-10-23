#include "exponentielle.h"
#include <cmath>

Exponentielle::Exponentielle(Expression* exp)
:Unaire::Unaire(exp)
{
	Expression::addExpression(this);
}

Exponentielle::~Exponentielle()
{
    //dtor
}

double Exponentielle::eval() const
{
    return exp(Unaire::eval());
}
