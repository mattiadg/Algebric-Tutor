#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

#include "../expression.h"

/**
 * \brief Unaire provides common implementation details for unary operators.
 *
 * It is an abstract class which provides some protected fields for its children and a constructor. Unaire is an abstract
 * Expression, so it doesn't provide an implementation for eval().
 */
class Unaire : public Expression
{
    public:
		/**
		 * Constructor.
		 *
		 * @param exp the operand of the unary operators.
		 */
        Unaire(Expression* exp);
		/**
         * Destructor.
         */
        virtual ~Unaire();
        virtual double eval() const;
    private:
        const Expression* operand;
};

#endif // OPERATEURUNAIRE_H
