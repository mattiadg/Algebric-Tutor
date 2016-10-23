#ifndef VARIABLE_H
#define VARIABLE_H
#include "../expression.h"
#include <string>
#include <map>

using namespace std;

/**
 * \brief Variable represents a variable inside our program.
 *
 * A Variable object is identified by a name which identify the variable inside a symbol table and can retrieve its value from it.
 * Class Variable provides also one static public method which builds a Variable-object pointer by its name.
 * This class should be used to retrieve a variable's value and not to make assignments. In order to assign a value to a
 * variable, class Affectation is provided.
 */
class Variable : public Expression
{
    public:
		/**
		 * Destructor.
		 */
        virtual ~Variable();
        /**
         * @return Variable's value from the symbols table
         */
        virtual double eval() const;
        /**
         * Create a pointer to a Variable object. If name already exists, the returned Variable will provide the value stored
         * in the symbol table, else a new entry with a 0 value will be created in the symbol table.
         * This is the only way to get a pointer to a Variable object.
         *
         * @return a pointer to the variable named name.
         */
        static Variable* getVariable(string name);
        /**
         * Assign the value computed by exp to the variable identified by name.
         *
         * @param name The name of the variable
         * @param exp An expression which computes the value to assign to the variable
         *
         * @return a pointer to the variable identified by name.
         */
        static Variable* assign(string name, Expression* exp);
    private:
        const string _name;
        double _value;
        Variable(string name, double value);

        static map<string, double> hashtab;
};

#endif // VARIABLE_H
