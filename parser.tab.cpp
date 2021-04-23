/* A Bison parser, made by GNU Bison 3.7.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>
#include "semantic.h"

extern FILE* yyin;

#line 82 "parser.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DIGIT = 3,                      /* DIGIT  */
  YYSYMBOL_FLOAT_DIGIT = 4,                /* FLOAT_DIGIT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_STRINGONEQOUTED = 6,            /* STRINGONEQOUTED  */
  YYSYMBOL_STRINGDOUBLEQUOTED = 7,         /* STRINGDOUBLEQUOTED  */
  YYSYMBOL_EQUAL = 8,                      /* EQUAL  */
  YYSYMBOL_STRICT_EQUAL = 9,               /* STRICT_EQUAL  */
  YYSYMBOL_NOT_EQUAL = 10,                 /* NOT_EQUAL  */
  YYSYMBOL_BIGGER_EQUAL = 11,              /* BIGGER_EQUAL  */
  YYSYMBOL_SMALLER_EQUAL = 12,             /* SMALLER_EQUAL  */
  YYSYMBOL_ASSIGNMENT = 13,                /* ASSIGNMENT  */
  YYSYMBOL_POW = 14,                       /* "**"  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_NOT = 16,                       /* NOT  */
  YYSYMBOL_AND = 17,                       /* AND  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_ELSEIF = 20,                    /* ELSEIF  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_WHILE = 22,                     /* WHILE  */
  YYSYMBOL_DO = 23,                        /* DO  */
  YYSYMBOL_SWITCH = 24,                    /* SWITCH  */
  YYSYMBOL_CASE = 25,                      /* CASE  */
  YYSYMBOL_BREAK = 26,                     /* BREAK  */
  YYSYMBOL_DEFAULT = 27,                   /* DEFAULT  */
  YYSYMBOL_OF = 28,                        /* OF  */
  YYSYMBOL_INPUT = 29,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 30,                    /* OUTPUT  */
  YYSYMBOL_SEMICOLON = 31,                 /* SEMICOLON  */
  YYSYMBOL_NEWLINE = 32,                   /* NEWLINE  */
  YYSYMBOL_LET = 33,                       /* LET  */
  YYSYMBOL_VAR = 34,                       /* VAR  */
  YYSYMBOL_CONST = 35,                     /* CONST  */
  YYSYMBOL_FINAL = 36,                     /* FINAL  */
  YYSYMBOL_37_ = 37,                       /* '>'  */
  YYSYMBOL_38_ = 38,                       /* '<'  */
  YYSYMBOL_39_ = 39,                       /* '+'  */
  YYSYMBOL_40_ = 40,                       /* '-'  */
  YYSYMBOL_41_ = 41,                       /* '*'  */
  YYSYMBOL_42_ = 42,                       /* '/'  */
  YYSYMBOL_43_ = 43,                       /* '%'  */
  YYSYMBOL_UMINUS = 44,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 45,                     /* UPLUS  */
  YYSYMBOL_46_ = 46,                       /* '['  */
  YYSYMBOL_47_ = 47,                       /* ']'  */
  YYSYMBOL_48_ = 48,                       /* ')'  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* '{'  */
  YYSYMBOL_51_ = 51,                       /* '}'  */
  YYSYMBOL_52_ = 52,                       /* ':'  */
  YYSYMBOL_53_ = 53,                       /* ','  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_exp = 56,                       /* exp  */
  YYSYMBOL_stmt = 57,                      /* stmt  */
  YYSYMBOL_stmt_list = 58,                 /* stmt_list  */
  YYSYMBOL_type = 59,                      /* type  */
  YYSYMBOL_if_stmt = 60,                   /* if_stmt  */
  YYSYMBOL_elseif_stmt_list = 61,          /* elseif_stmt_list  */
  YYSYMBOL_elseif_stmt = 62,               /* elseif_stmt  */
  YYSYMBOL_for_stmt = 63,                  /* for_stmt  */
  YYSYMBOL_while_stmt = 64,                /* while_stmt  */
  YYSYMBOL_do_while_stmt = 65,             /* do_while_stmt  */
  YYSYMBOL_switch_stmt = 66,               /* switch_stmt  */
  YYSYMBOL_case_stmt_list = 67,            /* case_stmt_list  */
  YYSYMBOL_case_stmt = 68,                 /* case_stmt  */
  YYSYMBOL_default_stmt = 69,              /* default_stmt  */
  YYSYMBOL_newline_seq = 70,               /* newline_seq  */
  YYSYMBOL_newline_seq_opt = 71,           /* newline_seq_opt  */
  YYSYMBOL_for_of = 72,                    /* for_of  */
  YYSYMBOL_array_handling = 73,            /* array_handling  */
  YYSYMBOL_expr_list = 74,                 /* expr_list  */
  YYSYMBOL_input = 75,                     /* input  */
  YYSYMBOL_output = 76                     /* output  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  53
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   797

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    43,     2,     2,
      49,    48,    41,    39,    53,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,     2,
      38,     2,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    44,    45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    96,    96,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   143,   144,   146,   146,   146,
     147,   149,   151,   153,   156,   157,   159,   161,   163,   165,
     167,   169,   172,   173,   175,   177,   179,   181,   182,   182,
     183,   185,   187,   188,   190,   191,   193,   194
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DIGIT", "FLOAT_DIGIT",
  "ID", "STRINGONEQOUTED", "STRINGDOUBLEQUOTED", "EQUAL", "STRICT_EQUAL",
  "NOT_EQUAL", "BIGGER_EQUAL", "SMALLER_EQUAL", "ASSIGNMENT", "\"**\"",
  "OR", "NOT", "AND", "IF", "ELSE", "ELSEIF", "FOR", "WHILE", "DO",
  "SWITCH", "CASE", "BREAK", "DEFAULT", "OF", "INPUT", "OUTPUT",
  "SEMICOLON", "NEWLINE", "LET", "VAR", "CONST", "FINAL", "'>'", "'<'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "UPLUS", "'['", "']'",
  "')'", "'('", "'{'", "'}'", "':'", "','", "$accept", "program", "exp",
  "stmt", "stmt_list", "type", "if_stmt", "elseif_stmt_list",
  "elseif_stmt", "for_stmt", "while_stmt", "do_while_stmt", "switch_stmt",
  "case_stmt_list", "case_stmt", "default_stmt", "newline_seq",
  "newline_seq_opt", "for_of", "array_handling", "expr_list", "input",
  "output", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    62,    60,    43,
      45,    42,    47,    37,   292,   293,    91,    93,    41,    40,
     123,   125,    58,    44
};
#endif

#define YYPACT_NINF (-48)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     240,   -48,   -48,   -48,   -48,   -48,   278,   -48,   -42,   -34,
     240,   -30,    13,   -21,   -16,   -48,   -48,   -48,   -48,   278,
     278,   278,   -48,    71,   614,   -48,   240,    67,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   751,   -31,   278,
     278,    51,   278,   -48,   -48,   -48,   278,   278,    44,    34,
      34,   336,   202,   -48,   278,   278,   278,   278,   278,    20,
     278,   278,   278,   -48,   278,   278,   278,   278,   278,   278,
     278,   278,   -48,   -48,   -48,   278,   -48,   278,   653,   348,
      29,   389,    44,    44,   401,   442,   -48,   164,     0,     0,
       0,    87,    87,   278,   741,    34,   751,   751,    44,    87,
      87,    15,    15,   -11,   -11,   -11,   601,   454,   278,   278,
     240,   278,    41,    31,    33,   -48,   702,   -43,   -48,   240,
     495,   692,   -48,   507,   -48,   -48,   -48,   -48,   -48,    44,
      48,   278,     2,   240,   278,    50,   -12,    44,    44,    72,
     702,   240,    59,    32,   -48,   -48,   548,   -48,   278,   -19,
     -48,   -48,   -48,   278,   240,   -48,   240,    44,   291,    58,
     -48,   -48,    62,   560,   -48,   -48,   -48,   -48,    44,   -48,
     -48,   202,   202,    44,   202,   240,   240,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     4,     6,     7,     8,     0,    68,     0,     0,
       0,     0,     0,     0,     0,    68,    47,    48,    49,     0,
       0,     0,    68,     0,     0,    45,     2,     0,    37,    38,
      39,    40,    41,    42,    36,    43,    44,    27,     0,     0,
       0,     0,     0,    68,    68,    32,     0,     0,    30,    28,
      29,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    46,     5,     0,    69,     0,     0,     0,
       0,     0,    31,    67,     0,     0,    10,     0,    16,    17,
      18,    21,    22,     0,    23,    24,    25,    26,    33,    19,
      20,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    72,     0,     9,     0,
       0,     0,    58,     0,    68,    68,    75,    68,    77,    35,
       0,     0,    50,     0,     0,     0,     0,    74,    76,     0,
      73,     0,     0,    52,    54,    70,     0,    68,     0,     0,
      62,    71,    51,     0,     0,    55,     0,    59,     0,     0,
      68,    63,     0,     0,    53,    57,    68,    68,    60,    68,
      68,    64,     0,    61,     0,    65,    66,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,    28,   -10,   -47,   -48,   -48,   -48,   -28,   -48,
     -48,   -48,   -48,   -48,   -33,   -48,    -7,   -13,   -48,   -48,
     -48,   -48,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    25,    26,    27,    28,   143,   144,    29,
      30,    31,    32,   149,   150,   162,    45,    38,    33,    34,
     117,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      41,    76,    48,    60,   130,    87,   148,    39,   159,    52,
     131,    57,    58,   148,    60,    40,    73,    72,    77,    42,
      76,   141,   142,     1,     2,     3,     4,     5,    46,    60,
      82,    83,   160,    47,    37,    71,     6,    64,    65,    66,
      67,    68,    69,    70,    43,    44,    71,    49,    50,    51,
      98,   154,   142,    16,    17,    18,    68,    69,    70,    19,
      20,    71,   125,    44,   127,    44,    93,    78,    79,    21,
      81,    53,    74,    80,    84,    85,    76,    73,   111,   139,
      71,   147,    88,    89,    90,    91,    92,    94,    95,    96,
      97,   124,    99,   100,   101,   102,   103,   104,   105,   106,
     122,    60,   129,    94,   151,   107,   126,   128,   153,   132,
     167,   136,   137,   169,   138,   155,   161,     0,     0,     0,
       0,   116,     0,   145,   175,   176,    66,    67,    68,    69,
      70,   152,     0,    71,   157,     0,   120,   121,     0,   123,
       0,     0,     0,     0,   164,     0,   165,   168,     0,     0,
       0,     0,     0,   171,   172,     0,   173,   174,     0,   140,
       0,     0,   146,     0,   177,    73,    73,     1,     2,     3,
       4,     5,     0,     0,     0,     0,   158,     0,     0,     0,
       6,   163,     7,     0,     0,     8,     9,    10,    11,     0,
      12,     0,     0,    13,    14,    15,     0,    16,    17,    18,
       0,     0,     0,    19,    20,     1,     2,     3,     4,     5,
       0,     0,     0,    21,    22,   115,     0,     0,     6,     0,
       7,     0,     0,     8,     9,    10,    11,     0,    12,     0,
       0,    13,    14,    15,    76,    16,    17,    18,     0,     0,
       0,    19,    20,     1,     2,     3,     4,     5,     0,     0,
       0,    21,    22,     0,     0,     0,     6,     0,     7,     0,
       0,     8,     9,    10,    11,     0,    12,     0,     0,    13,
      14,    15,     0,    16,    17,    18,     0,     0,     0,    19,
      20,     1,     2,     3,     4,     5,     0,     0,     0,    21,
      22,     0,     0,     0,     6,     0,     0,     0,     0,    54,
      55,    56,    57,    58,    75,    60,    61,     0,    62,     0,
       0,    16,    17,    18,     0,     0,     0,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,    21,    64,    65,
      66,    67,    68,    69,    70,     0,     0,    71,     0,     0,
       0,     0,     0,   166,    54,    55,    56,    57,    58,    75,
      60,    61,     0,    62,     0,     0,    54,    55,    56,    57,
      58,    75,    60,    61,     0,    62,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,    67,    68,    69,    70,
       0,     0,    71,     0,    86,    64,    65,    66,    67,    68,
      69,    70,     0,     0,    71,     0,   110,    54,    55,    56,
      57,    58,    75,    60,    61,     0,    62,     0,     0,    54,
      55,    56,    57,    58,    75,    60,    61,     0,    62,     0,
       0,     0,     0,     0,     0,     0,    64,    65,    66,    67,
      68,    69,    70,     0,     0,    71,     0,   112,    64,    65,
      66,    67,    68,    69,    70,     0,     0,    71,     0,   113,
      54,    55,    56,    57,    58,    75,    60,    61,     0,    62,
       0,     0,    54,    55,    56,    57,    58,    75,    60,    61,
       0,    62,     0,     0,     0,     0,     0,     0,     0,    64,
      65,    66,    67,    68,    69,    70,     0,     0,    71,     0,
     114,    64,    65,    66,    67,    68,    69,    70,     0,     0,
      71,     0,   119,    54,    55,    56,    57,    58,    75,    60,
      61,     0,    62,     0,     0,    54,    55,    56,    57,    58,
      75,    60,    61,     0,    62,     0,     0,     0,     0,     0,
       0,     0,    64,    65,    66,    67,    68,    69,    70,     0,
       0,    71,     0,   133,    64,    65,    66,    67,    68,    69,
      70,     0,     0,    71,     0,   135,    54,    55,    56,    57,
      58,    75,    60,    61,     0,    62,     0,     0,    54,    55,
      56,    57,    58,    75,    60,    61,     0,    62,     0,     0,
       0,     0,     0,     0,     0,    64,    65,    66,    67,    68,
      69,    70,     0,     0,    71,     0,   156,    64,    65,    66,
      67,    68,    69,    70,     0,     0,    71,     0,   170,    54,
      55,    56,    57,    58,    75,    60,    61,     0,    62,     0,
       0,     0,    54,    55,    56,    57,    58,    59,    60,    61,
       0,    62,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,    68,    69,    70,    63,    44,    71,   118,     0,
       0,    64,    65,    66,    67,    68,    69,    70,     0,     0,
      71,    54,    55,    56,    57,    58,    75,    60,    61,     0,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,     0,   109,     0,     0,     0,     0,     0,
      64,    65,    66,    67,    68,    69,    70,     0,     0,    71,
      54,    55,    56,    57,    58,    75,    60,    61,     0,    62,
      54,    55,    56,    57,    58,    75,    60,    61,     0,    62,
       0,     0,     0,   134,     0,     0,     0,     0,     0,    64,
      65,    66,    67,    68,    69,    70,     0,     0,    71,    64,
      65,    66,    67,    68,    69,    70,     0,     0,    71,    54,
      55,    56,    57,    58,     0,    60,    61,     0,    62,    54,
      55,    56,    57,    58,     0,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,    68,    69,    70,     0,     0,    71,    64,    65,
      66,    67,    68,    69,    70,     0,     0,    71
};

static const yytype_int16 yycheck[] =
{
      10,    32,    15,    14,    47,    52,    25,    49,    27,    22,
      53,    11,    12,    25,    14,    49,    26,    24,    49,    49,
      32,    19,    20,     3,     4,     5,     6,     7,    49,    14,
      43,    44,    51,    49,     6,    46,    16,    37,    38,    39,
      40,    41,    42,    43,    31,    32,    46,    19,    20,    21,
      63,    19,    20,    33,    34,    35,    41,    42,    43,    39,
      40,    46,    31,    32,    31,    32,    46,    39,    40,    49,
      42,     0,     5,    22,    46,    47,    32,    87,    49,    31,
      46,    31,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    50,    64,    65,    66,    67,    68,    69,    70,    71,
     110,    14,   115,    75,    32,    77,   113,   114,    49,   119,
      52,   124,   125,    51,   127,   143,   149,    -1,    -1,    -1,
      -1,    93,    -1,   133,   171,   172,    39,    40,    41,    42,
      43,   141,    -1,    46,   147,    -1,   108,   109,    -1,   111,
      -1,    -1,    -1,    -1,   154,    -1,   156,   160,    -1,    -1,
      -1,    -1,    -1,   166,   167,    -1,   169,   170,    -1,   131,
      -1,    -1,   134,    -1,   174,   175,   176,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      16,   153,    18,    -1,    -1,    21,    22,    23,    24,    -1,
      26,    -1,    -1,    29,    30,    31,    -1,    33,    34,    35,
      -1,    -1,    -1,    39,    40,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    49,    50,    51,    -1,    -1,    16,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    -1,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    16,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    -1,    26,    -1,    -1,    29,
      30,    31,    -1,    33,    34,    35,    -1,    -1,    -1,    39,
      40,     3,     4,     5,     6,     7,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    -1,
      -1,    33,    34,    35,    -1,    -1,    -1,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    52,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    48,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    48,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    -1,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    48,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    -1,    48,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      -1,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      48,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    48,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    48,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    48,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    -1,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    48,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    48,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    -1,
      -1,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    31,    32,    46,    47,    -1,
      -1,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,     8,
       9,    10,    11,    12,    -1,    14,    15,    -1,    17,     8,
       9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    16,    18,    21,    22,
      23,    24,    26,    29,    30,    31,    33,    34,    35,    39,
      40,    49,    50,    55,    56,    57,    58,    59,    60,    63,
      64,    65,    66,    72,    73,    75,    76,    56,    71,    49,
      49,    57,    49,    31,    32,    70,    49,    49,    71,    56,
      56,    56,    71,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    17,    31,    37,    38,    39,    40,    41,    42,
      43,    46,    70,    57,     5,    13,    32,    49,    56,    56,
      22,    56,    71,    71,    56,    56,    48,    58,    56,    56,
      56,    56,    56,    46,    56,    56,    56,    56,    71,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    28,    31,
      48,    49,    48,    48,    48,    51,    56,    74,    47,    48,
      56,    56,    57,    56,    50,    31,    70,    31,    70,    71,
      47,    53,    57,    48,    31,    48,    71,    71,    71,    31,
      56,    19,    20,    61,    62,    57,    56,    31,    25,    67,
      68,    32,    57,    49,    19,    62,    48,    71,    56,    27,
      51,    68,    69,    56,    57,    57,    52,    52,    71,    51,
      48,    71,    71,    71,    71,    58,    58,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    59,    59,    59,
      60,    60,    60,    60,    61,    61,    62,    63,    64,    65,
      66,    66,    67,    67,    68,    68,    69,    70,    71,    71,
      72,    73,    74,    74,    75,    75,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     1,     1,     1,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     2,     3,     2,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       6,     8,     7,     9,     1,     2,     6,     9,     5,     8,
       9,    10,     1,     2,     4,     5,     4,     2,     0,     2,
       7,     7,     1,     3,     6,     5,     6,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: stmt_list  */
