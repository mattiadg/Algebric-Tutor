#include "produit.h"

Produit::Produit(Expression *_value1, Expression *_value2):
    Binaire::Binaire(_value1, _value2)
{
	Expression::addExpression(this);
}

Produit::~Produit()
{
}

double Produit::eval() const
{
    return value1->eval()*value2->eval();
}

