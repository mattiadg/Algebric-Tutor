#include "unaire.h"

Unaire::Unaire(Expression* exp)
{
    operand = exp;
}

Unaire::~Unaire()
{

}

double Unaire::eval() const
{
    return operand->eval();
}
