#ifndef CONDITIONNEL_H
#define CONDITIONNEL_H
#include "../expression.h"
#include "../binaire/condition.h"

using namespace std;

/**
 * \brief Models a Ternary operator, returns one of two values depending on the result of a Condition.
 */ 
class Conditionnel : public Expression
{
    public:
		/**
		 * Constructor.
		 *
		 * @param _cond The condition to evaluate.
		 * @param _value1 The first operand returned if the condition is true.
		 * @param _value2 The second operand returned if the condition is false.
		 */
        Conditionnel(Condition *_cond, Expression *_value1, Expression *_value2);
		/**
         * Destructor.
         */
        virtual ~Conditionnel();
		/**
         * Tests the condition and returns the first operand if the predicate is true , the second otherwise.
         *
         * @return 1 if the condition is true, 0 otherwise.
         */
        virtual double eval() const;

    private:
		Condition *cond;
        Expression *value1;
        Expression *value2;
};

#endif // CONDITIONNEL_H
