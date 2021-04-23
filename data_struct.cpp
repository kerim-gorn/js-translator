#include "data_struct.h"


struct expr_struct* createDigitExpr(int _num)
{
	auto result = static_cast<expr_struct*>(malloc(sizeof(struct expr_struct)));
	result->type = Int_val;
	result->Num = _num;

	return result;
}


struct expr_struct* createFloatExpr(float _float)
{
	auto result = static_cast<expr_struct*>(malloc(sizeof(struct expr_struct)));
	result->type = Float;
	result->Float = _float;

	return result;
}

struct expr_struct* createVariableExpr(char* _value)
{
	auto result = static_cast<expr_struct*>(malloc(sizeof(struct expr_struct)));
	result->type = Id;
	result->value = _value;

	return result;
}


struct expr_struct* createBinaryOpeartionExpr(enum exprType _type, struct expr_struct* _left,
                                              struct expr_struct* _right)
{
	auto result = static_cast<expr_struct*>(malloc(sizeof(struct expr_struct)));

	result->type = _type;
	result->left = _left;
	result->right = _right;

	return result;
}

struct expr_struct* createUnaryOpeartionExpr(enum exprType _type, struct expr_struct* _left)
{
	auto result = static_cast<expr_struct*>(malloc(sizeof(struct expr_struct)));

	result->type = _type;
	result->left = _left;

	return result;
}

struct stmt_struct* createStmt(struct expr_struct* _expr)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = EXPR;
	temp->expr_value = _expr;

	return temp;
}

struct stmt_struct* createStmtNull()
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = Null;
	temp->expr_value = nullptr;

	return temp;
}

struct stmt_struct* createStmtBreak()
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	auto result = static_cast<expr_struct*>(malloc(sizeof(struct expr_struct)));
	result->type = Id;
	result->value = "break";

	temp->type = Break;
	temp->expr_value = result;
	//	temp->expr_value->type = Id;
	//	temp->expr_value->value = "break";

	return temp;
}

struct stmt_struct* createBlockStmt(struct stmt_list_struct* _block)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = BLOCK;
	temp->Block = _block;

	return temp;
}

struct stmt_list_struct* createStmtList(struct stmt_struct* _stmt)
{
	auto temp = static_cast<stmt_list_struct*>(malloc(sizeof(struct stmt_list_struct)));

	//temp->type = Stmt_List;
	temp->First = _stmt;
	temp->Next = nullptr;
	return temp;
}

struct stmt_list_struct* addToStmtList(struct stmt_list_struct* _head, struct stmt_struct* _stmt)
{
	auto cur = static_cast<stmt_list_struct*>(malloc(sizeof(struct stmt_list_struct)));
	auto temp = static_cast<stmt_list_struct*>(malloc(sizeof(struct stmt_list_struct)));

	cur = _head;
	while (cur->Next) cur = cur->Next;
	temp->First = _stmt;
	temp->Next = nullptr;
	cur->Next = temp;

	return _head;
}

struct stmt_struct* FillIfStmt(struct if_stmt_struct* _ifStmtStruct)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = If;
	temp->IfStmt = _ifStmtStruct;

	return temp;
}

struct if_stmt_struct* createIfStmt(struct expr_struct* _expr, struct stmt_struct* _stmtTrue,
                                    struct stmt_struct* _stmtFalse)
{
	auto temp = static_cast<if_stmt_struct*>(malloc(sizeof(struct if_stmt_struct)));


	temp->expr_value = _expr;
	temp->trueBranch = _stmtTrue;
	temp->falseBranch = _stmtFalse;
	temp->elseIfBranchs = nullptr;

	return temp;
}