#line 96 "parser.y"
                   { (yyval.stmt_list_value) = root = (yyvsp[0].stmt_list_value);}
#line 1650 "parser.tab.cpp"
    break;

  case 3: /* exp: DIGIT  */
#line 98 "parser.y"
                                                        {printf("DIGIT is printed\n"); (yyval.expr_value) = createDigitExpr((yyvsp[0].Int_val));}
#line 1656 "parser.tab.cpp"
    break;

  case 4: /* exp: FLOAT_DIGIT  */
#line 99 "parser.y"
                                                        {printf("FLOAT_DIGIT is printed\n");(yyval.expr_value) = createFloatExpr((yyvsp[0].Float));}
#line 1662 "parser.tab.cpp"
    break;

  case 5: /* exp: type ID  */
#line 100 "parser.y"
                                                        {printf("ID is printed\n");(yyval.expr_value) = createVariableExpr((yyvsp[0].Id));}
#line 1668 "parser.tab.cpp"
    break;

  case 6: /* exp: ID  */
#line 101 "parser.y"
                                                            {printf("ID is printed\n");(yyval.expr_value) = createVariableExpr((yyvsp[0].Id));}
#line 1674 "parser.tab.cpp"
    break;

  case 7: /* exp: STRINGONEQOUTED  */
