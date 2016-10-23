#include "conditionnel.h"

Conditionnel::Conditionnel(Condition *_cond, Expression *_value1, Expression *_value2):
    cond(_cond), value1(_value1), value2(_value2)
{
	Expression::addExpression(this);
}

Conditionnel::~Conditionnel()
{
}

double Conditionnel::eval() const
{
	if (cond->eval()) return value1->eval();
	else return value2->eval();
}
