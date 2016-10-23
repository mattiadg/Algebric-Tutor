#include "constante.h"

Constante::Constante(const double _value):
    value(_value)
{
	Expression::addExpression(this);
}

Constante::~Constante()
{

}

double Constante::eval() const
{
    return value;
}
