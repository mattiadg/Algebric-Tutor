#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <set>

using namespace std;

/**
 * \brief Expression interface, allows implementing Composite Pattern
 *
 * This interface declares the eval() method which must be implemented by expressions in order to be executed.
 * Moreover, it stores all the expressions and provide a static method for freeing memory.
 */
class Expression
{
    public:
		/**
		 * Method to implement by Expressions in order to provide Composite Pattern.
		 */
        virtual double eval() const = 0;

        /**
         * Virtual destructor.
         */
        virtual ~Expression() = 0;
        /**
         * Add an Expression to the Expression pool. When we don't need anymore the expressions we must call
         * toutLiberer in order to free memory.
         */
        static void addExpression(Expression*);
        /**
         * Free memory occupied by all Expression s.
         */
        static void toutLiberer();

    private:
        static set<Expression*> _pool;
};

inline Expression::~Expression() { }

#endif // EXPRESSION_H
