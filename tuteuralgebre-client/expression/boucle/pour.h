#ifndef POUR_H
#define POUR_H
#include "../expression.h"
#include "bloc.h"
#include "../binaire/condition.h"

using namespace std;
/**
 * \brief Models an iteration statements, it is designed to iterate a number of times.
 */ 
class Pour: public Expression
{
    public:
		/**
		 * Constructor.
		 *
		 * @param _init The initialization, generally a counter variable. It is executed a single time, at the beginning of the loop.
		 * @param _cond The condition to evaluate, the loop continues until it is true.
		 * @param _assg The operand to increase.
		 * @param _bloc One or a set of Expressions to execute.
		 */
        Pour(Expression *_init, Condition *_cond, Expression *_assg, Bloc *_bloc);
		/**
         * Destructor.
         */
        virtual ~Pour();
		/**
         * Executes the for loop. The returned value should be ignored, it is always equals to the largest long value.
         */
        virtual double eval() const;

    private:
		Expression *init;
		Condition *cond;
		Expression *assg;
		Bloc *bloc;
};

#endif // POUR_H