struct if_stmt_struct* createElseIfStmt(struct expr_struct* _expr,
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

struct elseif_stmt_struct* createSimpleElseIfStmt(struct expr_struct* _expr, struct stmt_struct* _stmt)
{
	auto temp = static_cast<elseif_stmt_struct*>(malloc(sizeof(struct elseif_stmt_struct)));

	temp->expr_value = _expr;
	temp->Stmt = _stmt;

	return temp;
}


struct elseif_stmt_list_struct* createElseIfStmtList(struct elseif_stmt_struct* _stmt)
{
	auto temp = static_cast<elseif_stmt_list_struct*>(malloc(sizeof(struct elseif_stmt_list_struct)));

	temp->First = _stmt;
	temp->Next = nullptr;

	return temp;
}

struct elseif_stmt_list_struct* addToElseIfStmtList(struct elseif_stmt_list_struct* _elseIfHead,
                                                    struct elseif_stmt_struct* _stmt)
{
	auto cur = static_cast<elseif_stmt_list_struct*>(malloc(sizeof(struct elseif_stmt_list_struct)));
	auto temp = static_cast<elseif_stmt_list_struct*>(malloc(sizeof(struct elseif_stmt_list_struct)));

	cur = _elseIfHead;
	while (cur->Next) cur = cur->Next;
	temp->First = _stmt;
	temp->Next = nullptr;
	cur->Next = temp;

	return _elseIfHead;
}

struct stmt_struct* FillForStmt(struct for_stmt_struct* _forStmt)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = For;
	temp->ForStmt = _forStmt;

	return temp;
}

struct for_stmt_struct* createForStmt(struct expr_struct* _initial, struct expr_struct* _condition,
                                      struct expr_struct* _finalExp, struct stmt_struct* _stmt)
{
	auto temp = static_cast<for_stmt_struct*>(malloc(sizeof(struct for_stmt_struct)));

	temp->Initial = _initial;
	temp->Condition = _condition;
	temp->Final_expr = _finalExp;
	temp->Stmt = _stmt;

	return temp;
}

struct stmt_struct* createWhileStmt(struct expr_struct* _condition, struct stmt_struct* _stmt)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = While;
	temp->expr_value = _condition;
	temp->Stmt = _stmt;

	return temp;
}

struct stmt_struct* createDoWhileStmt(struct stmt_struct* _stmt, struct expr_struct* _condition)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = doWhile;
	temp->Stmt = _stmt;
	temp->expr_value = _condition;

	return temp;
}

struct stmt_struct* createConsoleInStmt(struct expr_struct* _expr)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = consoleIn;
	temp->expr_value = _expr;

	return temp;
}

struct stmt_struct* createConsoleOutStmt(struct expr_struct* _expr)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = consoleOut;
	temp->expr_value = _expr;

	return temp;
}

struct switch_stmt_struct* createSwitchStmt(struct expr_struct* _expr, struct case_stmt_list_struct* _caseStmtList,
                                            struct default_stmt_struct* _defaultStmt)
{
	auto temp = static_cast<switch_stmt_struct*>(malloc(sizeof(struct switch_stmt_struct)));

	temp->expr_value = _expr;
	temp->CasesStmtList = _caseStmtList;
	temp->DefaultStmt = _defaultStmt;

	return temp;
}

struct stmt_struct* fillSwitchStmt(struct switch_stmt_struct* _switchStmt)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = Switch;
	temp->SwitchStmt = _switchStmt;

	return temp;
}

struct case_stmt_list_struct* createCaseStmtList(struct case_stmt_struct* _caseStmt)
{
	auto temp = static_cast<case_stmt_list_struct*>(malloc(sizeof(struct case_stmt_list_struct)));

	temp->First = _caseStmt;
	temp->Next = nullptr;

	return temp;
}

struct case_stmt_list_struct* addToCaseStmtList(struct case_stmt_list_struct* _caseHead, struct case_stmt_struct* _stmt)
{
	auto cur = static_cast<case_stmt_list_struct*>(malloc(sizeof(struct case_stmt_list_struct)));
	auto temp = static_cast<case_stmt_list_struct*>(malloc(sizeof(struct case_stmt_list_struct)));

