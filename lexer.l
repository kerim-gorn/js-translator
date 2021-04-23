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

%x SINGLE_QUOTES_STRING
%x DOUBLE_QUOTES_STRING
%x MULTILINE_COMMENT
	
DIGIT   [0-9]+
ID      [$_a-zA-Z][$_a-zA-Z0-9]*

%%

%{
  char str[1000];
	char temp[2];
%}

break		  {printf("Found break\n");return BREAK;}
case		  {printf("Found case\n"); return CASE;}
default		{printf("Found default\n"); return DEFAULT;}
do			  {printf("Found do\n"); return DO;}
if			  {printf("Found if\n");return IF;}
else		  {printf("Found else\n");return ELSE;}
"else if" {printf("Found else if\n");return ELSEIF;}
for			  {printf("Found for\n"); return FOR;}
of			  {printf("Found of\n"); return OF;}
switch		{printf("Found switch\n"); return SWITCH;}
var     	{printf("Found var\n"); return VAR;}
let     	{printf("Found let\n"); return LET;}
const     {printf("Found const\n"); return CONST;}
while		  {printf("Found while\n"); return WHILE;}
final		  {printf("Found final\n"); return FINAL;}

input     {printf("Found input\n"); return INPUT;}
output	  {printf("Found output\n"); return OUTPUT;}

"+"       {printf("Found +\n"); return '+';}
"-"       {printf("Found -\n"); return '-';}
"/"       {printf("Found /\n"); return '/';}
"*"       {printf("Found *\n"); return '*';}
"%"		    {printf("Found %\n"); return '%';}
"**"	    {printf("Found **\n"); return POW;}
"="       {printf("Found =\n"); return ASSIGNMENT;}
"=="      {printf("Found ==\n"); return EQUAL;}
"==="     {printf("Found ===\n"); return STRICT_EQUAL;}
"!="	    {printf("Found !=\n"); return NOT_EQUAL;}
">"		    {printf("Found >\n"); return '>';}
"<"		    {printf("Found <\n"); return '<';}
">="	    {printf("Found =>\n"); return BIGGER_EQUAL;}
"<="	    {printf("Found <=\n"); return SMALLER_EQUAL;}
"!"       {printf("Found !\n"); return NOT;}
"||"      {printf("Found ||\n"); return OR ;}
"&&"      {printf("Found &&\n"); return AND;}
"{"       {printf("Found {\n"); return '{';}
"}"       {printf("Found }\n"); return '}';}
"["	  	  {printf("Found [\n"); return '[';}
"]"		    {printf("Found ]\n"); return ']';}
"("       {printf("Found (\n"); return '(';}
")"       {printf("Found )\n"); return ')';}
";"       {printf("Found ;\n"); return SEMICOLON;}
","       {printf("Found ,\n"); return ',';}
":"		    {printf("Found :\n"); return ':';}

{ID}	  {
  printf("variable : %s\n", yytext);
  yylval.Id = (char *)malloc(sizeof(yytext)+1);
  strcpy(yylval.Id, yytext);
  return ID;
}
{DIGIT} {
  printf("find number %d \n",atoi(yytext));
  yylval.Int_val = atoi(yytext);
  return DIGIT;
}
{DIGIT}+\.{DIGIT}+ {
  printf("find number %f \n",atof(yytext));
  yylval.Float = atof(yytext);
  return FLOAT_DIGIT;
}

\t 		;
\n		{printf("NewLine \\n \n");return NEWLINE;}
" "		;
\'    {strcpy(str," "); BEGIN(SINGLE_QUOTES_STRING);}
\" 		{strcpy(str," "); BEGIN(DOUBLE_QUOTES_STRING);}
        
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\\'   {strcat(str, "\'");}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\\"   {strcat(str, "\"");}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\\\   {strcat(str, "\\");}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\n    {strcat(str, "\n");}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\r    {strcat(str, "\r");}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\v    {strcat(str, "\v");}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\t    {strcat(str, "\t");}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\b    {strcat(str, "\b");}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\f    {strcat(str, "\f");}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\\n		;
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\n		  {
  printf("there is an error in line: %d\n",yylineno);
  BEGIN(INITIAL);
}

<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\[0-7]{1,3} {
  temp[0] = octalToDecimal(yytext);
  temp[1] = 0; strcat(str, temp );
}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>[^\'\"\\\n\r\v\b\f]+   {strcat(str,yytext);}
	
<DOUBLE_QUOTES_STRING><<EOF>>	{
  printf("The \" is not closed in line: %d\n", yylineno);
  BEGIN(INITIAL);
}

<DOUBLE_QUOTES_STRING>\" {
  printf("Double Quoted String: %s\n",str);
  yylval.Id = (char *)malloc(sizeof(str)+1);
  strcpy(yylval.Id,str);  BEGIN(INITIAL); return STRINGDOUBLEQUOTED;
}
	
<SINGLE_QUOTES_STRING><<EOF>>	{
  printf("The \' is not closed in line: %d\n", yylineno);
  BEGIN(INITIAL);
}
<SINGLE_QUOTES_STRING>\' {
  printf("Single Quoted String: %s\n",str);
  yylval.Id = (char *)malloc(sizeof(str)+1);
  strcpy(yylval.Id, str); BEGIN(INITIAL); return STRINGONEQOUTED;
}
		
\/\*  BEGIN(MULTILINE_COMMENT);

<MULTILINE_COMMENT>[^*]* 
<MULTILINE_COMMENT>"*"+[^*/]* 
<MULTILINE_COMMENT>"*"+"/"  {printf("Multi-Line Comment\n");BEGIN(INITIAL);}


\/\/ {printf("One Line Comment\n");}

#!	{ printf("Hashbang Comment");}
			
%%

char octalToDecimal(char* octalValue){
  char returnValue;
  int octal=0, decimal=0, i=0, j=0;
  if(strncmp(octalValue,"\\",1)==0)
      for(i=0; i<4; i++)
          octalValue[i]=octalValue[i+1];
  octalValue[3]=0;
  octal = atoi(octalValue);
        
  while(octal!=0){
      decimal =  decimal +(octal % 10)* pow(8, j++);
      octal = octal / 10;
  }
  returnValue = (char)decimal;

  return returnValue;
}
