#include "pour.h"
#include <limits.h>
#include <iostream>

Pour::Pour(Expression *_init, Condition *_cond, Expression *_assg, Bloc *_bloc):
    init(_init), cond(_cond), assg(_assg), bloc(_bloc)
{
	Expression::addExpression(this);
}

Pour::~Pour()
{
}

double Pour::eval() const
{
	init->eval();
	while(cond->eval()){
		bloc->eval();
		assg->eval();
	}
	/*
	for(init->eval(); cond->eval(); assg->eval())
	{	
		bloc->eval();
	}*/
	return LONG_MAX;
}
