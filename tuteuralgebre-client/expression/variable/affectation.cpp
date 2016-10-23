/*
 * affectation.cpp
 *
 *  Created on: 29/gen/2016
 *      Author: mattia
 */

#include "affectation.h"
#include "variable.h"

Affectation::Affectation(string name, Expression* exp)
:_name(name), _exp(exp)
{
}

Affectation::~Affectation() {
}

double Affectation::eval() const {
	return Variable::assign(_name, _exp)->eval();
}
