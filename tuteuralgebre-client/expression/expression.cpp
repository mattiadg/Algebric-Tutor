/*
 * expression.cpp
 *
 *  Created on: 30/gen/2016
 *      Author: mattia
 */
#include "expression.h"

set<Expression*> Expression::_pool;

void Expression::addExpression(Expression* exp) {
	_pool.insert(exp);
}

void Expression::toutLiberer() {
	std::set<Expression*>::const_iterator it = _pool.begin();
	for(; it != _pool.end(); it++){
		delete *it;
	}
}



