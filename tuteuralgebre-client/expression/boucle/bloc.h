#ifndef BLOC_H
#define BLOC_H

#include "../expression.h"
#include <list>
#include <string>

using namespace std;

/**
 * \brief Models a sequence of Expressions as a block, the value returned is the value of the last Expression of the block.
 */ 
class Bloc: public Expression
{
    public:
		/**
		 * Constructor with a single parameter.
		 *
		 * @param _name String representing the name of the block.
		 */
		Bloc(string _name);
		/**
		 * Constructor with two parameter.
		 *
		 * @param _name String representing the name of the block.
		 * @param _exp Expression assigned to a block.
		 */
        Bloc(string _name, Expression *_exp);
		/**
		 * Constructor with two parameter.
		 *
		 * @param _name String representing the name of the block.
		 * @param _exp The list of Expressions which constitute the block.
		 */
		Bloc(string _name, list<Expression*> _exp);
		/**
         * Destructor.
         */
        virtual ~Bloc();
		/**
         * Evaluate the Expressions one by one.
         *
         * @return the computed value of the last instruction.
         */
        virtual double eval() const;
		/**
         * Add an Expression into a block.
         */
		void add(Expression *_exp);

    private:
		string name;
        list<Expression*> expressions;
};

#endif // 	BLOC_H
