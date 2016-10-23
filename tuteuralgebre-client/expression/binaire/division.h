#ifndef DIVISION_H
#define DIVISION_H

#include "binaire.h"

/**
 * \brief Division models a division between two Expressions.
 */
class Division : public Binaire
{
    public:
		/**
		 * Constructor.
		 *
		 * @param _value1 The left operand of the division.
		 * @param _value2 The right operand of the division.
		 */
        Division(Expression *_value1, Expression *_value2);
		/**
         * Destructor.
         */
        virtual ~Division();
		/**
         * Compute the values of the operands and then compute the division between them.
         */
        virtual double eval() const;
};

#endif // DIVISION_H