	cur = _caseHead;
	while (cur->Next) cur = cur->Next;
	temp->First = _stmt;
	temp->Next = nullptr;
	cur->Next = temp;

	return _caseHead;
}

struct case_stmt_struct* createCaseStmt(struct expr_struct* _expr, struct stmt_list_struct* _stmtList)
{
	auto temp = static_cast<case_stmt_struct*>(malloc(sizeof(struct case_stmt_struct)));

	temp->expr_value = _expr;
	temp->StmtList = _stmtList;


	return temp;
}

struct default_stmt_struct* createDefaultStmt(struct stmt_list_struct* _stmtList)
{
	auto temp = static_cast<default_stmt_struct*>(malloc(sizeof(struct default_stmt_struct)));

	temp->StmtList = _stmtList;

	return temp;
}

struct stmt_struct* fillForOfStmt(struct forOf_stmt_struct* _forOfStmt)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = ForOf;
	temp->ForOfStmt = _forOfStmt;

	return temp;
}

struct forOf_stmt_struct* createForOfStmt(struct expr_struct* _expr, struct expr_struct* _exprIterable,
                                          struct stmt_struct* _stmt)
{
	auto temp = static_cast<forOf_stmt_struct*>(malloc(sizeof(struct forOf_stmt_struct)));

	temp->expr_value = _expr;
	temp->ExprIterable = _exprIterable;
	temp->Stmt = _stmt;

	return temp;
}

struct stmt_struct* createArray(struct array_handling_struct* _array)
{
	auto temp = static_cast<stmt_struct*>(malloc(sizeof(struct stmt_struct)));

	temp->type = array_handling;
	temp->array = _array;

	return temp;
}

struct array_handling_struct* createArrayHandlingStmt(struct expr_struct* _expr,
                                                      struct expr_list_struct* _arrayElements)
{
	auto temp = static_cast<array_handling_struct*>(malloc(sizeof(struct array_handling_struct)));

	temp->expr_value = _expr;
	temp->ArrayElements = _arrayElements;

	return temp;
}

struct expr_list_struct* createExprList(struct expr_struct* _expr)
{
	auto temp = static_cast<expr_list_struct*>(malloc(sizeof(struct expr_list_struct)));


	temp->expr_value = _expr;
	temp->NextExpr = nullptr;

	return temp;
}

struct expr_list_struct* addToExprList(struct expr_list_struct* _exprHead, struct expr_struct* _expr)
{
	auto cur = static_cast<expr_list_struct*>(malloc(sizeof(struct expr_list_struct)));
	auto temp = static_cast<expr_list_struct*>(malloc(sizeof(struct expr_list_struct)));

	cur = _exprHead;

	while (cur->NextExpr) cur = cur->NextExpr;
	temp->expr_value = _expr;
	temp->NextExpr = nullptr;
	cur->NextExpr = temp;

	return _exprHead;
}

/*******************************Printing Tree Functions **************************************/


void yyerror(const char* s)
{
	printf("%s", s);
}

void write_tree(FILE* _filename)
{
	char dataToAppend[256];

	fputs("digraph tree{\n", _filename);
	if (root == nullptr) fputs("Root is Empty\n", _filename);
	else
	{
		createLabel(_variableCounter, "program: stmt_list ", dataToAppend);
		fputs(dataToAppend, _filename);
		write_stmt_list(root, nullptr, _filename);
		decorate_AST(root);
		printf("write_tree done his job\n");
	}
	fputs("\n\n\n }", _filename);
}

