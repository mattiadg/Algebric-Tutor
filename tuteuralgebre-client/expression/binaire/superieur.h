#ifndef SUPERIEUR_H
#define SUPERIEUR_H

#include "condition.h"

/**
 * \brief Compares two Expressions and determines whether the first Expression is greater than or equal to the second Expression.
 */
class Superieur : public Condition
{
    public:
		/**
		 * Constructor.
		 *
		 * @param _value1 The left operand of the comparison.
		 * @param _value2 The right operand of the comparison.
		 */
        Superieur(Expression *_value1, Expression *_value2);
		/**
         * Destructor.
         */
        virtual ~Superieur();
		/**
         * Compares two operands and returns the value 1.0 if the predicate is true , the value 0.0 otherwise.
         */
        virtual double eval() const;
};


#endif // SUPERIEUR_H