#line 102 "parser.y"
                                                {printf("STRINGONEQOUTED is printed\n");(yyval.expr_value) = createVariableExpr((yyvsp[0].Id));}
#line 1680 "parser.tab.cpp"
    break;

  case 8: /* exp: STRINGDOUBLEQUOTED  */
#line 103 "parser.y"
                                                {printf("STRINGDOUBLEQUOTED is printed\n");(yyval.expr_value) = createVariableExpr((yyvsp[0].Id));}
#line 1686 "parser.tab.cpp"
    break;

  case 9: /* exp: exp '[' exp ']'  */
#line 104 "parser.y"
                                                        {printf("exp \'[\' exp \']\' worked\n"); (yyval.expr_value) = createBinaryOpeartionExpr(array_element_access, (yyvsp[-3].expr_value), (yyvsp[-1].expr_value));}
#line 1692 "parser.tab.cpp"
    break;

  case 10: /* exp: '(' exp ')'  */
#line 105 "parser.y"
                                                        {printf("\'(\' exp \')\' worked\n"); (yyval.expr_value) = (yyvsp[-1].expr_value);}
#line 1698 "parser.tab.cpp"
    break;

  case 11: /* exp: exp '+' exp  */
#line 106 "parser.y"
                                                        {printf("exp + exp  worked\n");(yyval.expr_value) = createBinaryOpeartionExpr(Plus, (yyvsp[-2].expr_value) , (yyvsp[0].expr_value));}
