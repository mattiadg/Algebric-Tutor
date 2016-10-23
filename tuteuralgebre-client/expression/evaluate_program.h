#ifndef EVALUATEPROGRAM_H
#define EVALUATEPROGRAM_H

#include "../menu_option.h"
#include <string>

extern int yyparse();
extern FILE * yyin;

/**
 * \brief EvaluateProgram provides a parser for our little programming language.
 *
 * EvaluateProgram is a MenuOption, so that it is used as a functionality of our client by means of the CommandPattern provided
 * by ClientMenu.
 */
class EvaluateProgram : public MenuOption
{
    public:
		/**
		 * Constructor.
		 *
		 * @param name The string to print in the menu.
		 */
        EvaluateProgram(string name);
        /**
         * Destructor.
         */
        virtual ~EvaluateProgram();

        /**
         * Ask a filename containing a program to the user and interpret it.
         */
        virtual void execute();

    private:

};

#endif // EVALUATEPROGRAM_H