void write_stmt_list(struct stmt_list_struct* _stmtList,
                     char* _parentPath,
                     FILE* _filename)
{
	char leftOperandPath[256];
	char dataToAppend[256];
	char buffer[50];

	if (_parentPath != nullptr)
	{
		fputs(_parentPath, _filename);
		sprintf(buffer, "%d", _variableCounter);
		fputs(buffer, _filename);
		fputs(";\n", _filename);
	}

	sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath
	sprintf(buffer, "%d", _variableCounter);
	strcat(leftOperandPath, buffer);
	strcat(leftOperandPath, "->");

	_variableCounter++;
	while (_stmtList != nullptr)
	{
		write_stmt(_stmtList->First, leftOperandPath, _filename);
		_stmtList = _stmtList->Next;
	}
}

void write_elseif_stmt_list(struct elseif_stmt_list_struct* _stmtList,
                            char* _parentPath,
                            FILE* _filename)
{
	char leftOperandPath[256];
	char dataToAppend[256];
	char buffer[50];


	while (_stmtList != nullptr)
	{
		createLabel(_variableCounter, "elseif_stmt", dataToAppend);
		fputs(dataToAppend, _filename);

		if (_parentPath != nullptr)
		{
			fputs(_parentPath, _filename);
			sprintf(buffer, "%d", _variableCounter);
			fputs(buffer, _filename);
			fputs(";\n", _filename);
		}
		sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath
		sprintf(buffer, "%d", _variableCounter);
		strcat(leftOperandPath, buffer);
		strcat(leftOperandPath, "->");

		_variableCounter++;
		write_expr(_stmtList->First->expr_value, leftOperandPath, _filename);
		_variableCounter++;
		write_stmt(_stmtList->First->Stmt, leftOperandPath, _filename);
		_stmtList = _stmtList->Next;
	}
}

void write_case_stmt_list(struct case_stmt_list_struct* _stmtList,
                          char* _parentPath,
                          FILE* _filename)
{
	char leftOperandPath[256];
	char dataToAppend[256];
	char buffer[50];


	while (_stmtList != nullptr)
	{
		createLabel(_variableCounter, "case_stmt", dataToAppend);
		fputs(dataToAppend, _filename);

		if (_parentPath != nullptr)
		{
			fputs(_parentPath, _filename);
			sprintf(buffer, "%d", _variableCounter);
			fputs(buffer, _filename);
			fputs(";\n", _filename);
		}
		sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath
		sprintf(buffer, "%d", _variableCounter);
		strcat(leftOperandPath, buffer);
		strcat(leftOperandPath, "->");

		_variableCounter++;
		write_expr(_stmtList->First->expr_value, leftOperandPath, _filename);
		_variableCounter++;
		createLabel(_variableCounter, "stmt_block", dataToAppend);
		fputs(dataToAppend, _filename);
		write_stmt_list(_stmtList->First->StmtList, leftOperandPath, _filename);
		_stmtList = _stmtList->Next;
	}
}

