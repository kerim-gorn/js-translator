#include "tree.h"
#include "print_tree.h"

struct expr_struct* create_digit_expr(int _num)
{
	auto result = static_cast<expr_struct*>(malloc(sizeof(struct expr_struct)));
	result->type = Int_value;
	result->Num = _num;

	return result;
}


struct expr_struct* create_float_expr(float _float)
{
	auto result = static_cast<expr_struct*>(malloc(sizeof(struct expr_struct)));
	result->type = Float_value;
	result->Float = _float;

	return result;
}

struct expr_struct* create_variable_expr(char* _value)
{
	auto result = static_cast<expr_struct*>(malloc(sizeof(struct expr_struct)));
	result->type = Id;
	result->value = _value;

	return result;
}


struct expr_struct* create_binary_operation_expr(enum exprType _type, struct expr_struct* _left,
                                              struct expr_struct* _right)
{
	auto result = static_cast<expr_struct*>(malloc(sizeof(struct expr_struct)));

	result->type = _type;
	result->left = _left;
	result->right = _right;

	return result;
}

struct expr_struct* create_unary_operation_expr(enum exprType _type, struct expr_struct* _left)
{
	auto result = static_cast<expr_struct*>(malloc(sizeof(struct expr_struct)));

	result->type = _type;
	result->left = _left;

	return result;
}

struct stmt_struct* create_stmt(struct expr_struct* _expr)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = EXPR;
	temp->expr_value = _expr;

	return temp;
}

struct stmt_struct* create_stmt_null()
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = Null;
	temp->expr_value = nullptr;

	return temp;
}

struct stmt_struct* create_stmt_break()
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	auto result = static_cast<expr_struct*>(malloc(sizeof(struct expr_struct)));
	result->type = Id;
	result->value = "break";

	temp->type = Break;
	temp->expr_value = result;

	return temp;
}

struct stmt_struct* create_block_stmt(struct stmt_list_struct* _block)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = BLOCK;
	temp->Block = _block;

	return temp;
}

struct stmt_list_struct* create_stmt_list(struct stmt_struct* _stmt)
{
	auto temp = static_cast<stmt_list_struct*>(malloc(sizeof(struct stmt_list_struct)));

	temp->First = _stmt;
	temp->Next = nullptr;
	return temp;
}

struct stmt_list_struct* add_to_stmt_list(struct stmt_list_struct* _head, struct stmt_struct* _stmt)
{
	auto temp = static_cast<stmt_list_struct*>(malloc(sizeof(struct stmt_list_struct)));

	auto cur = _head;
	while (cur->Next) cur = cur->Next;
	temp->First = _stmt;
	temp->Next = nullptr;
	cur->Next = temp;

	return _head;
}

struct stmt_struct* fill_if_stmt(struct if_stmt_struct* _ifStmtStruct)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = If;
	temp->IfStmt = _ifStmtStruct;

	return temp;
}

struct if_stmt_struct* create_if_stmt(struct expr_struct* _expr, struct stmt_struct* _stmtTrue,
                                    struct stmt_struct* _stmtFalse)
{
	auto temp = static_cast<if_stmt_struct*>(malloc(sizeof(struct if_stmt_struct)));


	temp->expr_value = _expr;
	temp->trueBranch = _stmtTrue;
	temp->falseBranch = _stmtFalse;
	temp->elseIfBranchs = nullptr;

	return temp;
}

struct if_stmt_struct* create_else_if_stmt(struct expr_struct* _expr,
                                        struct stmt_struct* _stmtTrue,
                                        struct elseif_stmt_list_struct* _elseIfStmtList,
                                        struct stmt_struct* _stmtFalse)
{
	auto temp = static_cast<if_stmt_struct*>(malloc(sizeof(struct if_stmt_struct)));


	temp->expr_value = _expr;
	temp->trueBranch = _stmtTrue;
	temp->falseBranch = _stmtFalse;
	temp->elseIfBranchs = _elseIfStmtList;

	return temp;
}

struct elseif_stmt_struct* create_simple_else_if_stmt(struct expr_struct* _expr, struct stmt_struct* _stmt)
{
	auto temp = static_cast<elseif_stmt_struct*>(malloc(sizeof(struct elseif_stmt_struct)));

	temp->expr_value = _expr;
	temp->Stmt = _stmt;

	return temp;
}


struct elseif_stmt_list_struct* create_else_if_stmt_list(struct elseif_stmt_struct* _stmt)
{
	auto temp = static_cast<elseif_stmt_list_struct*>(malloc(sizeof(struct elseif_stmt_list_struct)));

	temp->First = _stmt;
	temp->Next = nullptr;

	return temp;
}

struct elseif_stmt_list_struct* add_to_else_if_stmt_list(struct elseif_stmt_list_struct* _elseIfHead,
                                                    struct elseif_stmt_struct* _stmt)
{
	auto temp = static_cast<elseif_stmt_list_struct*>(malloc(sizeof(struct elseif_stmt_list_struct)));

	auto cur = _elseIfHead;
	while (cur->Next) cur = cur->Next;
	temp->First = _stmt;
	temp->Next = nullptr;
	cur->Next = temp;

	return _elseIfHead;
}

