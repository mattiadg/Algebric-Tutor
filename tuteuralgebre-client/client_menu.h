#ifndef CLIENTMENU_H
#define CLIENTMENU_H

#include "menu_option.h"
#include <vector>
#include <memory>

using namespace std;

/**
 * \brief Implements a client-side menu. It handles the options and call them as needed.
 *
 * Implements the Command Pattern by calling the execute() method of MenuOption, which defines the interface
 * to be implemented by commands.
 */
class ClientMenu
{
    public:
		/**
		 * The default constructor.
		 */
        ClientMenu();
        /**
         * Destructor
         */
        virtual ~ClientMenu();
        /**
         * Add a MenuOption to the menu. The MenuOption must have a name in order to be printed.
         *
         * @param option A shared_ptr to the concrete class of MenuOption that we want to add to the menu.
         */
        void addOption(shared_ptr<MenuOption> option);
        /**
         * Call the execute() method of the ith MenuOption.
         *
         * @param i The position of the option to call.
         */
        void executeOption(int i);
        /**
         * Return the number of options registered.
         */
        int getOptionsNumber();

        /**
         * Friend method for printing the whole menu.
         */
        friend ostream& operator<<(ostream& os, const ClientMenu& menu);

    private:
        vector<shared_ptr<MenuOption>> options;
};

#endif // CLIENTMENU_H