void write_stmt(struct stmt_struct* _stmt,
                char* _parentPath,
                FILE* _filename)
{
	char leftOperandPath[256];
	char rightOperandPath[256];
	char dataToAppend[256];
	char buffer[50];


	switch (_stmt->type)
	{
	case Null:
		break;
	case Break:


		_variableCounter++;
		write_expr(_stmt->expr_value, _parentPath, _filename);
		break;
	case EXPR:
		createLabel(_variableCounter, "expr_stmt", dataToAppend);
		fputs(dataToAppend, _filename);

		sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath

		if (_parentPath != nullptr)
			strcat(leftOperandPath, _parentPath);
		sprintf(buffer, "%d", _variableCounter);
		strcat(leftOperandPath, buffer);
		strcat(leftOperandPath, "->");

		_variableCounter++;
		write_expr(_stmt->expr_value, leftOperandPath, _filename);
		break;
	case BLOCK:
		createLabel(_variableCounter, "block_stmt", dataToAppend);
		fputs(dataToAppend, _filename);

		if (_parentPath != nullptr)
		{
			fputs(_parentPath, _filename);
			sprintf(buffer, "%d", _variableCounter);
			fputs(buffer, _filename);
			fputs(";\n", _filename);
		}

		sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath
		sprintf(buffer, "%d", _variableCounter);
		strcat(leftOperandPath, buffer);
		strcat(leftOperandPath, "->");

		_variableCounter++;
		while (_stmt->Block != nullptr)
		{
			write_stmt(_stmt->Block->First, leftOperandPath, _filename);
			_stmt->Block = _stmt->Block->Next;
		}
		break;
	case array_handling:
		createLabel(_variableCounter, "array_initial", dataToAppend);
		fputs(dataToAppend, _filename);

		if (_parentPath != nullptr)
		{
			fputs(_parentPath, _filename);
			sprintf(buffer, "%d", _variableCounter);
			fputs(buffer, _filename);
			fputs(";\n", _filename);
		}

		sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath

		sprintf(buffer, "%d", _variableCounter);
		strcat(leftOperandPath, buffer);
		strcat(leftOperandPath, "->");

		_variableCounter++;
		write_expr(_stmt->array->expr_value, leftOperandPath, _filename);
		_variableCounter++;
		write_expr_list(_stmt->array->ArrayElements, leftOperandPath, _filename);
		break;
	case If:
		createLabel(_variableCounter, "if_stmt", dataToAppend);
		fputs(dataToAppend, _filename);

		if (_parentPath != nullptr)
		{
			fputs(_parentPath, _filename);
			sprintf(buffer, "%d", _variableCounter);
			fputs(buffer, _filename);
			fputs(";\n", _filename);
		}

		sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath

		sprintf(buffer, "%d", _variableCounter);
		strcat(leftOperandPath, buffer);
		strcat(leftOperandPath, "->");

		_variableCounter++;
		write_expr(_stmt->IfStmt->expr_value, leftOperandPath, _filename);
		_variableCounter++;
		write_stmt(_stmt->IfStmt->trueBranch, leftOperandPath, _filename);

		strcpy(rightOperandPath, leftOperandPath);
		if (_stmt->IfStmt->elseIfBranchs != nullptr)
		{
			_variableCounter++;
			createLabel(_variableCounter, "elseif_block", dataToAppend);
			fputs(dataToAppend, _filename);

			if (leftOperandPath != nullptr)
			{
				fputs(leftOperandPath, _filename);
				sprintf(buffer, "%d", _variableCounter);
				fputs(buffer, _filename);
				fputs(";\n", _filename);
			}

			sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath
			sprintf(leftOperandPath, "%d", _variableCounter);
			strcat(leftOperandPath, "->");

			_variableCounter++;
			write_elseif_stmt_list(_stmt->IfStmt->elseIfBranchs, leftOperandPath, _filename);
		}
		if (_stmt->IfStmt->falseBranch != nullptr)
		{
			_variableCounter++;
			write_stmt(_stmt->IfStmt->falseBranch, rightOperandPath, _filename);
		}
		break;
	case While:
		createLabel(_variableCounter, "while_stmt", dataToAppend);
		fputs(dataToAppend, _filename);

		if (_parentPath != nullptr)
		{
			fputs(_parentPath, _filename);
			sprintf(buffer, "%d", _variableCounter);
			fputs(buffer, _filename);
			fputs(";\n", _filename);
		}

		sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath
		sprintf(buffer, "%d", _variableCounter);
		strcat(leftOperandPath, buffer);
		strcat(leftOperandPath, "->");

		_variableCounter++;
		write_expr(_stmt->expr_value, leftOperandPath, _filename);
		_variableCounter++;
		write_stmt(_stmt->Stmt, leftOperandPath, _filename);
		break;
	case For:
		createLabel(_variableCounter, "for_stmt", dataToAppend);
		fputs(dataToAppend, _filename);

		if (_parentPath != nullptr)
		{
			fputs(_parentPath, _filename);
			sprintf(buffer, "%d", _variableCounter);
			fputs(buffer, _filename);
			fputs(";\n", _filename);
		}

		sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath
		sprintf(buffer, "%d", _variableCounter);
		strcat(leftOperandPath, buffer);
		strcat(leftOperandPath, "->");

		_variableCounter++;
		write_expr(_stmt->ForStmt->Initial, leftOperandPath, _filename);
		_variableCounter++;
		write_expr(_stmt->ForStmt->Condition, leftOperandPath, _filename);
		_variableCounter++;
		write_expr(_stmt->ForStmt->Final_expr, leftOperandPath, _filename);
		_variableCounter++;
		write_stmt(_stmt->ForStmt->Stmt, leftOperandPath, _filename);
		break;
	case doWhile:
		createLabel(_variableCounter, "doWhile_stmt", dataToAppend);
		fputs(dataToAppend, _filename);

		if (_parentPath != nullptr)
		{
			fputs(_parentPath, _filename);
			sprintf(buffer, "%d", _variableCounter);
			fputs(buffer, _filename);
			fputs(";\n", _filename);
		}

		sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath
		sprintf(buffer, "%d", _variableCounter);
		strcat(leftOperandPath, buffer);
		strcat(leftOperandPath, "->");

		_variableCounter++;
		write_expr(_stmt->expr_value, leftOperandPath, _filename);
		_variableCounter++;
		write_stmt(_stmt->Stmt, leftOperandPath, _filename);
		break;
	case Switch:
		createLabel(_variableCounter, "Swtich_stmt", dataToAppend);
		fputs(dataToAppend, _filename);

		if (_parentPath != nullptr)
		{
			fputs(_parentPath, _filename);
			sprintf(buffer, "%d", _variableCounter);
			fputs(buffer, _filename);
			fputs(";\n", _filename);
		}

		sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath
		sprintf(buffer, "%d", _variableCounter);
		strcat(leftOperandPath, buffer);
		strcat(leftOperandPath, "->");

		_variableCounter++;
		write_expr(_stmt->SwitchStmt->expr_value, leftOperandPath, _filename);

		if (_stmt->SwitchStmt->CasesStmtList != nullptr)
		{
			_variableCounter++;
			write_case_stmt_list(_stmt->SwitchStmt->CasesStmtList, leftOperandPath, _filename);
		}
		if (_stmt->SwitchStmt->DefaultStmt != nullptr)
		{
			_variableCounter++;
			createLabel(_variableCounter, "default_block", dataToAppend);
			fputs(dataToAppend, _filename);

			write_stmt_list(_stmt->SwitchStmt->DefaultStmt->StmtList, leftOperandPath, _filename);
		}
		break;
	case ForOf:
		createLabel(_variableCounter, "ForOf_stmt", dataToAppend);
		fputs(dataToAppend, _filename);

		if (_parentPath != nullptr)
		{
			fputs(_parentPath, _filename);
			sprintf(buffer, "%d", _variableCounter);
			fputs(buffer, _filename);
			fputs(";\n", _filename);
		}

		sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath
		sprintf(buffer, "%d", _variableCounter);
		strcat(leftOperandPath, buffer);
		strcat(leftOperandPath, "->");

		_variableCounter++;
		write_expr(_stmt->ForOfStmt->expr_value, leftOperandPath, _filename);
		_variableCounter++;
		write_expr(_stmt->ForOfStmt->ExprIterable, leftOperandPath, _filename);
		_variableCounter++;
		write_stmt(_stmt->ForOfStmt->Stmt, leftOperandPath, _filename);
		break;
	case consoleIn:
		createLabel(_variableCounter, "consoleIn", dataToAppend);
		fputs(dataToAppend, _filename);

		if (_parentPath != nullptr)
		{
			fputs(_parentPath, _filename);
			sprintf(buffer, "%d", _variableCounter);
			fputs(buffer, _filename);
			fputs(";\n", _filename);
		}

		sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath
		sprintf(buffer, "%d", _variableCounter);
		strcat(leftOperandPath, buffer);
		strcat(leftOperandPath, "->");

		_variableCounter++;
		write_expr(_stmt->expr_value, leftOperandPath, _filename);
		break;
	case consoleOut:
		createLabel(_variableCounter, "consoleOut", dataToAppend);
		fputs(dataToAppend, _filename);

		if (_parentPath != nullptr)
		{
			fputs(_parentPath, _filename);
			sprintf(buffer, "%d", _variableCounter);
			fputs(buffer, _filename);
			fputs(";\n", _filename);
		}

		sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath
		sprintf(buffer, "%d", _variableCounter);
		strcat(leftOperandPath, buffer);
		strcat(leftOperandPath, "->");

		_variableCounter++;
		write_expr(_stmt->expr_value, leftOperandPath, _filename);
		break;
	}
}