#line 1704 "parser.tab.cpp"
    break;

  case 12: /* exp: exp '-' exp  */
#line 107 "parser.y"
                                                        {printf("exp - exp  worked\n");(yyval.expr_value) = createBinaryOpeartionExpr(Minus, (yyvsp[-2].expr_value) , (yyvsp[0].expr_value));}
#line 1710 "parser.tab.cpp"
    break;

  case 13: /* exp: exp '*' exp  */
#line 108 "parser.y"
                                                        {printf("exp * exp  worked\n");(yyval.expr_value) = createBinaryOpeartionExpr(Mul, (yyvsp[-2].expr_value) , (yyvsp[0].expr_value));}
#line 1716 "parser.tab.cpp"
    break;

  case 14: /* exp: exp '/' exp  */
#line 109 "parser.y"
                                                        {printf("exp / exp  worked\n");(yyval.expr_value) = createBinaryOpeartionExpr(Div, (yyvsp[-2].expr_value) , (yyvsp[0].expr_value));}
#line 1722 "parser.tab.cpp"
    break;

  case 15: /* exp: exp '%' exp  */
#line 110 "parser.y"
                                                        {printf("exp Remi exp  worked\n");(yyval.expr_value) = createBinaryOpeartionExpr(Remi, (yyvsp[-2].expr_value) , (yyvsp[0].expr_value));}
