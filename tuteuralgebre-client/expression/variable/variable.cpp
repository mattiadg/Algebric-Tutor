#include "variable.h"
#include <iostream>

std::map<string, double> Variable::hashtab;


/* on construit l'objet variable et on ins�re dans le tableau des symboles */
Variable::Variable(string name, double value)
:_name(name), _value(value)
{
    Variable::hashtab[_name] = value;
    Expression::addExpression(this);
}


Variable::~Variable()
{
	hashtab.erase(_name);
}


double Variable::eval() const
{
    return hashtab[_name];
}

Variable* Variable::getVariable(string name)
{
	double val = hashtab[name];
	Variable * var = new Variable(name, val);
	return var;
}

Variable* Variable::assign(string name, Expression* exp)
{
    Variable * newvar = new Variable(name, exp->eval());
    return newvar;
}
