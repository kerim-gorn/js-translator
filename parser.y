%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>
#include "semantic.h"
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
%token CONSOLE_IN
%token CONSOLE_OUT
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
%type <stmt_value> stmt  while_stmt do_while_stmt  console_in console_out    
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
program: stmt_list { $$ = root = $1;}
	;

exp:   DIGIT						{printf("DIGIT is printed\n"); $$ = createDigitExpr($1);}
    |  FLOAT_DIGIT					{printf("FLOAT_DIGIT is printed\n");$$ = createFloatExpr($1);}
    |  type ID						{printf("ID is printed\n");$$ = createVariableExpr($2);}
	|  ID						    {printf("ID is printed\n");$$ = createVariableExpr($1);}
    |  STRINGONEQOUTED				{printf("STRINGONEQOUTED is printed\n");$$ = createVariableExpr($1);}
    |  STRINGDOUBLEQUOTED			{printf("STRINGDOUBLEQUOTED is printed\n");$$ = createVariableExpr($1);}
	| exp '[' exp ']'				{printf("exp \'[\' exp \']\' worked\n"); $$ = createBinaryOpeartionExpr(array_element_access, $1, $3);}
	| '(' exp ')' 					{printf("\'(\' exp \')\' worked\n"); $$ = $2;}
	| exp '+' exp 					{printf("exp + exp  worked\n");$$ = createBinaryOpeartionExpr(Plus, $1 , $3);}
	| exp '-' exp 					{printf("exp - exp  worked\n");$$ = createBinaryOpeartionExpr(Minus, $1 , $3);}	
	| exp '*' exp 					{printf("exp * exp  worked\n");$$ = createBinaryOpeartionExpr(Mul, $1 , $3);}
	| exp '/' exp 					{printf("exp / exp  worked\n");$$ = createBinaryOpeartionExpr(Div, $1 , $3);}
	| exp '%' exp					{printf("exp Remi exp  worked\n");$$ = createBinaryOpeartionExpr(Remi, $1 , $3);}
	| exp EQUAL exp 				{printf("exp EQUAL exp  worked\n");$$ = createBinaryOpeartionExpr(EQ, $1 , $3);}
	| exp STRICT_EQUAL exp  		{printf("exp STRICT_EQUAL exp  worked\n");$$ = createBinaryOpeartionExpr(SEQ, $1 , $3);}
	| exp NOT_EQUAL exp 			{printf("exp NOT_EQUAL exp  worked\n");$$ = createBinaryOpeartionExpr(NEQ, $1 , $3);}
	| exp '>' exp 					{printf("exp > exp  worked\n");$$ = createBinaryOpeartionExpr(GR, $1 , $3);}
	| exp '<' exp  					{printf("exp < exp  worked\n");$$ = createBinaryOpeartionExpr(SM, $1 , $3);}
	| exp BIGGER_EQUAL exp 			{printf("exp >= exp  worked\n");$$ = createBinaryOpeartionExpr(GREQ, $1 , $3);}
	| exp SMALLER_EQUAL exp 		{printf("exp <= exp  worked\n");$$ = createBinaryOpeartionExpr(SMEQ, $1 , $3);}
	| exp ASSIGNMENT exp 			{printf("exp = exp  worked\n");$$ = createBinaryOpeartionExpr(Assign, $1 , $3);}
	| exp POW exp					{printf("exp POW exp  worked\n");$$ = createBinaryOpeartionExpr(Pow, $1 , $3);}
	| exp OR exp 					{printf("exp OR exp  worked\n");$$ = createBinaryOpeartionExpr(Or, $1 , $3);}
	| exp AND exp 					{printf("exp AND exp  worked\n");$$ = createBinaryOpeartionExpr(And, $1 , $3);}
	| NOT exp						{printf("NOT exp  worked\n");$$ = createUnaryOpeartionExpr(Not, $2 );}
	| '+' exp %prec UPLUS			{printf(" + exp  worked\n");$$ = createUnaryOpeartionExpr(Uplu, $2 );}
	| '-' exp %prec UMINUS 		{printf(" - exp  worked\n");$$ = createUnaryOpeartionExpr(Umin, $2 );}
	;
	

stmt: /*empty*/ SEMICOLON  newline_seq_opt						{printf("empty stmt \n"); $$=createStmtNull();}
	| BREAK SEMICOLON newline_seq_opt 		 			{printf("create break stmt\n"); $$=createStmtBreak();}
	| BREAK newline_seq				 		 			{printf("create break stmt\n"); $$=createStmtBreak();}
	| exp SEMICOLON  newline_seq_opt         	    	{$$ = createStmt($1);}
	| exp newline_seq          							{$$ = createStmt($1);}
	| '{' newline_seq_opt stmt_list '}' newline_seq_opt					{$$ = createBlockStmt($3);}
    | array_handling 									{$$= createArray($1); }     
	| if_stmt 											{$$= FillIfStmt($1);}
	| for_stmt											{$$= FillForStmt($1); }
	| while_stmt										{$$= $1; }
	| do_while_stmt										{$$= $1; }
	| switch_stmt									{printf("                     fillSwitchStmt worked\n");$$= fillSwitchStmt($1);}
	| for_of											{$$= fillForOfStmt($1); }
	| console_in										{$$= $1; }
	| console_out										{$$= $1; }
	;
	

stmt_list: 	stmt 				{printf("                 stmt is created\n");$$ = createStmtList($1);}		 
		| stmt_list stmt		{printf("                 addToStmtList is preformed\n");$$ = addToStmtList($1, $2);}									
		;

type: LET
    | VAR
	| CONST
	;
