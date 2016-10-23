#ifndef CONDITION_H
#define CONDITION_H

#include "../expression.h"
#include "binaire.h"

/**
 * \brief A type for binary operations that are also conditions.
 *
 * It is needed because we want only boolean values for conditions.
 */
class Condition : public Binaire
{
    public:
		/**
		 * Constructor.
		 *
		 * @param _value1 The left operand of the condition.
		 * @param _value2 The right operand of the condition.
		 */
        Condition(Expression * _value1, Expression * _value2);
        virtual ~Condition();
        virtual double eval() const=0;
};

#endif // CONDITION_H
