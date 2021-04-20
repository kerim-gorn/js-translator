
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DIGIT = 258,
     FLOAT_DIGIT = 259,
     ID = 260,
     STRINGONEQOUTED = 261,
     STRINGDOUBLEQUOTED = 262,
     EQUAL = 263,
     STRICT_EQUAL = 264,
     NOT_EQUAL = 265,
     BIGGER_EQUAL = 266,
     SMALLER_EQUAL = 267,
     ASSIGNMENT = 268,
     POW = 269,
     OR = 270,
     NOT = 271,
     AND = 272,
     IF = 273,
     ELSE = 274,
     ELSEIF = 275,
     FOR = 276,
     WHILE = 277,
     DO = 278,
     SWITCH = 279,
     CASE = 280,
     BREAK = 281,
     DEFAULT = 282,
     OF = 283,
     CONSOLE_IN = 284,
     CONSOLE_OUT = 285,
     SEMICOLON = 286,
     NEWLINE = 287,
     LET = 288,
     VAR = 289,
     CONST = 290,
     FINAL = 291,
     UPLUS = 292,
     UMINUS = 293
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 11 "parser.y"

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



/* Line 1676 of yacc.c  */
#line 112 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