void write_expr(struct expr_struct* _expr,
                char* _parentPath,
                FILE* _filename)
{
	char leftOperandPath[256];
	char rightOperandPath[256];
	char dataToAppend[256];
	char buffer[50];

	switch (_expr->type)
	{
	case Int_val:
		sprintf(buffer, "%d", _expr->Num);
		createLabel(_variableCounter, buffer, dataToAppend);

		strcat(dataToAppend, _parentPath);
		sprintf(buffer, "%d", _variableCounter);

		strcat(dataToAppend, buffer);
		strcat(dataToAppend, ";\n");

		fputs(dataToAppend, _filename);

		sprintf(dataToAppend, "%s", ""); //to empty the dataToAppend
		sprintf(buffer, "%s", ""); // to empty the buffer
		_variableCounter++;
		break;
	case Float:
		sprintf(buffer, "%f", _expr->Float);
		createLabel(_variableCounter, buffer, dataToAppend);

		strcat(dataToAppend, _parentPath);
		sprintf(buffer, "%d", _variableCounter);

		strcat(dataToAppend, buffer);
		strcat(dataToAppend, ";\n");

		fputs(dataToAppend, _filename);

		sprintf(dataToAppend, "%s", ""); //to empty the dataToAppend
		sprintf(buffer, "%s", ""); // to empty the buffer
		_variableCounter++;
		break;
	case Id:
		createLabel(_variableCounter, _expr->value, dataToAppend);

		strcat(dataToAppend, _parentPath);
		sprintf(buffer, "%d", _variableCounter);

		strcat(dataToAppend, buffer);
		strcat(dataToAppend, ";\n");

		fputs(dataToAppend, _filename);

		sprintf(dataToAppend, "%s", ""); //to empty the dataToAppend
		sprintf(buffer, "%s", ""); // to empty the buffer
		_variableCounter++;
		break;
	case array_element_access:
		write_binary_expr(_expr, "[]", _parentPath, _filename);
		break;
	case Plus:
		write_binary_expr(_expr, "+", _parentPath, _filename);
		break;
	case Minus:
		write_binary_expr(_expr, "-", _parentPath, _filename);
		break;
	case Mul:
		write_binary_expr(_expr, "*", _parentPath, _filename);
		break;
	case Div:
		write_binary_expr(_expr, "/", _parentPath, _filename);
		break;
	case Brac:
		write_unary_expr(_expr, "()", _parentPath, _filename);
		break;
	case Remi:
		write_binary_expr(_expr, "%", _parentPath, _filename);
		break;
	case EQ:
		write_binary_expr(_expr, "==", _parentPath, _filename);
		break;
	case SEQ:
		write_binary_expr(_expr, "===", _parentPath, _filename);
		break;
	case NEQ:
		write_binary_expr(_expr, "!=", _parentPath, _filename);
		break;
	case GR:
		write_binary_expr(_expr, ">", _parentPath, _filename);
		break;
	case SM:
		write_binary_expr(_expr, "<", _parentPath, _filename);
		break;
	case GREQ:
		write_binary_expr(_expr, ">=", _parentPath, _filename);
		break;
	case SMEQ:
		write_binary_expr(_expr, "<=", _parentPath, _filename);
		break;
	case Assign:
		write_binary_expr(_expr, "=", _parentPath, _filename);
		break;
	case Pow:
		write_binary_expr(_expr, "**", _parentPath, _filename);
		break;
	case Or:
		write_binary_expr(_expr, "||", _parentPath, _filename);
		break;
	case And:
		write_binary_expr(_expr, "&&", _parentPath, _filename);
		break;
	case Not:
		write_unary_expr(_expr, "!", _parentPath, _filename);
		break;
	case Uplu:
		write_unary_expr(_expr, "++", _parentPath, _filename);
		break;
	case Umin:
		write_unary_expr(_expr, "--", _parentPath, _filename);
		break;
	}
}

