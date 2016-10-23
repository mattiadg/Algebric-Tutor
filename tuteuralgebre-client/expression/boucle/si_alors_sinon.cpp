#include "si_alors_sinon.h"
#include <limits.h>
#include <iostream>

Si_alors_sinon::Si_alors_sinon(Condition *_cond, Bloc *_value1, Bloc *_value2):
    cond(_cond), value1(_value1), value2(_value2)
{
	Expression::addExpression(this);
}

Si_alors_sinon::~Si_alors_sinon()
{
}

double Si_alors_sinon::eval() const
{
	if (cond->eval()){
		return value1->eval();
	}
	else {
		return value2->eval();
	}
}
