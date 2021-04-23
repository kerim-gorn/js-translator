%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>
#include "print_tree.h"

extern FILE* yyin;
%}

%error-verbose
%union{
	int Int_val;
	float Float;
	char *Id;
	struct expr_struct* expr_value;
	struct expr_list_struct* expr_list_value;
	struct stmt_struct* stmt_value;
	struct stmt_list_struct* stmt_list_value;
	struct array_handling_struct* array_handling_value;
	struct if_stmt_struct* if_stmt_value;
	struct elseif_stmt_struct* elseif_stmt_value;
	struct elseif_stmt_list_struct* elseif_stmt_list_value;
	struct for_stmt_struct* for_stmt_value;
	struct forOf_stmt_struct* forOf_stmt_value;
	struct switch_stmt_struct* switch_stmt_value;
	struct case_stmt_struct* case_stmt_value;
	struct default_stmt_struct* default_stmt_value;
	struct case_stmt_list_struct *case_stmt_list_value;
}
%start program
%token <Int_val> DIGIT
%token <Float> FLOAT_DIGIT
%token <Id> ID
%token <Id> STRINGONEQOUTED
%token <Id> STRINGDOUBLEQUOTED
%token EQUAL
%token STRICT_EQUAL
%token NOT_EQUAL
%token BIGGER_EQUAL
%token SMALLER_EQUAL
%token ASSIGNMENT
%token POW "**"
%token OR
%token NOT
%token AND

%token IF
%token ELSE
%token ELSEIF
%token FOR 
%token WHILE
%token DO
%token SWITCH
%token CASE
%token BREAK
%token DEFAULT
%token OF
%token INPUT
%token OUTPUT
%token SEMICOLON
%token NEWLINE
%token LET
%token VAR
%token CONST
%token FINAL


%left ASSIGNMENT
%left OR AND NOT
%left EQUAL STRICT_EQUAL NOT_EQUAL
%left '>' '<' BIGGER_EQUAL SMALLER_EQUAL
%left '+' '-'
%left '*' '/' '%'
%left POW
%left UMINUS UPLUS
%left '[' ']'
%nonassoc ')'

%type <expr_value> exp
%type <expr_list_value> expr_list
%type <stmt_value> stmt  while_stmt do_while_stmt  input output    
%type <if_stmt_value>if_stmt
%type <stmt_list_value> program stmt_list  
%type <elseif_stmt_list_value> elseif_stmt_list
%type <elseif_stmt_value> elseif_stmt
%type <for_stmt_value> for_stmt
%type <forOf_stmt_value>  for_of
%type <array_handling_value> array_handling
%type <switch_stmt_value> switch_stmt
%type <case_stmt_list_value> case_stmt_list
%type <default_stmt_value> default_stmt
%type <case_stmt_value> case_stmt
%%
program: stmt_list { $$ = root = $1;};

