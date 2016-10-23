/*
 * affectation.h
 *
 *  Created on: 29/gen/2016
 *      Author: mattia
 */

#ifndef AFFECTATION_H_
#define AFFECTATION_H_

#include "../expression.h"
#include <string>

/**
 * \brief Affectation represents an assignment instruction.
 *
 * Affectation represents an instruction of the type var = expression. Its aim is to update the variable's value without producing
 * a cache. This is mainly needed by our for loops which store an instruction like i = i + 1 and the value of i must change
 * every time the assignment operation is made.
 * This is different from the Variable class because that one allows to retrieve the variable value from the symbol table but
 * not to change it, because it takes a double value to be initialized.
 * Affectation, at the opposite, is a dynamical class that computes the correct values when needed.
 */
class Affectation : public Expression{
public:
	/**
	 * Constructor.
	 *
	 * @param name The name of the variable
	 * @param exp The expression which produces the value to assign. Note that it can be a really complicated expression, as it
	 * can be a simple constant.
	 */
	Affectation(string name, Expression* exp);
	/**
	 * Destructor.
	 */
	virtual ~Affectation();
	/**
	 * Assign the result of exp->eval() to the variable named name.
	 *
	 * @return the assigned value.
	 */
	virtual double eval() const;

private:
	string _name;
	Expression* _exp;
};

#endif /* AFFECTATION_H_ */
