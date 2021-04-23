/* A Bison parser, made by GNU Bison 3.7.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DIGIT = 258,                   /* DIGIT  */
    FLOAT_DIGIT = 259,             /* FLOAT_DIGIT  */
    ID = 260,                      /* ID  */
    STRINGONEQOUTED = 261,         /* STRINGONEQOUTED  */
    STRINGDOUBLEQUOTED = 262,      /* STRINGDOUBLEQUOTED  */
    EQUAL = 263,                   /* EQUAL  */
    STRICT_EQUAL = 264,            /* STRICT_EQUAL  */
    NOT_EQUAL = 265,               /* NOT_EQUAL  */
    BIGGER_EQUAL = 266,            /* BIGGER_EQUAL  */
    SMALLER_EQUAL = 267,           /* SMALLER_EQUAL  */
    ASSIGNMENT = 268,              /* ASSIGNMENT  */
    POW = 269,                     /* "**"  */
    OR = 270,                      /* OR  */
    NOT = 271,                     /* NOT  */
    AND = 272,                     /* AND  */
    IF = 273,                      /* IF  */
    ELSE = 274,                    /* ELSE  */
    ELSEIF = 275,                  /* ELSEIF  */
    FOR = 276,                     /* FOR  */
    WHILE = 277,                   /* WHILE  */
    DO = 278,                      /* DO  */
    SWITCH = 279,                  /* SWITCH  */
    CASE = 280,                    /* CASE  */
    BREAK = 281,                   /* BREAK  */
    DEFAULT = 282,                 /* DEFAULT  */
    OF = 283,                      /* OF  */
    INPUT = 284,                   /* INPUT  */
    OUTPUT = 285,                  /* OUTPUT  */
    SEMICOLON = 286,               /* SEMICOLON  */
    NEWLINE = 287,                 /* NEWLINE  */
    LET = 288,                     /* LET  */
    VAR = 289,                     /* VAR  */
    CONST = 290,                   /* CONST  */
    FINAL = 291,                   /* FINAL  */
    UMINUS = 292,                  /* UMINUS  */
    UPLUS = 293                    /* UPLUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "parser.y"

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

#line 122 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
