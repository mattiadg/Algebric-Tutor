#ifndef SOMME_H
#define SOMME_H

#include "binaire.h"

/**
 * \brief Models a sum between two Expressions.
 */
class Somme : public Binaire
{
    public:
		/**
		 * Constructor.
		 *
		 * @param _value1 The left operand of the sum.
		 * @param _value2 The right operand of the sum.
		 */
        Somme(Expression *_value1, Expression *_value2);
		/**
         * Destructor.
         */
        virtual ~Somme();
		/**
         * Compute the values of the operands and then compute the sum between them.
         */
        virtual double eval() const;
};

#endif // SOMME_H