void write_expr_list(struct expr_list_struct* _exprList,
                     //int _variableCounter,
                     char* _parentPath,
                     FILE* _filename)
{
	char leftOperandPath[256];
	char dataToAppend[256];
	char buffer[50];

	createLabel(_variableCounter, "expr_list", dataToAppend);
	fputs(dataToAppend, _filename);

	if (_parentPath != nullptr)
	{
		fputs(_parentPath, _filename);
		sprintf(buffer, "%d", _variableCounter);
		fputs(buffer, _filename);
		fputs(";\n", _filename);
	}

	sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath

	sprintf(buffer, "%d", _variableCounter);
	strcat(leftOperandPath, buffer);
	strcat(leftOperandPath, "->");

	_variableCounter++;
	while (_exprList != nullptr)
	{
		write_expr(_exprList->expr_value, leftOperandPath, _filename);
		_exprList = _exprList->NextExpr;
	}
}

// [1 [label="a"]] - 1=_variableNum and a=_variableId
void createLabel(int _variableNum,
                 const char* _variableId,
                 char* result)
{
	char buffer[50];
	sprintf(buffer, "%d", _variableNum);
	sprintf(result, "%s", "");
	strcat(result, buffer);
	//strcat(result, buffer);
	strcat(result, " [label=\"");
	strcat(result, _variableId);
	strcat(result, "\"]\n");
}

