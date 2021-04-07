%option noyywrap
%option never-interactive

%{
	#include <stdio.h>
	#include <conio.h>
%}

DIGIT [0-9]
HEX_DIGIT [0-9A-Fa-f]
OCTAL_DIGIT [0-7]
BINARY_DIGIT [01]


DECIMAL_LITERAL DIGIT+
BINARY_LITERAL 0[bB]{BINARY_DIGIT}+
OCTAL_LITERAL 0[oO]?{OCTAL_DIGIT}+
HEX_LITERAL 0[xX]{HEX_DIGIT}+
EXP_DEC_LITERAL [0-9]+e[0-9]+

VARIABLE_NAME [a-zA-Z\_][a-zA-Z_0-9]*

%x MULTILINE_COMMENT
%x SINGLE_QUOTES_STRING
%x DOUBLE_QUOTES_STRING

%%

%{
	char comment[1000];
	int num;
  int shift;
  char string[1000];
  char tmp[100];
%}

";"     { printf("Found SEMI_COLON.\n"); }
"("     { printf("Found OPEN_BRACKET.\n"); }
")"     { printf("Found CLOSE_BRACKET.\n"); }
"{"     { printf("Found OPEN_CURLY_BRACKET.\n"); }
"}"     { printf("Found CLOSE_CURLY_BRACKET.\n"); }
"["     { printf("Found OPEN_SQUARE_BRACKET.\n"); }
"]"     { printf("Found CLOSE_SQUARE_BRACKET.\n"); }

"="     { printf("Found ASSIGN_OP.\n"); }
"+="    { printf("Found ADD_ASSIGN_OP.\n"); }
"-="    { printf("Found SUB_ASSIGN_OP.\n"); }
"*="    { printf("Found MULT_ASSIGN_OP.\n"); }
"/="    { printf("Found DIV_ASSIGN_OP.\n"); }
"%="    { printf("Found REM_ASSIGN_OP.\n"); }
"**="   { printf("Found EXP_ASSIGN_OP.\n"); }
"<<="   { printf("Found LSHIFT_ASSIGN_OP.\n"); }
">>="   { printf("Found RSHIFT_ASSIGN_OP.\n"); }
">>>="  { printf("Found UNSIGNED_RSHIFT_ASSIGN_OP.\n"); }
"&="    { printf("Found BIT_AND_ASSIGN_OP.\n"); }
"^="    { printf("Found BIT_XOR_ASSIGN_OP.\n"); }
"|="    { printf("Found BIT_OR_ASSIGN_OP.\n"); }
"&&="   { printf("Found LOG_AND_ASSIGN_OP.\n"); } // x && (x = y)
"||="   { printf("Found LOG_OR_ASSIGN_OP.\n"); } // x || (x = y)

"=="    { printf("Found EQUAL_OP.\n"); }
"!="    { printf("Found NOT_EQUAL_OP.\n"); }
"==="   { printf("Found STRICT_EQUAL_OP.\n"); }
"!=="   { printf("Found STRICT_NOT_EQUAL_OP.\n"); }
">"     { printf("Found GREATER_OP.\n"); }
">="    { printf("Found GREATER_OR_EQUAL_OP.\n"); }
"<"     { printf("Found LESS_OP.\n"); }
"<="    { printf("Found LESS_OR_EQUAL_OP.\n"); }

"+"     { printf("Found ARITH_PLUS_OP.\n"); }
"-"     { printf("Found ARITH_NEG_OP.\n"); }
"*"     { printf("Found ARITH_MULT_OP.\n"); }
"/"     { printf("Found ARITH_DIV_OP.\n"); }
"%"     { printf("Found ARITH_REM_OP.\n"); }
"++"    { printf("Found ARITH_INCR_OP.\n"); }
"--"    { printf("Found ARITH_DECR_OP.\n"); }
"**"    { printf("Found ARITH_EXP_OP.\n"); }

"&"     { printf("Found BIT_AND_OP.\n"); }
"|"     { printf("Found BIT_OR_OP.\n"); }
"^"     { printf("Found BIT_XOR_OP.\n"); }
"~"     { printf("Found BIT_NOT_OP.\n"); }
"<<"    { printf("Found LEFT_SHIFT_OP.\n"); }
">>"    { printf("Found RIGHT_SHIFT_OP.\n"); }
">>>"   { printf("Found UNSIGNED_RIGHT_SHIFT_OP.\n"); }

"&&"    { printf("Found LOG_AND_OP.\n"); }
"||"    { printf("Found LOG_OR_OP.\n"); }
"!"     { printf("Found LOG_NOT_OP.\n"); }

