#pragma once

#include "tree.h"

inline struct stmt_list_struct* root;
inline int _variableCounter = 1;
void yyerror(const char* s);
int yylex(void);
void decorate_AST(struct stmt_list_struct* _stmtlist);
void decorate_stmt(struct stmt_struct* _stmt);
void decorate_expr(struct expr_struct* _expr);
void printTable();
void decorate_AST(struct stmt_list_struct* root);
void write_tree(FILE* _filename);
void write_stmt_list(struct stmt_list_struct* _stmtList,
    char* _parentPath,
    FILE* _filename);
void write_elseif_stmt_list(struct elseif_stmt_list_struct* _stmtList,
    char* _parentPath,
    FILE* _filename);

void write_stmt(struct stmt_struct* _stmt,
    char* _parentPath,
    FILE* _filename);

void write_expr(struct expr_struct* _expr,
    char* _parentPath,
    FILE* _filename);
void write_expr_list(struct expr_list_struct* _expr,
    char* _parentPath,
    FILE* _filename);
void write_case_stmt_list(struct case_stmt_list_struct* _stmtList,
    char* _parentPath,
    FILE* _filename);
void createLabel(int _variableNum,
    const char* _variableId,
    char* result);
void write_binary_expr(struct expr_struct* _expr,
    const char* _sign,
    const char* _parentPath,
    FILE* _filename);
void write_unary_expr(struct expr_struct* _expr,
    const char* _sign,
    const char* _parentPath,
    FILE* _filename);

