#ifndef MENUOPTION_H
#define MENUOPTION_H

#include <string>


using namespace std;

/**
 * \brief Defines an option to use with ClientMenu.
 *
 * Each MenuOption is identified by a name to print and provide an execute() method which executes the task.
 */
class MenuOption
{
    public:
		/**
		 * Constructor.
		 *
		 * @param name The string to print in the menu
		 */
        MenuOption(string name) :_name(name) {};
        /**
         * Destructor
         */
        virtual ~MenuOption() {}

        /**
         * Method to implement by the implementer classes. It represents a task done by the client.
         */
        virtual void execute() = 0;
        /**
         * Return the name of choice of the option
         */
        string getName() { return _name; }

        /**
         * operator<< print the object in a stream. It is used by operator<< of ClientMenu.
         */
        friend ostream& operator<<(ostream& os, MenuOption& option)
        {
            os << option._name;
            return os;
        }

    private:
        string _name;
};

#endif // MENUOPTION_H
