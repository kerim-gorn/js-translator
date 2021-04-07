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
%token SEMI_COLON
%token ADD_ASSIGN_OP
%token SUB_ASSIGN_OP
%token MULT_ASSIGN_OP
%token DIV_ASSIGN_OP
%token REM_ASSIGN_OP
%token EXP_ASSIGN_OP
%token LSHIFT_ASSIGN_OP
%token RSHIFT_ASSIGN_OP
%token UNSIGNED_RSHIFT_ASSIGN_OP
%token BIT_AND_ASSIGN_OP
%token BIT_XOR_ASSIGN_OP
%token BIT_OR_ASSIGN_OP
%token LOG_AND_ASSIGN_OP
%token LOG_OR_ASSIGN_OP
%token EQUAL_OP
%token NOT_EQUAL_OP
%token STRICT_EQUAL_OP
%token STRICT_NOT_EQUAL_OP
%token GREATER_OR_EQUAL_OP
%token LESS_OR_EQUAL_OP
%token ARITH_INCR_OP
%token ARITH_DECR_OP
%token ARITH_EXP_OP
%token LEFT_SHIFT_OP
%token RIGHT_SHIFT_OP
%token UNSIGNED_RIGHT_SHIFT_OP
%token LOG_AND_OP
%token LOG_OR_OP
%token LOG_NOT_OP
%token BREAK_KW
%token CASE_KW
%token CATCH_KW
%token CLASS_KW
%token CONST_KW
%token CONTINUE_KW
%token DEBUGGER_KW
%token DEFAULT_KW
%token DELETE_KW
%token DO_KW
%token ELSE_KW
%token EXPORT_KW
%token FALSE_KW
%token FINALLY_KW
%token FOR_KW
%token FUNCTION_KW
%token IF_KW
%token IMPLEMENTS_KW
%token IMPORT_KW
%token IN_KW
%token INSTANCEOF_KW
%token INTERFACE_KW
%token LET_KW
%token NEW_KW
%token PACKAGE_KW
%token PUBLIC_KW
%token PRIVATE_KW
%token PROTECTED_KW
%token RETURN_KW
%token SUPER_KW
%token STATIC_KW
%token SWITCH_KW
%token THIS_KW
%token THROW_KW
%token TRUE_KW
%token TRY_KW
%token TYPEOF_KW
%token VAR_KW
%token VOID_KW
%token WHILE_KW
%token WITH_KW
%token YIELD_KW




%%