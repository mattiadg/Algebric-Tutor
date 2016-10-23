#include "condition.h"

Condition::Condition(Expression * _value1, Expression * _value2):
    Binaire::Binaire(_value1, _value2)
{
}

Condition::~Condition()
{
}
