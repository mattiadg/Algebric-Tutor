#ifndef SIN_H
#define SIN_H

#include "unaire.h"

/**
 * \brief Models the sine of an Expression.
 */
class Sin : public Unaire
{
    public:
		/**
		 * Constructor.
		 *
		 * @param exp the operand of the operator.
		 */
        Sin(Expression* exp);
		/**
         * Destructor.
         */
        virtual ~Sin();
		/**
         * Compute the sine of the operand.
         *
         * @return the computed sine.
         */
        virtual double eval() const;
};

#endif // SIN_H