struct stmt_struct* fill_for_stmt(struct for_stmt_struct* _forStmt)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = For;
	temp->ForStmt = _forStmt;

	return temp;
}

struct for_stmt_struct* create_for_stmt(struct expr_struct* _initial, struct expr_struct* _condition,
                                      struct expr_struct* _finalExp, struct stmt_struct* _stmt)
{
	auto temp = static_cast<for_stmt_struct*>(malloc(sizeof(struct for_stmt_struct)));

	temp->Initial = _initial;
	temp->Condition = _condition;
	temp->Final_expr = _finalExp;
	temp->Stmt = _stmt;

	return temp;
}

struct stmt_struct* create_while_stmt(struct expr_struct* _condition, struct stmt_struct* _stmt)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = While;
	temp->expr_value = _condition;
	temp->Stmt = _stmt;

	return temp;
}

struct stmt_struct* create_do_while_stmt(struct stmt_struct* _stmt, struct expr_struct* _condition)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = doWhile;
	temp->Stmt = _stmt;
	temp->expr_value = _condition;

	return temp;
}

struct stmt_struct* create_console_in_stmt(struct expr_struct* _expr)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = consoleIn;
	temp->expr_value = _expr;

	return temp;
}

struct stmt_struct* create_console_out_stmt(struct expr_struct* _expr)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = consoleOut;
	temp->expr_value = _expr;

	return temp;
}

struct switch_stmt_struct* create_switch_stmt(struct expr_struct* _expr, struct case_stmt_list_struct* _caseStmtList,
                                            struct default_stmt_struct* _defaultStmt)
{
	auto temp = static_cast<switch_stmt_struct*>(malloc(sizeof(struct switch_stmt_struct)));

	temp->expr_value = _expr;
	temp->CasesStmtList = _caseStmtList;
	temp->DefaultStmt = _defaultStmt;

	return temp;
}

struct stmt_struct* fill_switch_stmt(struct switch_stmt_struct* _switchStmt)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = Switch;
	temp->SwitchStmt = _switchStmt;

	return temp;
}

struct case_stmt_list_struct* create_case_stmt_list(struct case_stmt_struct* _caseStmt)
{
	auto temp = static_cast<case_stmt_list_struct*>(malloc(sizeof(struct case_stmt_list_struct)));

	temp->First = _caseStmt;
	temp->Next = nullptr;

	return temp;
}

struct case_stmt_list_struct* add_to_case_stmt_list(struct case_stmt_list_struct* _caseHead, struct case_stmt_struct* _stmt)
{
	auto temp = static_cast<case_stmt_list_struct*>(malloc(sizeof(struct case_stmt_list_struct)));

	auto cur = _caseHead;
	while (cur->Next) cur = cur->Next;
	temp->First = _stmt;
	temp->Next = nullptr;
	cur->Next = temp;

	return _caseHead;
}

struct case_stmt_struct* create_case_stmt(struct expr_struct* _expr, struct stmt_list_struct* _stmtList)
{
	auto temp = static_cast<case_stmt_struct*>(malloc(sizeof(struct case_stmt_struct)));

	temp->expr_value = _expr;
	temp->StmtList = _stmtList;


	return temp;
}

struct default_stmt_struct* create_default_stmt(struct stmt_list_struct* _stmtList)
{
	auto temp = static_cast<default_stmt_struct*>(malloc(sizeof(struct default_stmt_struct)));

	temp->StmtList = _stmtList;

	return temp;
}

struct stmt_struct* fill_for_of_stmt(struct forOf_stmt_struct* _forOfStmt)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = ForOf;
	temp->ForOfStmt = _forOfStmt;

	return temp;
}

struct forOf_stmt_struct* create_for_of_stmt(struct expr_struct* _expr, struct expr_struct* _exprIterable,
                                          struct stmt_struct* _stmt)
{
	auto temp = static_cast<forOf_stmt_struct*>(malloc(sizeof(struct forOf_stmt_struct)));

	temp->expr_value = _expr;
	temp->ExprIterable = _exprIterable;
	temp->Stmt = _stmt;

	return temp;
}

struct stmt_struct* create_array(struct array_handling_struct* _array)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = array_handling;
	temp->array = _array;

	return temp;
}

struct array_handling_struct* create_array_handling_stmt(struct expr_struct* _expr,
                                                      struct expr_list_struct* _arrayElements)
{
	auto temp = static_cast<array_handling_struct*>(malloc(sizeof(struct array_handling_struct)));

	temp->expr_value = _expr;
	temp->ArrayElements = _arrayElements;

	return temp;
}

struct expr_list_struct* create_expr_list(struct expr_struct* _expr)
{
	auto temp = static_cast<expr_list_struct*>(malloc(sizeof(struct expr_list_struct)));


	temp->expr_value = _expr;
	temp->NextExpr = nullptr;

	return temp;
}

struct expr_list_struct* add_to_expr_list(struct expr_list_struct* _exprHead, struct expr_struct* _expr)
{
	auto temp = static_cast<expr_list_struct*>(malloc(sizeof(struct expr_list_struct)));

	auto cur = _exprHead;

	while (cur->NextExpr) cur = cur->NextExpr;
	temp->expr_value = _expr;
	temp->NextExpr = nullptr;
	cur->NextExpr = temp;

	return _exprHead;
}

