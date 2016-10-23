#include "superieur.h"

Superieur::Superieur(Expression *_value1, Expression *_value2):
    Condition::Condition(_value1, _value2)
{
	Expression::addExpression(this);
}

Superieur::~Superieur()
{
}

double Superieur::eval() const
{
    if(value1->eval()>=value2->eval())
        return 1.0;
    else return 0.0;
}

