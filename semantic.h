#ifndef SEMANTIC_H
#define SEMANTIC_H

#endif // SEMANTIC_H
#include "data_struct.h"

void decorate_AST(struct stmt_list_struct * _stmtlist);
void decorate_stmt(struct stmt_struct * _stmt);
void decorate_expr(struct expr_struct* _expr);
void printTable();
