#include "evaluate_program.h"
#include "headerexp.h"
#include "calc.tab.h"
#include <iostream>
#include <fstream>
#include <stdio.h>


EvaluateProgram::EvaluateProgram(string name) :MenuOption::MenuOption(name)
{
    //ctor
}

EvaluateProgram::~EvaluateProgram()
{
    //dtor
}

void EvaluateProgram::execute()
{
    string filename;
    do{
        std::cout << "insert a file: " ;
        std::cin >> filename;
        yyin = fopen(filename.c_str(), "r");
        if(yyin != NULL){
			yyparse();
			fclose(yyin);
		} else {
			std::cerr << "Filename doesn't exists" << std::endl;
		}
    } while(yyin == NULL);
}
