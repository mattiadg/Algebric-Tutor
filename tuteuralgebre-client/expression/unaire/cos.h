#ifndef COS_H
#define COS_H

#include "unaire.h"

/**
 * \brief Models the cosine of an Expression.
 */
class Cos : public Unaire
{
    public:
		/**
		 * Constructor.
		 *
		 * @param exp the operand of the operator.
		 */
        Cos(Expression* exp);
		/**
         * Destructor.
         */
        virtual ~Cos();
		/**
         * Compute the cosine of the operand.
         *
         * @return the computed cosine.
         */
        virtual double eval() const;
};

#endif // COS_H
