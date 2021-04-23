%option noyywrap
%option never-interactive
%option nounput yylineno
%{
	#include "parser.tab.h"
	#include <stdlib.h>
	#include <math.h>

    #include <string.h>

		
    extern void write_tree(FILE *_filename);
	extern void yyerror(char const *s);
	extern int yyparse(void);
    char octalToDecimal(char* octal);
%}

%x STRING
%x STRING_DOUBLE_QUOTED
%x MCOMMENT
%x LCOMMENT
%x HLCOMMENT
	
DIGIT   [0-9]+
ID      [$_a-zA-Z][$_a-zA-Z0-9]*

%%

%{
    char str[1000];
	char temp[2];
%}


	//Reserved Keywords ECMAScript 2015
break		{printf("break is here\n");return BREAK;}
	case		{return CASE;}
	default		{return DEFAULT;}
	do			{return DO;}
	if			{printf("if is found\n");return IF;}
	else		{printf("else is found\n");return ELSE;}
	"else if"  	{printf("else if is found\n");return ELSEIF;}
	for			{return FOR;}
	of			{return OF;}
	switch		{return SWITCH;}
    var     	{return VAR;}
	let     	{return LET;}
	const       {return CONST;}
	while		{return WHILE;}
	final		{return FINAL;}


	console_in   {return CONSOLE_IN;}
	console_out	{return CONSOLE_OUT;}
 
    "+"     {printf("Found Operator: +\n"); return '+';}
    "-"     {printf("Found Operator: -\n"); return '-';}
    "/"     {printf("Found Operator: /\n"); return '/';}
    "*"     {printf("Found Operator: *\n"); return '*';}
	"%"		{printf("Found Operator: %\n"); return '%';}
	"**"	{printf("Found Operator: **\n"); return POW;}
    "="     {printf("Found Operator: =\n"); return ASSIGNMENT;}
    "=="    {printf("Found Operator: ==\n"); return EQUAL;}
	"==="   {printf("Found Operator: ===\n"); return STRICT_EQUAL;}
	"!="	{printf("Found Operator: !=\n"); return NOT_EQUAL;}
	">"		{printf("Found Operator: >\n"); return '>';}
	"<"		{printf("Found Operator: <\n"); return '<';}
	">="	{printf("Found Operator: =>\n"); return BIGGER_EQUAL;}
	"<="	{printf("Found Operator: <=\n"); return SMALLER_EQUAL;}
    "!"     {printf("Found Operator: !\n"); return NOT;}
    "||"    {printf("Found Operator: ||\n"); return OR ;}
    "&&"    {printf("Found Operator: &&\n"); return AND;}
    "{"     {printf("Found Token: {\n"); return '{';}
    "}"     {printf("Found Token: }\n"); return '}';}
	"["		{printf("Found Token: [\n"); return '[';}
	"]"		{printf("Found Token: ]\n"); return ']';}
    "("     {printf("Found Token: (\n"); return '(';}
    ")"     {printf("Found Token: )\n"); return ')';}
    ";"     {printf("Found Token: ;\n"); return SEMICOLON;}
	","     {printf("Found Token: ,\n"); return ',';}
	":"		{printf("Found Token: :\n"); return ':';}
	
    {ID}	{printf("variable : %s\n", yytext);yylval.Id = (char *)malloc(sizeof(yytext)+1);
			strcpy(yylval.Id, yytext);
			return ID;}
    {DIGIT} {printf("find number %d \n",atoi(yytext)); yylval.Int_val = atoi(yytext);
			return DIGIT;}
	{DIGIT}+\.{DIGIT}+ {printf("find number %f \n",atof(yytext));yylval.Float = atof(yytext);
						return FLOAT_DIGIT;}

\t 		;
\n		{printf("NewLine \\n \n");return NEWLINE;}
" "		;
\'      {strcpy(str," "); BEGIN(STRING);}
\" 		{strcpy(str," "); BEGIN(STRING_DOUBLE_QUOTED);}
        
	<STRING,STRING_DOUBLE_QUOTED>\\\'       {strcat(str, "\'");}
    <STRING,STRING_DOUBLE_QUOTED>\\\"       {strcat(str, "\"");}
    <STRING,STRING_DOUBLE_QUOTED>\\\\       {strcat(str, "\\");}
    <STRING,STRING_DOUBLE_QUOTED>\\n        {strcat(str, "\n");}
    <STRING,STRING_DOUBLE_QUOTED>\\r        {strcat(str, "\r");}
    <STRING,STRING_DOUBLE_QUOTED>\\v        {strcat(str, "\v");}
    <STRING,STRING_DOUBLE_QUOTED>\\t        {strcat(str, "\t");}
    <STRING,STRING_DOUBLE_QUOTED>\\b        {strcat(str, "\b");}
    <STRING,STRING_DOUBLE_QUOTED>\\f        {strcat(str, "\f");}
	<STRING,STRING_DOUBLE_QUOTED>\\\n		;
	<STRING,STRING_DOUBLE_QUOTED>\n		{printf("there is an error in line: %d\n",yylineno);BEGIN(INITIAL);}	
    <STRING,STRING_DOUBLE_QUOTED>\\[0-7]{1,3} {temp[0] = octalToDecimal(yytext); temp[1] = 0; strcat(str, temp );}
    <STRING,STRING_DOUBLE_QUOTED>[^\'\"\\\n\r\v\b\f]+   {strcat(str,yytext);}
	
	<STRING_DOUBLE_QUOTED><<EOF>>	{printf("The \" is not closed in line: %d\n", yylineno); BEGIN(INITIAL);}
    <STRING_DOUBLE_QUOTED>\"          {printf("Double Quoted String: %s\n",str); yylval.Id = (char *)malloc(sizeof(str)+1);
										strcpy(yylval.Id,str);  BEGIN(INITIAL); return STRINGDOUBLEQUOTED;}
	
	<STRING><<EOF>>	{printf("The \' is not closed in line: %d\n", yylineno); BEGIN(INITIAL);}
	<STRING>\' {printf("Single Quoted String: %s\n",str); yylval.Id = (char *)malloc(sizeof(str)+1);
				strcpy(yylval.Id, str); BEGIN(INITIAL); return STRINGONEQOUTED; }
		
	\/\*  BEGIN(MCOMMENT);
		
	<MCOMMENT>[^*]* 
	<MCOMMENT>"*"+[^*/]* 
	<MCOMMENT>"*"+"/"  {printf("					Multi-Line Comment\n");BEGIN(INITIAL);}
		
		
	\/\/ {printf("					One Line Comment\n"); BEGIN(LCOMMENT);}
	<LCOMMENT>.* { BEGIN(INITIAL);}
		
		#!	{ printf("Hashbang Comment"); BEGIN(HLCOMMENT);	}
	<HLCOMMENT>.* { BEGIN(INITIAL);}
			
%%


/*
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
	
}
*/
char octalToDecimal(char* octalValue){
        char returnValue;
        int octal=0,decimal=0,i=0,j=0;
        if(strncmp(octalValue,"\\",1)==0)
            for(i=0; i<4; i++)
                octalValue[i]=octalValue[i+1];

        octalValue[3]=0;
        octal = atoi(octalValue);
        
        while(octal!=0){
            decimal =  decimal +(octal % 10)* pow(8, j++);
            octal = octal / 10;
        }
		//returnValue = itoa(decimal, returnValue ,10);
		returnValue = (char)decimal;

        return returnValue;
    }
	


   