exp:   DIGIT						{printf("DIGIT is printed\n"); $$ = create_digit_expr($1);}
    |  FLOAT_DIGIT					{printf("FLOAT_DIGIT is printed\n");$$ = create_float_expr($1);}
    |  type ID						{printf("ID is printed\n");$$ = create_variable_expr($2);}
	|  ID						    {printf("ID is printed\n");$$ = create_variable_expr($1);}
    |  STRINGONEQOUTED				{printf("STRINGONEQOUTED is printed\n");$$ = create_variable_expr($1);}
    |  STRINGDOUBLEQUOTED			{printf("STRINGDOUBLEQUOTED is printed\n");$$ = create_variable_expr($1);}
	| exp '[' exp ']'				{printf("exp \'[\' exp \']\' worked\n"); $$ = create_binary_operation_expr(array_element_access, $1, $3);}
	| '(' exp ')' 					{printf("\'(\' exp \')\' worked\n"); $$ = $2;}
	| exp '+' exp 					{printf("exp + exp  worked\n");$$ = create_binary_operation_expr(Plus, $1 , $3);}
	| exp '-' exp 					{printf("exp - exp  worked\n");$$ = create_binary_operation_expr(Minus, $1 , $3);}	
	| exp '*' exp 					{printf("exp * exp  worked\n");$$ = create_binary_operation_expr(Multiplication, $1 , $3);}
	| exp '/' exp 					{printf("exp / exp  worked\n");$$ = create_binary_operation_expr(Division, $1 , $3);}
	| exp '%' exp					{printf("exp Remi exp  worked\n");$$ = create_binary_operation_expr(Reminder, $1 , $3);}
	| exp EQUAL exp 				{printf("exp EQUAL exp  worked\n");$$ = create_binary_operation_expr(EQ, $1 , $3);}
	| exp STRICT_EQUAL exp  		{printf("exp STRICT_EQUAL exp  worked\n");$$ = create_binary_operation_expr(SEQ, $1 , $3);}
	| exp NOT_EQUAL exp 			{printf("exp NOT_EQUAL exp  worked\n");$$ = create_binary_operation_expr(NEQ, $1 , $3);}
	| exp '>' exp 					{printf("exp > exp  worked\n");$$ = create_binary_operation_expr(GR, $1 , $3);}
	| exp '<' exp  					{printf("exp < exp  worked\n");$$ = create_binary_operation_expr(SM, $1 , $3);}
	| exp BIGGER_EQUAL exp 			{printf("exp >= exp  worked\n");$$ = create_binary_operation_expr(GREQ, $1 , $3);}
	| exp SMALLER_EQUAL exp 		{printf("exp <= exp  worked\n");$$ = create_binary_operation_expr(SMEQ, $1 , $3);}
	| exp ASSIGNMENT exp 			{printf("exp = exp  worked\n");$$ = create_binary_operation_expr(Assign, $1 , $3);}
	| exp POW exp					{printf("exp POW exp  worked\n");$$ = create_binary_operation_expr(Pow, $1 , $3);}
	| exp OR exp 					{printf("exp OR exp  worked\n");$$ = create_binary_operation_expr(Or, $1 , $3);}
	| exp AND exp 					{printf("exp AND exp  worked\n");$$ = create_binary_operation_expr(And, $1 , $3);}
	| NOT exp						{printf("NOT exp  worked\n");$$ = create_unary_operation_expr(Not, $2 );}
	| '+' exp %prec UPLUS			{printf(" + exp  worked\n");$$ = create_unary_operation_expr(unary_plus, $2 );}
	| '-' exp %prec UMINUS 		{printf(" - exp  worked\n");$$ = create_unary_operation_expr(unary_minus, $2 );}	;
	
stmt:  SEMICOLON  newline_seq_opt						{printf("empty stmt \n"); $$=create_stmt_null();}
	| BREAK SEMICOLON newline_seq_opt 		 			{printf("create break stmt\n"); $$=create_stmt_break();}
	| BREAK newline_seq				 		 			{printf("create break stmt\n"); $$=create_stmt_break();}
	| exp SEMICOLON  newline_seq_opt         	    	{$$ = create_stmt($1);}
	| exp newline_seq          							{$$ = create_stmt($1);}
	| '{' newline_seq_opt stmt_list '}' newline_seq_opt	{$$ = create_block_stmt($3);}
    | array_handling 									{$$= create_array($1); }     
	| if_stmt 											{$$= fill_if_stmt($1);}
	| for_stmt											{$$= fill_for_stmt($1); }
	| while_stmt										{$$= $1; }
	| do_while_stmt										{$$= $1; }
	| switch_stmt										{printf("fill_switch_stmt worked\n");$$= fill_switch_stmt($1);}
	| for_of											{$$= fill_for_of_stmt($1); }
	| input										{$$= $1; }
	| output										{$$= $1; }	;
	

stmt_list: 	stmt 				{printf("stmt is created\n");$$ = create_stmt_list($1);}		 
		| stmt_list stmt		{printf("add_to_stmt_list is preformed\n");$$ = add_to_stmt_list($1, $2);}	;