if_stmt: IF newline_seq_opt '('  exp ')' stmt									{printf("                    IfStmt is worked\n"); $$ = createIfStmt($4, $6, NULL);}
		| IF newline_seq_opt '(' exp ')' stmt ELSE stmt							{printf("                    IfElseStmt is worked\n"); $$ = createIfStmt($4, $6, $8);}
		| IF  newline_seq_opt '(' exp ')' stmt elseif_stmt_list					{printf("                    If and ElseIf is worked\n"); $$ = createElseIfStmt($4, $6, $7,NULL);}
		| IF newline_seq_opt '(' exp ')' stmt elseif_stmt_list ELSE stmt		{printf("                    If, ElseIf and Else is worked"); $$ = createElseIfStmt($4, $6, $7, $9);} 
		;
		
elseif_stmt_list: elseif_stmt  					{$$ = createElseIfStmtList($1);}
		| elseif_stmt_list  elseif_stmt 		{$$ = addToElseIfStmtList($1, $2);}
		;
elseif_stmt: ELSEIF '(' exp ')' newline_seq_opt stmt            {$$ = createSimpleElseIfStmt($3,$6);}
			;
 		
for_stmt: FOR '(' exp SEMICOLON exp SEMICOLON exp ')' stmt {$$ = createForStmt($3, $5, $7, $9);}
		;

while_stmt: WHILE '(' exp ')' stmt    {$$ = createWhileStmt($3, $5);} 
			;
 
do_while_stmt: DO stmt WHILE '('  exp ')' SEMICOLON newline_seq_opt {$$ = createDoWhileStmt($2, $5);} 
			; 


switch_stmt: SWITCH '(' exp ')' '{' newline_seq_opt  case_stmt_list  '}' newline_seq_opt					 {printf("          createSwitchStmt is worked\n"); $$ = createSwitchStmt($3, $7,NULL)}
			| SWITCH '(' exp ')' '{' newline_seq_opt case_stmt_list default_stmt'}' 	newline_seq_opt 	 {printf("          createSwitchStmt is worked\n"); $$ = createSwitchStmt($3, $7,$8)}
			; 


case_stmt_list: case_stmt                       {printf("          createCaseStmtList is worked\n");$$ = createCaseStmtList($1);}
			| case_stmt_list case_stmt			{printf("          addToCaseStmtList is worked\n");$$ = addToCaseStmtList($1, $2);}
			;
				
case_stmt: CASE exp ':'	newline_seq_opt											{printf("          newline_seq_opt is worked\n");$$ = createCaseStmt($2, NULL);}
			| CASE exp ':' newline_seq_opt stmt_list 			{printf("          CASE exp ':' newline_seq_opt stmt_list is worked\n"); $$ = createCaseStmt($2, $5);}
		//	| CASE exp ':'  NEWLINE BREAK SEMICOLON NEWLINE				{printf("          CASE exp ':'  NEWLINE BREAK SEMICOLON NEWLINE is worked\n"); $$ = createCaseStmt($2, NULL);}
		//	| CASE exp ':' NEWLINE stmt_list BREAK SEMICOLON NEWLINE	{printf("          CASE exp ':' NEWLINE stmt_list BREAK SEMICOLON NEWLINE is worked\n"); $$ = createCaseStmt($2, $5);}
			;
default_stmt: DEFAULT ':' newline_seq_opt stmt_list      					    {printf("          DEFAULT ':' newline_seq_opt stmt_list stmt_list  is worked\n");$$ = createDefaultStmt($4);}
		//	| DEFAULT ':' newline_seq_opt BREAK SEMICOLON NEWLINE				{printf("          DEFAULT ':' NEWLINE BREAK SEMICOLON NEWLINE is worked\n");$$ = createDefaultStmt(NULL);}
		//	| DEFAULT ':' NEWLINE stmt_list  BREAK SEMICOLON NEWLINE	{printf("          DEFAULT ':' NEWLINE stmt_list  BREAK SEMICOLON NEWLINE is worked\n");$$ = createDefaultStmt($4);}
			;
newline_seq: NEWLINE newline_seq_opt
			;
newline_seq_opt: /*empty*/
				| newline_seq_opt NEWLINE
				;
for_of : FOR '(' exp OF exp ')'  stmt        {$$ = createForOfStmt($3, $5, $7);}
		;
 
array_handling: exp ASSIGNMENT '[' expr_list ']' SEMICOLON NEWLINE {$$ = createArrayHandlingStmt($1, $4);}
 			  ;

expr_list: exp					 {printf("             expr is created\n");$$ = createExprList($1);}
		 | expr_list ',' exp     {printf("             addToExpr is preformed\n");$$ = addToExprList($1, $3);}
	   	 ;


console_in: CONSOLE_IN '(' exp  ')' SEMICOLON newline_seq_opt 	{$$ = createConsoleInStmt($3);}
		  | CONSOLE_IN '(' exp  ')'  newline_seq			 	{$$ = createConsoleInStmt($3);}
		  ;   

console_out: CONSOLE_OUT '(' exp ')' SEMICOLON newline_seq_opt 	{$$ = createConsoleOutStmt($3);}
			| CONSOLE_OUT '(' exp ')' newline_seq				{$$ = createConsoleOutStmt($3);}
	 	   ;
%%

void main(int argc, char *argv[]){

	if(argc>1)
		yyin = fopen(argv[1], "r");
	yyparse();
	char outPutFilename[50];
	sprintf(outPutFilename,"%s","output_");
	strcat(outPutFilename, argv[1]);
	FILE * _filename;
	_filename = fopen(outPutFilename, "w");
	if(_filename == NULL ) yyerror("Eorror opening file");
	else{
		printf("Printing Tree\n");
		write_tree(_filename);
		printf("Tree is printed in output_<filename>\n");
	}
	
	fclose(_filename);
	getch();
}


