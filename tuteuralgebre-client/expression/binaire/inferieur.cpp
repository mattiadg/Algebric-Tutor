#include "inferieur.h"

Inferieur::Inferieur(Expression *_value1, Expression *_value2):
    Condition::Condition(_value1, _value2)
{
	Expression::addExpression(this);
}

Inferieur::~Inferieur()
{
}

double Inferieur::eval() const
{
    if(value1->eval()<=value2->eval())
        return 1.0;
    else return 0.0;
}