void write_binary_expr(struct expr_struct* _expr,
                       const char* _sign,
                       const char* _parentPath,
                       FILE* _filename)
{
	char leftOperandPath[256];
	char dataToAppend[256];
	char buffer[50];

	createLabel(_variableCounter, _sign, dataToAppend);
	fputs(dataToAppend, _filename);

	if (_parentPath != nullptr)
	{
		fputs(_parentPath, _filename);
		sprintf(buffer, "%d", _variableCounter);
		fputs(buffer, _filename);
		fputs(";\n", _filename);
	}

	sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath

	sprintf(buffer, "%d", _variableCounter);
	strcat(leftOperandPath, buffer);
	strcat(leftOperandPath, "->");

	_variableCounter++;
	write_expr(_expr->left, leftOperandPath, _filename);
	_variableCounter++;
	write_expr(_expr->right, leftOperandPath, _filename);
}

void write_unary_expr(struct expr_struct* _expr,
                      const char* _sign,
                      const char* _parentPath,
                      FILE* _filename)
{
	char leftOperandPath[256];
	char dataToAppend[256];
	char buffer[50];

	createLabel(_variableCounter, _sign, dataToAppend);
	fputs(dataToAppend, _filename);

	if (_parentPath != nullptr)
	{
		fputs(_parentPath, _filename);
		sprintf(buffer, "%d", _variableCounter);
		fputs(buffer, _filename);
		fputs(";\n", _filename);
	}

	sprintf(leftOperandPath, "%s", ""); // to empty the leftOperandPath

	sprintf(buffer, "%d", _variableCounter);
	strcat(leftOperandPath, buffer);
	strcat(leftOperandPath, "->");

	_variableCounter++;
	write_expr(_expr->left, leftOperandPath, _filename);
}