#line 1728 "parser.tab.cpp"
    break;

  case 16: /* exp: exp EQUAL exp  */
#line 111 "parser.y"
                                                        {printf("exp EQUAL exp  worked\n");(yyval.expr_value) = createBinaryOpeartionExpr(EQ, (yyvsp[-2].expr_value) , (yyvsp[0].expr_value));}
#line 1734 "parser.tab.cpp"
    break;

  case 17: /* exp: exp STRICT_EQUAL exp  */
#line 112 "parser.y"
                                                {printf("exp STRICT_EQUAL exp  worked\n");(yyval.expr_value) = createBinaryOpeartionExpr(SEQ, (yyvsp[-2].expr_value) , (yyvsp[0].expr_value));}
#line 1740 "parser.tab.cpp"
    break;

  case 18: /* exp: exp NOT_EQUAL exp  */
#line 113 "parser.y"
                                                {printf("exp NOT_EQUAL exp  worked\n");(yyval.expr_value) = createBinaryOpeartionExpr(NEQ, (yyvsp[-2].expr_value) , (yyvsp[0].expr_value));}
#line 1746 "parser.tab.cpp"
    break;

  case 19: /* exp: exp '>' exp  */
#line 114 "parser.y"
                                                        {printf("exp > exp  worked\n");(yyval.expr_value) = createBinaryOpeartionExpr(GR, (yyvsp[-2].expr_value) , (yyvsp[0].expr_value));}
#line 1752 "parser.tab.cpp"
    break;

  case 20: /* exp: exp '<' exp  */
#line 115 "parser.y"
                                                        {printf("exp < exp  worked\n");(yyval.expr_value) = createBinaryOpeartionExpr(SM, (yyvsp[-2].expr_value) , (yyvsp[0].expr_value));}
#line 1758 "parser.tab.cpp"
    break;

  case 21: /* exp: exp BIGGER_EQUAL exp  */
#line 116 "parser.y"
                                                {printf("exp >= exp  worked\n");(yyval.expr_value) = createBinaryOpeartionExpr(GREQ, (yyvsp[-2].expr_value) , (yyvsp[0].expr_value));}
#line 1764 "parser.tab.cpp"
    break;

  case 22: /* exp: exp SMALLER_EQUAL exp  */
#line 117 "parser.y"
                                                {printf("exp <= exp  worked\n");(yyval.expr_value) = createBinaryOpeartionExpr(SMEQ, (yyvsp[-2].expr_value) , (yyvsp[0].expr_value));}
#line 1770 "parser.tab.cpp"
    break;

  case 23: /* exp: exp ASSIGNMENT exp  */
#line 118 "parser.y"
                                                {printf("exp = exp  worked\n");(yyval.expr_value) = createBinaryOpeartionExpr(Assign, (yyvsp[-2].expr_value) , (yyvsp[0].expr_value));}
