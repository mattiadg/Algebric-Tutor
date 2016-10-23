#ifndef EXPONENTIELLE_H
#define EXPONENTIELLE_H

#include "unaire.h"

/**
 * \brief Models the exponential function of an Expression.
 */
class Exponentielle : public Unaire
{
    public:
		/**
		 * Constructor.
		 *
		 * @param exp the operand of the operator.
		 */
        Exponentielle(Expression* exp);
		/**
         * Destructor.
         */
        virtual ~Exponentielle();
		/**
         * Compute the exponential function of the operand, the value of the exponent.
         *
         * @return the computed exponential.
         */
        virtual double eval() const;
};

#endif // EXPONENTIELLE_H
