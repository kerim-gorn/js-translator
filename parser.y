%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
// #include <conio.h>
#include <string.h>
%}

%start
%token <Int> DIGIT
%token <Float> FLOAT_DIGIT
%token <Id> ID
%token <Id> SINGLE_QUOTES_STRING
%token <Id> DOUBLE_QUOTES_STRING

%%