#line 1776 "parser.tab.cpp"
    break;

  case 24: /* exp: exp "**" exp  */
#line 119 "parser.y"
                                                        {printf("exp POW exp  worked\n");(yyval.expr_value) = createBinaryOpeartionExpr(Pow, (yyvsp[-2].expr_value) , (yyvsp[0].expr_value));}
#line 1782 "parser.tab.cpp"
    break;

  case 25: /* exp: exp OR exp  */
#line 120 "parser.y"
                                                        {printf("exp OR exp  worked\n");(yyval.expr_value) = createBinaryOpeartionExpr(Or, (yyvsp[-2].expr_value) , (yyvsp[0].expr_value));}
#line 1788 "parser.tab.cpp"
    break;

  case 26: /* exp: exp AND exp  */
#line 121 "parser.y"
                                                        {printf("exp AND exp  worked\n");(yyval.expr_value) = createBinaryOpeartionExpr(And, (yyvsp[-2].expr_value) , (yyvsp[0].expr_value));}
#line 1794 "parser.tab.cpp"
    break;

  case 27: /* exp: NOT exp  */
#line 122 "parser.y"
                                                                {printf("NOT exp  worked\n");(yyval.expr_value) = createUnaryOpeartionExpr(Not, (yyvsp[0].expr_value) );}
#line 1800 "parser.tab.cpp"
    break;

  case 28: /* exp: '+' exp  */
#line 123 "parser.y"
                                                {printf(" + exp  worked\n");(yyval.expr_value) = createUnaryOpeartionExpr(Uplu, (yyvsp[0].expr_value) );}
#line 1806 "parser.tab.cpp"
    break;

  case 29: /* exp: '-' exp  */
#line 124 "parser.y"
                                        {printf(" - exp  worked\n");(yyval.expr_value) = createUnaryOpeartionExpr(Umin, (yyvsp[0].expr_value) );}
#line 1812 "parser.tab.cpp"
    break;

  case 30: /* stmt: SEMICOLON newline_seq_opt  */
#line 126 "parser.y"
                                                                                {printf("empty stmt \n"); (yyval.stmt_value)=createStmtNull();}
#line 1818 "parser.tab.cpp"
    break;

  case 31: /* stmt: BREAK SEMICOLON newline_seq_opt  */
#line 127 "parser.y"
                                                                                {printf("create break stmt\n"); (yyval.stmt_value)=createStmtBreak();}
#line 1824 "parser.tab.cpp"
    break;

  case 32: /* stmt: BREAK newline_seq  */
#line 128 "parser.y"
                                                                                                {printf("create break stmt\n"); (yyval.stmt_value)=createStmtBreak();}
#line 1830 "parser.tab.cpp"
    break;

  case 33: /* stmt: exp SEMICOLON newline_seq_opt  */
#line 129 "parser.y"
                                                                {(yyval.stmt_value) = createStmt((yyvsp[-2].expr_value));}
#line 1836 "parser.tab.cpp"
    break;

  case 34: /* stmt: exp newline_seq  */
#line 130 "parser.y"
                                                                                        {(yyval.stmt_value) = createStmt((yyvsp[-1].expr_value));}
#line 1842 "parser.tab.cpp"
    break;

  case 35: /* stmt: '{' newline_seq_opt stmt_list '}' newline_seq_opt  */
#line 131 "parser.y"
                                                                {(yyval.stmt_value) = createBlockStmt((yyvsp[-2].stmt_list_value));}
#line 1848 "parser.tab.cpp"
    break;

  case 36: /* stmt: array_handling  */
#line 132 "parser.y"
                                                                                        {(yyval.stmt_value)= createArray((yyvsp[0].array_handling_value)); }
#line 1854 "parser.tab.cpp"
    break;

  case 37: /* stmt: if_stmt  */
#line 133 "parser.y"
                                                                                                        {(yyval.stmt_value)= FillIfStmt((yyvsp[0].if_stmt_value));}
#line 1860 "parser.tab.cpp"
    break;

  case 38: /* stmt: for_stmt  */
#line 134 "parser.y"
                                                                                                        {(yyval.stmt_value)= FillForStmt((yyvsp[0].for_stmt_value)); }
#line 1866 "parser.tab.cpp"
    break;

  case 39: /* stmt: while_stmt  */
#line 135 "parser.y"
                                                                                                {(yyval.stmt_value)= (yyvsp[0].stmt_value); }
#line 1872 "parser.tab.cpp"
    break;

  case 40: /* stmt: do_while_stmt  */
#line 136 "parser.y"
                                                                                                {(yyval.stmt_value)= (yyvsp[0].stmt_value); }
#line 1878 "parser.tab.cpp"
    break;

  case 41: /* stmt: switch_stmt  */
#line 137 "parser.y"
                                                                                                {printf("fillSwitchStmt worked\n");(yyval.stmt_value)= fillSwitchStmt((yyvsp[0].switch_stmt_value));}
#line 1884 "parser.tab.cpp"
    break;

  case 42: /* stmt: for_of  */
#line 138 "parser.y"
                                                                                                        {(yyval.stmt_value)= fillForOfStmt((yyvsp[0].forOf_stmt_value)); }
#line 1890 "parser.tab.cpp"
    break;

  case 43: /* stmt: input  */
