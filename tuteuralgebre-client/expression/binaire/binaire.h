#ifndef BINAIRE_H
#define BINAIRE_H

#include "../expression.h"

/**
 * \brief Binaire provides common implementation details for binary operators.
 *
 * It is an abstract class which provides some protected fields for its children and a constructor. Binaire is an abstract
 * Expression, so it doesn't provide an implementation for eval().
 */
class Binaire : public Expression
{
    public:
		/**
		 * Constructor.
		 *
		 * @param _value1 The left operand of the binary operation.
		 * @param _value2 The right operand of the binary operation.
		 */
        Binaire(Expression * _value1, Expression * _value2);
        /**
         * Destructor.
         */
        virtual ~Binaire();
        virtual double eval() const=0;
    protected:
        Expression *value1;
        Expression *value2;
};

#endif // BINAIRE_H
