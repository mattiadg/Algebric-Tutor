#ifndef DIFFERENCE_H
#define DIFFERENCE_H

#include "binaire.h"

/**
 * \brief Difference models a difference between two Expressions.
 */
class Difference : public Binaire
{
    public:
		/**
		 * Constructor.
		 *
		 * @param _value1 The left operand of the difference.
		 * @param _value2 The right operand of the difference.
		 */
        Difference(Expression *_value1, Expression *_value2);
        /**
         * Destructor.
         */
        virtual ~Difference();
        /**
         * Compute the values of the operands and then compute the difference between them.
         */
        virtual double eval() const;
};

#endif // DIFFERENCE_H