#line 139 "parser.y"
                                                                                        {(yyval.stmt_value)= (yyvsp[0].stmt_value); }
#line 1896 "parser.tab.cpp"
    break;

  case 44: /* stmt: output  */
#line 140 "parser.y"
                                                                                                {(yyval.stmt_value)= (yyvsp[0].stmt_value); }
#line 1902 "parser.tab.cpp"
    break;

  case 45: /* stmt_list: stmt  */
#line 143 "parser.y"
                                                {printf("stmt is created\n");(yyval.stmt_list_value) = createStmtList((yyvsp[0].stmt_value));}
#line 1908 "parser.tab.cpp"
    break;

  case 46: /* stmt_list: stmt_list stmt  */
#line 144 "parser.y"
                                                {printf("addToStmtList is preformed\n");(yyval.stmt_list_value) = addToStmtList((yyvsp[-1].stmt_list_value), (yyvsp[0].stmt_value));}
#line 1914 "parser.tab.cpp"
    break;

  case 50: /* if_stmt: IF newline_seq_opt '(' exp ')' stmt  */
#line 148 "parser.y"
                                {printf("IfStmt is worked\n"); (yyval.if_stmt_value) = createIfStmt((yyvsp[-2].expr_value), (yyvsp[0].stmt_value), NULL);}
#line 1920 "parser.tab.cpp"
    break;

  case 51: /* if_stmt: IF newline_seq_opt '(' exp ')' stmt ELSE stmt  */
#line 150 "parser.y"
                                {printf("IfElseStmt is worked\n"); (yyval.if_stmt_value) = createIfStmt((yyvsp[-4].expr_value), (yyvsp[-2].stmt_value), (yyvsp[0].stmt_value));}
#line 1926 "parser.tab.cpp"
    break;

  case 52: /* if_stmt: IF newline_seq_opt '(' exp ')' stmt elseif_stmt_list  */
#line 152 "parser.y"
                                {printf("If and ElseIf is worked\n"); (yyval.if_stmt_value) = createElseIfStmt((yyvsp[-3].expr_value), (yyvsp[-1].stmt_value), (yyvsp[0].elseif_stmt_list_value),NULL);}
#line 1932 "parser.tab.cpp"
    break;

  case 53: /* if_stmt: IF newline_seq_opt '(' exp ')' stmt elseif_stmt_list ELSE stmt  */
#line 154 "parser.y"
                                {printf("If, ElseIf and Else is worked"); (yyval.if_stmt_value) = createElseIfStmt((yyvsp[-5].expr_value), (yyvsp[-3].stmt_value), (yyvsp[-2].elseif_stmt_list_value), (yyvsp[0].stmt_value));}
#line 1938 "parser.tab.cpp"
    break;

  case 54: /* elseif_stmt_list: elseif_stmt  */
#line 156 "parser.y"
                                                                {(yyval.elseif_stmt_list_value) = createElseIfStmtList((yyvsp[0].elseif_stmt_value));}
#line 1944 "parser.tab.cpp"
    break;

  case 55: /* elseif_stmt_list: elseif_stmt_list elseif_stmt  */
#line 157 "parser.y"
                                                                {(yyval.elseif_stmt_list_value) = addToElseIfStmtList((yyvsp[-1].elseif_stmt_list_value), (yyvsp[0].elseif_stmt_value));}
#line 1950 "parser.tab.cpp"
    break;

  case 56: /* elseif_stmt: ELSEIF '(' exp ')' newline_seq_opt stmt  */
#line 159 "parser.y"
                                                                {(yyval.elseif_stmt_value) = createSimpleElseIfStmt((yyvsp[-3].expr_value),(yyvsp[0].stmt_value));}
#line 1956 "parser.tab.cpp"
    break;

  case 57: /* for_stmt: FOR '(' exp SEMICOLON exp SEMICOLON exp ')' stmt  */
#line 161 "parser.y"
                                                           {(yyval.for_stmt_value) = createForStmt((yyvsp[-6].expr_value), (yyvsp[-4].expr_value), (yyvsp[-2].expr_value), (yyvsp[0].stmt_value));}
#line 1962 "parser.tab.cpp"
    break;

  case 58: /* while_stmt: WHILE '(' exp ')' stmt  */
#line 163 "parser.y"
                                      {(yyval.stmt_value) = createWhileStmt((yyvsp[-2].expr_value), (yyvsp[0].stmt_value));}
#line 1968 "parser.tab.cpp"
    break;

  case 59: /* do_while_stmt: DO stmt WHILE '(' exp ')' SEMICOLON newline_seq_opt  */
#line 165 "parser.y"
                                                                    {(yyval.stmt_value) = createDoWhileStmt((yyvsp[-6].stmt_value), (yyvsp[-3].expr_value));}
#line 1974 "parser.tab.cpp"
    break;

  case 60: /* switch_stmt: SWITCH '(' exp ')' '{' newline_seq_opt case_stmt_list '}' newline_seq_opt  */
#line 168 "parser.y"
                                                                {printf("createSwitchStmt is worked\n"); (yyval.switch_stmt_value) = createSwitchStmt((yyvsp[-6].expr_value), (yyvsp[-2].case_stmt_list_value),NULL); }