type: LET | VAR	| CONST	;
if_stmt: IF newline_seq_opt '('  exp ')' stmt									
				{printf("IfStmt is worked\n"); $$ = create_if_stmt($4, $6, NULL);}
		| IF newline_seq_opt '(' exp ')' stmt ELSE stmt							
				{printf("IfElseStmt is worked\n"); $$ = create_if_stmt($4, $6, $8);}
		| IF  newline_seq_opt '(' exp ')' stmt elseif_stmt_list					
				{printf("If and ElseIf is worked\n"); $$ = create_else_if_stmt($4, $6, $7,NULL);}
		| IF newline_seq_opt '(' exp ')' stmt elseif_stmt_list ELSE stmt		
				{printf("If, ElseIf and Else is worked"); $$ = create_else_if_stmt($4, $6, $7, $9);};
		
elseif_stmt_list: elseif_stmt  					{$$ = create_else_if_stmt_list($1);}
		| elseif_stmt_list  elseif_stmt 		{$$ = add_to_else_if_stmt_list($1, $2);}	;

elseif_stmt: ELSEIF '(' exp ')' newline_seq_opt stmt            {$$ = create_simple_else_if_stmt($3,$6);};
 		
for_stmt: FOR '(' exp SEMICOLON exp SEMICOLON exp ')' stmt {$$ = create_for_stmt($3, $5, $7, $9);};

while_stmt: WHILE '(' exp ')' stmt    {$$ = create_while_stmt($3, $5);};
 
do_while_stmt: DO stmt WHILE '('  exp ')' SEMICOLON newline_seq_opt {$$ = create_do_while_stmt($2, $5);}; 

switch_stmt: SWITCH '(' exp ')' '{' newline_seq_opt  case_stmt_list  '}' newline_seq_opt					 
								{printf("create_switch_stmt is worked\n"); $$ = create_switch_stmt($3, $7,NULL); }
			| SWITCH '(' exp ')' '{' newline_seq_opt case_stmt_list default_stmt'}' 	newline_seq_opt 	
								{printf("create_switch_stmt is worked\n"); $$ = create_switch_stmt($3, $7,$8); }; 

case_stmt_list: case_stmt                       {printf("create_case_stmt_list is worked\n");$$ = create_case_stmt_list($1);}
			| case_stmt_list case_stmt			{printf("add_to_case_stmt_list is worked\n");$$ = add_to_case_stmt_list($1, $2);};
				
case_stmt: CASE exp ':'	newline_seq_opt							
						{printf("newline_seq_opt is worked\n");$$ = create_case_stmt($2, NULL);}
			| CASE exp ':' newline_seq_opt stmt_list 			
						{printf("CASE exp ':' newline_seq_opt stmt_list is worked\n"); $$ = create_case_stmt($2, $5);};
default_stmt: DEFAULT ':' newline_seq_opt stmt_list      					   
						{printf("DEFAULT ':' newline_seq_opt stmt_list stmt_list  is worked\n");$$ = create_default_stmt($4);};
newline_seq: NEWLINE newline_seq_opt;
newline_seq_opt: | newline_seq_opt NEWLINE;
for_of : FOR '(' exp OF exp ')'  stmt  {$$ = create_for_of_stmt($3, $5, $7);};
 
array_handling: exp ASSIGNMENT '[' expr_list ']' SEMICOLON NEWLINE {$$ = create_array_handling_stmt($1, $4);};

expr_list: exp					 {printf("expr is created\n");$$ = create_expr_list($1);}
		 | expr_list ',' exp     {printf("addToExpr is preformed\n");$$ = add_to_expr_list($1, $3);};

input: INPUT '(' exp  ')' SEMICOLON newline_seq_opt 	{$$ = create_console_in_stmt($3);}
		  | INPUT '(' exp  ')'  newline_seq			 	{$$ = create_console_in_stmt($3);};   

output: OUTPUT '(' exp ')' SEMICOLON newline_seq_opt 	{$$ = create_console_out_stmt($3);}
			| OUTPUT '(' exp ')' newline_seq				{$$ = create_console_out_stmt($3);};
%%

int main(int argc, char *argv[]){

	if(argc>1)
		{	
			yyin = fopen(argv[1], "r");
		}
	yyparse();
	FILE * _filename;
	_filename = fopen(argv[2], "w");
	if(_filename == NULL ) 
		yyerror("Error opening file");
	else
		{
		printf("Printing Tree\n");
		write_tree(_filename);
		printf("Tree is printed in output.txt\n");
		}
	
	fclose(_filename);
	
}


