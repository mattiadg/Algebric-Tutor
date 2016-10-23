#ifndef SI_ALORS_SINON_H
#define SI_ALORS_SINON_H
#include "bloc.h"
#include "../binaire/condition.h"

using namespace std;

/**
 * \brief Models a selection statements, returns one of two values depending on the result of a Condition.
 *
 * Unlike the ternary operator the result can not be assigned to a variable.
 */
class Si_alors_sinon: public Expression
{
    public:
		/**
		 * Constructor.
		 *
		 * @param _cond The condition to evaluate.
		 * @param _value1 The first operand returned if the condition is true.
		 * @param _value2 The second operand returned if the condition is false.
		 */
        Si_alors_sinon(Condition *_cond, Bloc *_value1, Bloc *_value2);
		/**
         * Destructor.
         */
        virtual ~Si_alors_sinon();
		/**
         * Tests the condition and executes the first block if it's true, or the second one otherwise.
         *
         * @return eval() of the first block if condition is true, or eval() of the second block otherwise. In our programming language
         * logic, this value cannot be assigned, it has only debug meaning.
         */
        virtual double eval() const;

    private:
		Condition *cond;
        Bloc *value1;
        Bloc *value2;
};

#endif // SI_ALORS_SINON_H