break       { printf("Found BREAK_KW.\n"); }
case        { printf("Found CASE_KW.\n"); }
catch       { printf("Found CATCH_KW.\n"); }
class       { printf("Found CLASS_KW.\n"); }
const       { printf("Found CONST_KW.\n"); }
continue    { printf("Found CONTINUE_KW.\n"); }
debugger    { printf("Found DEBUGGER_KW.\n"); }
default     { printf("Found DEFAULT_KW.\n"); }
delete      { printf("Found DELETE_KW.\n"); }
do          { printf("Found DO_KW.\n"); }
else        { printf("Found ELSE_KW.\n"); }
export      { printf("Found EXPORT_KW.\n"); }
extends     { printf("Found EXTENDS_KW.\n"); }
false       { printf("Found FALSE_KW.\n"); }
finally     { printf("Found FINALLY_KW.\n"); }
for         { printf("Found FOR_KW.\n"); }
function    { printf("Found FUNCTION_KW.\n"); }
if          { printf("Found IF_KW.\n"); }
implements  { printf("Found IMPLEMENTS_KW.\n"); }
import      { printf("Found IMPORT_KW.\n"); }
in          { printf("Found IN_KW.\n"); }
instanceof  { printf("Found INSTANCEOF_KW.\n"); }
interface   { printf("Found INTERFACE_KW.\n"); }
let         { printf("Found LET_KW.\n"); }
new         { printf("Found NEW_KW.\n"); }
package     { printf("Found PACKAGE_KW.\n"); }
public      { printf("Found PUBLIC_KW.\n"); }
private     { printf("Found PRIVATE_KW.\n"); }
protected   { printf("Found PROTECTED_KW.\n"); }
return      { printf("Found RETURN_KW.\n"); }
super       { printf("Found SUPER_KW.\n"); }
static      { printf("Found STATIC_KW.\n"); }
switch      { printf("Found SWITCH_KW.\n"); }
this        { printf("Found THIS_KW.\n"); }
throw       { printf("Found THROW_KW.\n"); }
true        { printf("Found TRUE_KW.\n"); }
try         { printf("Found TRY_KW.\n"); }
typeof      { printf("Found TYPEOF_KW.\n"); }
var         { printf("Found VAR_KW.\n"); }
void        { printf("Found VOID_KW.\n"); }
while       { printf("Found WHILE_KW.\n"); }
with        { printf("Found WITH_KW.\n"); }
yield       { printf("Found YIELD_KW.\n"); }

{HEX_LITERAL} { 
  printf("Found HEX_LITERAL: %s.\n", yytext+2);
}

{OCTAL_LITERAL} {
  shift = (yytext[1] == 'o' || yytext[1] == 'O') ? 2: 1;
  printf("Found OCTAL_LITERAL: %s.\n", yytext+shift);
}

{DECIMAL_LITERAL} {
  printf("Found DECIMAL_LITERAL: %s.\n", yytext);
}

{BINARY_LITERAL} { 
  printf("Found BINARY_DIGIT: %s.\n", yytext+2);
}

{VARIABLE_NAME} {
  printf("Found VARIABLE_NAME: %s.\n", yytext);
}

"/*" {
	comment[0] = 0;
	BEGIN(MULTILINE_COMMENT);
}

<MULTILINE_COMMENT>[^*\n]* {
	strcat(comment, yytext);
}

<MULTILINE_COMMENT>\*+[^*/\n]* {
	strcat(comment, yytext);
}

<MULTILINE_COMMENT>\n {
	strcat(comment, yytext);
}

<MULTILINE_COMMENT>\*+\/ {
	strcat(comment, yytext);
  comment[strlen(comment)-2] = 0;
	printf("Found multiline comment:\n%s\n", comment);
	BEGIN(INITIAL);
}

\/\/.* {
	comment[0] = 0;
	printf("Found single line comment: %s\n", yytext + 2);
}

\'  { 
  string[0] = 0; 
  BEGIN(SINGLE_QUOTES_STRING);    
}
\"  {
  string[0] = 0; 
  BEGIN(DOUBLE_QUOTES_STRING);
}
<SINGLE_QUOTES_STRING>[^\\\'\n]+ {
	strcat(string, yytext);
}
<DOUBLE_QUOTES_STRING>[^\\\"\n]+ {
	strcat(string, yytext);
}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\\' {
	strcat(string, "\'");
}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\\" {
	strcat(string, "\"");
}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\n {
	strcat(string, "\n");
}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\r {
	strcat(string, "\r");
}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\v {
	strcat(string, "\v");
}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\t {
	strcat(string, "\t");
}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\b {
	strcat(string, "\b");
}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING>\\f {
	strcat(string, "\f");
}
<SINGLE_QUOTES_STRING,DOUBLE_QUOTES_STRING><<EOF>> {
  printf("ERROR: Unexpected EOF.\n");
}
<SINGLE_QUOTES_STRING>\' {
	printf("Found string literal: %s\n", string);
	BEGIN(INITIAL);
}
<DOUBLE_QUOTES_STRING>\" {
	printf("Found string literal: %s\n", string);
	BEGIN(INITIAL);
}

%%

int main(int argc, char* argv[])
{
	if (argc < 2) 
	{
		printf("Found No file with JS program text");
		return 0;
	}

	yyin = fopen(argv[1], "r");

	yylex();
}