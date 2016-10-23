#ifndef PRODUIT_H
#define PRODUIT_H

#include "binaire.h"

/**
 * \brief Models a product between two Expressions.
 */
class Produit : public Binaire
{
    public:
		/**
		 * Constructor.
		 *
		 * @param _value1 The left operand of the product.
		 * @param _value2 The right operand of the product.
		 */
        Produit(Expression *_value1, Expression *_value2);
		/**
         * Destructor.
         */
        virtual ~Produit();
		/**
         * Compute the values of the operands and then compute the product between them.
         */
        virtual double eval() const;
};

#endif // PRODUIT_H
