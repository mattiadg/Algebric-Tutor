%{
	#include <math.h>
	#include <stdio.h>
	#include <list>
	#include "headerexp.h"
	void yyerror (char const *);
	double tmp;
	
	extern int yylex();
	extern FILE * yyin;
%}

%union{
	Expression *espr;
	Bloc *bloc;
	Condition *cond;
	double double_t;
	Variable *var_t;
	list<Expression*> *list_exp;
	char* char_t;
}

%error-verbose
%token <double_t>NUM_REAL
%token <char_t>VAR
%token SIN COS EXP IF ELSE LEQ GEQ FOR
%left '+'
%left '-'
%left '*'
%left '/'
%left '?'
%left ':'

%type <espr>right
%type <char_t>left
%type <espr>assg
%type <espr>right_exp
%type <espr> conditional
%type <espr> instruction
%type <espr> construct
%type <bloc> block
%type <list_exp> instructions
%type <list_exp> commands
%type <cond>cond_exp
%type <espr> for

%start program

%%

program : instructions 					{Expression::toutLiberer();}

instructions: instructions instruction  {$1->push_back($2); printf("%.4f\n", $2->eval());}
		  | instructions construct  	{$1->push_back($2);}
		  | instruction 				{std::list<Expression*> *exps = new std::list<Expression*>; exps->push_back($1); $$ = exps;  printf("%.4f\n", $1->eval());}
		  | construct 					{std::list<Expression*> *exps = new std::list<Expression*>; exps->push_back($1); $$ = exps; $1->eval();}		 
		  ;

instruction: assg ';'								{$$ = $1;}
	   | right_exp ';'								{$$ = $1;}									
	 ;
	 
construct: conditional ';'							{$$ = $1; $1->eval();}
		| block ';'									{$$ = $1; printf("%.4f\n", $1->eval());} 
		| for	';'									{$$ = $1; $1->eval();}
		;

block: '{' commands '}'								{$$=new Bloc(string("Bloc"), *$2);}

commands: commands instruction  		{$1->push_back($2);}
		  | commands construct  		{$1->push_back($2);}
		  | instruction 				{std::list<Expression*> *exps = new std::list<Expression*>; exps->push_back($1); $$ = exps; }
		  | construct 					{std::list<Expression*> *exps = new std::list<Expression*>; exps->push_back($1); $$ = exps; }		 
		  ;
assg: left '=' right_exp							{$$=new Affectation($1, $3);}
	;
	
conditional: IF '(' cond_exp ')' block ELSE block     {$$=new Si_alors_sinon($3,$5,$7);}
	;
	
for: FOR '(' assg ';' cond_exp ';' assg ')' block	  {$$ = new Pour($3, $5, $7, $9);}
	;

right_exp: right									{$$=$1;}
	| right_exp '+' right_exp				        {$$=new Somme($1,$3);}
	| right_exp '-' right_exp				        {$$=new Difference($1,$3);}
	| right_exp '*' right_exp				        {$$=new Produit($1,$3);}
	| right_exp '/' right_exp				        {$$=new Division($1,$3);}
	| '(' right_exp ')'				                {$$=$2;}
	| SIN '(' right_exp ')'			                {$$=new Sin($3);}
	| COS '(' right_exp ')'			                {$$=new Cos($3);}
	| EXP '(' right_exp ')'			                {$$=new Exponentielle($3);}
	| '(' cond_exp ')' '?' right_exp ':' right_exp  {$$=new Conditionnel($2,$5,$7);}
	;

cond_exp: right_exp LEQ right_exp              		{$$=new Inferieur($1,$3);}
        | right_exp GEQ right_exp              		{$$=new Superieur($1,$3);}
        ;

right: NUM_REAL						    			{$$=new Constante($1);}
	| VAR											{$$=Variable::getVariable($1);}
    ;
    
left: VAR											{$$=$1;}
	;

%%

