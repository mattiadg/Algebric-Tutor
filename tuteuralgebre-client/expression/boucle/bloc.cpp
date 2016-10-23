#include "bloc.h"

Bloc::Bloc(string _name):
	name(_name)
{
	Expression::addExpression(this);
}

Bloc::Bloc(string _name, Expression *_exp):
    name(_name)
{
	Expression::addExpression(this);
	expressions.push_back(_exp);
}

Bloc::Bloc(string _name, list<Expression*> _exp):
	name(_name), expressions(_exp)
{
	Expression::addExpression(this);
}

Bloc::~Bloc()
{
}

double Bloc::eval() const
{
	list<Expression*>::const_iterator it;
    for (it = expressions.begin(); *it != expressions.back(); it++)
    {
        (*it)->eval();
    }
	return expressions.back()->eval();
}

void Bloc::add(Expression *_exp)
{
	expressions.push_back(_exp);
}