#line 1980 "parser.tab.cpp"
    break;

  case 61: /* switch_stmt: SWITCH '(' exp ')' '{' newline_seq_opt case_stmt_list default_stmt '}' newline_seq_opt  */
#line 170 "parser.y"
                                                                {printf("createSwitchStmt is worked\n"); (yyval.switch_stmt_value) = createSwitchStmt((yyvsp[-7].expr_value), (yyvsp[-3].case_stmt_list_value),(yyvsp[-2].default_stmt_value)); }
#line 1986 "parser.tab.cpp"
    break;

  case 62: /* case_stmt_list: case_stmt  */
#line 172 "parser.y"
                                                {printf("createCaseStmtList is worked\n");(yyval.case_stmt_list_value) = createCaseStmtList((yyvsp[0].case_stmt_value));}
#line 1992 "parser.tab.cpp"
    break;

  case 63: /* case_stmt_list: case_stmt_list case_stmt  */
#line 173 "parser.y"
                                                                        {printf("addToCaseStmtList is worked\n");(yyval.case_stmt_list_value) = addToCaseStmtList((yyvsp[-1].case_stmt_list_value), (yyvsp[0].case_stmt_value));}
#line 1998 "parser.tab.cpp"
    break;

  case 64: /* case_stmt: CASE exp ':' newline_seq_opt  */
#line 176 "parser.y"
                                                {printf("newline_seq_opt is worked\n");(yyval.case_stmt_value) = createCaseStmt((yyvsp[-2].expr_value), NULL);}
#line 2004 "parser.tab.cpp"
    break;

  case 65: /* case_stmt: CASE exp ':' newline_seq_opt stmt_list  */
#line 178 "parser.y"
                                                {printf("CASE exp ':' newline_seq_opt stmt_list is worked\n"); (yyval.case_stmt_value) = createCaseStmt((yyvsp[-3].expr_value), (yyvsp[0].stmt_list_value));}
#line 2010 "parser.tab.cpp"
    break;

  case 66: /* default_stmt: DEFAULT ':' newline_seq_opt stmt_list  */
#line 180 "parser.y"
                                                {printf("DEFAULT ':' newline_seq_opt stmt_list stmt_list  is worked\n");(yyval.default_stmt_value) = createDefaultStmt((yyvsp[0].stmt_list_value));}
#line 2016 "parser.tab.cpp"
    break;

  case 70: /* for_of: FOR '(' exp OF exp ')' stmt  */
#line 183 "parser.y"
                                       {(yyval.forOf_stmt_value) = createForOfStmt((yyvsp[-4].expr_value), (yyvsp[-2].expr_value), (yyvsp[0].stmt_value));}
#line 2022 "parser.tab.cpp"
    break;

  case 71: /* array_handling: exp ASSIGNMENT '[' expr_list ']' SEMICOLON NEWLINE  */
#line 185 "parser.y"
                                                                   {(yyval.array_handling_value) = createArrayHandlingStmt((yyvsp[-6].expr_value), (yyvsp[-3].expr_list_value));}
#line 2028 "parser.tab.cpp"
    break;

  case 72: /* expr_list: exp  */
#line 187 "parser.y"
                                                 {printf("expr is created\n");(yyval.expr_list_value) = createExprList((yyvsp[0].expr_value));}
#line 2034 "parser.tab.cpp"
    break;

  case 73: /* expr_list: expr_list ',' exp  */
#line 188 "parser.y"
                                         {printf("addToExpr is preformed\n");(yyval.expr_list_value) = addToExprList((yyvsp[-2].expr_list_value), (yyvsp[0].expr_value));}
#line 2040 "parser.tab.cpp"
    break;

  case 74: /* input: INPUT '(' exp ')' SEMICOLON newline_seq_opt  */
#line 190 "parser.y"
                                                        {(yyval.stmt_value) = createConsoleInStmt((yyvsp[-3].expr_value));}
#line 2046 "parser.tab.cpp"
    break;

  case 75: /* input: INPUT '(' exp ')' newline_seq  */
#line 191 "parser.y"
                                                                                {(yyval.stmt_value) = createConsoleInStmt((yyvsp[-2].expr_value));}
#line 2052 "parser.tab.cpp"
    break;

  case 76: /* output: OUTPUT '(' exp ')' SEMICOLON newline_seq_opt  */
#line 193 "parser.y"
                                                        {(yyval.stmt_value) = createConsoleOutStmt((yyvsp[-3].expr_value));}
#line 2058 "parser.tab.cpp"
    break;

  case 77: /* output: OUTPUT '(' exp ')' newline_seq  */
#line 194 "parser.y"
                                                                                        {(yyval.stmt_value) = createConsoleOutStmt((yyvsp[-2].expr_value));}
#line 2064 "parser.tab.cpp"
    break;


#line 2068 "parser.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 195 "parser.y"


int main(int argc, char *argv[]){

	if(argc>1)
		{	
			yyin = fopen(argv[1], "r");
		}
	yyparse();
	FILE * _filename;
	_filename = fopen(argv[2], "w");
	if(_filename == NULL ) 
		yyerror("Eorror opening file");
	else
		{
		printf("Printing Tree\n");
		write_tree(_filename);
		printf("Tree is printed in output.txt\n");
		}
	
	fclose(_filename);
	
}


