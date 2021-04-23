#include "print_tree.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;


enum constant_type
{
	CONSTANT_utf8,
	CONSTANT_int,
	CONSTANT_float,
	CONSTANT_String,
	CONSTANT_methodRef,
	CONSTANT_nameAndType,
	CONSTANT_class,
};

class constant_table
{
public:
	int constNumber;
	enum constant_type type;
	int constNum1;
	int constNum2;
	string constName;
	constant_table* Next;
};

int varCounter;
map<string, int> varTable;
constant_table* constTable = new constant_table();


void decorate_AST(stmt_list_struct* _stmtlist)
{
	while (_stmtlist != nullptr)
	{
		decorate_stmt(_stmtlist->First);
		_stmtlist = _stmtlist->Next;
	}
	printTable();
}

void decorate_stmt(stmt_struct* _stmt)
{
	switch (_stmt->type)
	{
	case Null:
		break;
	case Break:
		break;
	case EXPR:
		break;
	case BLOCK:
		break;
	case array_handling:
		break;
	case If:
		break;
	case While:
		break;
	case For:
		break;
	case doWhile:
		break;
	case Switch:
		break;
	case ForOf:
		break;
	case consoleIn:
		break;
	case consoleOut:
		break;
	}
}

void decorate_expr(expr_struct* _expr)
{
	switch (_expr->type)
	{
	case Int_value:
		break;
	case Float_value:
		break;
	case Id:
		if (varTable.find(_expr->value) == varTable.end())
			varTable.insert(std::pair<string, int>(_expr->value, varCounter++));
		break;
	case array_element_access:
		break;
	case Plus:
		break;
	case Minus:
		break;
	case Multiplication:
		break;
	case Division:
		break;
	case Bracket:
		break;
	case Reminder:
		break;
	case EQ:
		break;
	case SEQ:
		break;
	case NEQ:
		break;
	case GR:
		break;
	case SM:
		break;
	case GREQ:
		break;
	case SMEQ:
		break;
	case Assign:
		if (_expr->left->type == Id)
		{
			decorate_expr(_expr->left);
			decorate_expr(_expr->right);
		}
		else printf("Invalid left-hand side in assignment expression\n");
		break;
	case Pow:
		break;
	case Or:
		break;
	case And:
		break;
	case Not:
		break;
	case unary_minus:
		break;
	case unary_plus:
		break;
	}
}

void printTable()
{
	FILE* _filename;
	_filename = fopen("VarAndConstTable.txt", "w");
	if (_filename == nullptr) printf("cannot opening file");
	else
	{
		map<string, int>::const_iterator iterator = varTable.begin();
		while (iterator != varTable.end())
		{
			cout << iterator->first << ":" << iterator->second << endl;
		}
	}
}

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
		printf("printed tree\n");
	}
	fputs("\n\n\n }", _filename);
}

void write_stmt_list(struct stmt_list_struct* _stmtList,
	char* _parentPath,
	FILE* _filename)
{
	char left_operand_path[256];

	char buffer[50];

	if (_parentPath != nullptr)
	{
		fputs(_parentPath, _filename);
		sprintf(buffer, "%d", _variableCounter);
		fputs(buffer, _filename);
		fputs(";\n", _filename);
	}

	sprintf(left_operand_path, "%s", "");
	sprintf(buffer, "%d", _variableCounter);
	strcat(left_operand_path, buffer);
	strcat(left_operand_path, "->");

	_variableCounter++;
	while (_stmtList != nullptr)
	{
		write_stmt(_stmtList->First, left_operand_path, _filename);
		_stmtList = _stmtList->Next;
	}
}

void write_elseif_stmt_list(struct elseif_stmt_list_struct* _stmtList,
	char* _parentPath,
	FILE* _filename)
{
	char left_operand_path[256];
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
		sprintf(left_operand_path, "%s", "");
		sprintf(buffer, "%d", _variableCounter);
		strcat(left_operand_path, buffer);
		strcat(left_operand_path, "->");

		_variableCounter++;
		write_expr(_stmtList->First->expr_value, left_operand_path, _filename);
		_variableCounter++;
		write_stmt(_stmtList->First->Stmt, left_operand_path, _filename);
		_stmtList = _stmtList->Next;
	}
}

void write_case_stmt_list(struct case_stmt_list_struct* _stmtList,
	char* _parentPath,
	FILE* _filename)
{
	char left_operand_path[256];
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
		sprintf(left_operand_path, "%s", "");
		sprintf(buffer, "%d", _variableCounter);
		strcat(left_operand_path, buffer);
		strcat(left_operand_path, "->");

		_variableCounter++;
		write_expr(_stmtList->First->expr_value, left_operand_path, _filename);
		_variableCounter++;
		createLabel(_variableCounter, "stmt_block", dataToAppend);
		fputs(dataToAppend, _filename);
		write_stmt_list(_stmtList->First->StmtList, left_operand_path, _filename);
		_stmtList = _stmtList->Next;
	}
}

void write_stmt(struct stmt_struct* _stmt,
	char* _parentPath,
	FILE* _filename)
{
	char left_operand_path[256];
	char right_operand_path[256];
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

		sprintf(left_operand_path, "%s", "");

		if (_parentPath != nullptr)
			strcat(left_operand_path, _parentPath);
		sprintf(buffer, "%d", _variableCounter);
		strcat(left_operand_path, buffer);
		strcat(left_operand_path, "->");

		_variableCounter++;
		write_expr(_stmt->expr_value, left_operand_path, _filename);
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

		sprintf(left_operand_path, "%s", "");
		sprintf(buffer, "%d", _variableCounter);
		strcat(left_operand_path, buffer);
		strcat(left_operand_path, "->");

		_variableCounter++;
		while (_stmt->Block != nullptr)
		{
			write_stmt(_stmt->Block->First, left_operand_path, _filename);
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

		sprintf(left_operand_path, "%s", "");

		sprintf(buffer, "%d", _variableCounter);
		strcat(left_operand_path, buffer);
		strcat(left_operand_path, "->");

		_variableCounter++;
		write_expr(_stmt->array->expr_value, left_operand_path, _filename);
		_variableCounter++;
		write_expr_list(_stmt->array->ArrayElements, left_operand_path, _filename);
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

		sprintf(left_operand_path, "%s", "");

		sprintf(buffer, "%d", _variableCounter);
		strcat(left_operand_path, buffer);
		strcat(left_operand_path, "->");

		_variableCounter++;
		write_expr(_stmt->IfStmt->expr_value, left_operand_path, _filename);
		_variableCounter++;
		write_stmt(_stmt->IfStmt->trueBranch, left_operand_path, _filename);

		strcpy(right_operand_path, left_operand_path);
		if (_stmt->IfStmt->elseIfBranchs != nullptr)
		{
			_variableCounter++;
			createLabel(_variableCounter, "elseif_block", dataToAppend);
			fputs(dataToAppend, _filename);

			if (left_operand_path != nullptr)
			{
				fputs(left_operand_path, _filename);
				sprintf(buffer, "%d", _variableCounter);
				fputs(buffer, _filename);
				fputs(";\n", _filename);
			}

			sprintf(left_operand_path, "%s", "");
			sprintf(left_operand_path, "%d", _variableCounter);
			strcat(left_operand_path, "->");

			_variableCounter++;
			write_elseif_stmt_list(_stmt->IfStmt->elseIfBranchs, left_operand_path, _filename);
		}
		if (_stmt->IfStmt->falseBranch != nullptr)
		{
			_variableCounter++;
			write_stmt(_stmt->IfStmt->falseBranch, right_operand_path, _filename);
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

		sprintf(left_operand_path, "%s", "");
		sprintf(buffer, "%d", _variableCounter);
		strcat(left_operand_path, buffer);
		strcat(left_operand_path, "->");

		_variableCounter++;
		write_expr(_stmt->expr_value, left_operand_path, _filename);
		_variableCounter++;
		write_stmt(_stmt->Stmt, left_operand_path, _filename);
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

		sprintf(left_operand_path, "%s", "");
		sprintf(buffer, "%d", _variableCounter);
		strcat(left_operand_path, buffer);
		strcat(left_operand_path, "->");

		_variableCounter++;
		write_expr(_stmt->ForStmt->Initial, left_operand_path, _filename);
		_variableCounter++;
		write_expr(_stmt->ForStmt->Condition, left_operand_path, _filename);
		_variableCounter++;
		write_expr(_stmt->ForStmt->Final_expr, left_operand_path, _filename);
		_variableCounter++;
		write_stmt(_stmt->ForStmt->Stmt, left_operand_path, _filename);
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

		sprintf(left_operand_path, "%s", "");
		sprintf(buffer, "%d", _variableCounter);
		strcat(left_operand_path, buffer);
		strcat(left_operand_path, "->");

		_variableCounter++;
		write_expr(_stmt->expr_value, left_operand_path, _filename);
		_variableCounter++;
		write_stmt(_stmt->Stmt, left_operand_path, _filename);
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

		sprintf(left_operand_path, "%s", "");
		sprintf(buffer, "%d", _variableCounter);
		strcat(left_operand_path, buffer);
		strcat(left_operand_path, "->");

		_variableCounter++;
		write_expr(_stmt->SwitchStmt->expr_value, left_operand_path, _filename);

		if (_stmt->SwitchStmt->CasesStmtList != nullptr)
		{
			_variableCounter++;
			write_case_stmt_list(_stmt->SwitchStmt->CasesStmtList, left_operand_path, _filename);
		}
		if (_stmt->SwitchStmt->DefaultStmt != nullptr)
		{
			_variableCounter++;
			createLabel(_variableCounter, "default_block", dataToAppend);
			fputs(dataToAppend, _filename);

			write_stmt_list(_stmt->SwitchStmt->DefaultStmt->StmtList, left_operand_path, _filename);
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

		sprintf(left_operand_path, "%s", "");
		sprintf(buffer, "%d", _variableCounter);
		strcat(left_operand_path, buffer);
		strcat(left_operand_path, "->");

		_variableCounter++;
		write_expr(_stmt->ForOfStmt->expr_value, left_operand_path, _filename);
		_variableCounter++;
		write_expr(_stmt->ForOfStmt->ExprIterable, left_operand_path, _filename);
		_variableCounter++;
		write_stmt(_stmt->ForOfStmt->Stmt, left_operand_path, _filename);
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

		sprintf(left_operand_path, "%s", "");
		sprintf(buffer, "%d", _variableCounter);
		strcat(left_operand_path, buffer);
		strcat(left_operand_path, "->");

		_variableCounter++;
		write_expr(_stmt->expr_value, left_operand_path, _filename);
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

		sprintf(left_operand_path, "%s", "");
		sprintf(buffer, "%d", _variableCounter);
		strcat(left_operand_path, buffer);
		strcat(left_operand_path, "->");

		_variableCounter++;
		write_expr(_stmt->expr_value, left_operand_path, _filename);
		break;
	case ElseIf: break;
	}
}

void write_expr(struct expr_struct* _expr,
	char* _parentPath,
	FILE* _filename)
{

	char dataToAppend[256];
	char buffer[50];

	switch (_expr->type)
	{
	case Int_value:
		sprintf(buffer, "%d", _expr->Num);
		createLabel(_variableCounter, buffer, dataToAppend);

		strcat(dataToAppend, _parentPath);
		sprintf(buffer, "%d", _variableCounter);

		strcat(dataToAppend, buffer);
		strcat(dataToAppend, ";\n");

		fputs(dataToAppend, _filename);

		sprintf(dataToAppend, "%s", "");
		sprintf(buffer, "%s", "");
		_variableCounter++;
		break;
	case Float_value:
		sprintf(buffer, "%f", _expr->Float);
		createLabel(_variableCounter, buffer, dataToAppend);

		strcat(dataToAppend, _parentPath);
		sprintf(buffer, "%d", _variableCounter);

		strcat(dataToAppend, buffer);
		strcat(dataToAppend, ";\n");

		fputs(dataToAppend, _filename);

		sprintf(dataToAppend, "%s", "");
		sprintf(buffer, "%s", "");
		_variableCounter++;
		break;
	case Id:
		createLabel(_variableCounter, _expr->value, dataToAppend);

		strcat(dataToAppend, _parentPath);
		sprintf(buffer, "%d", _variableCounter);

		strcat(dataToAppend, buffer);
		strcat(dataToAppend, ";\n");

		fputs(dataToAppend, _filename);

		sprintf(dataToAppend, "%s", "");
		sprintf(buffer, "%s", "");
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
	case Multiplication:
		write_binary_expr(_expr, "*", _parentPath, _filename);
		break;
	case Division:
		write_binary_expr(_expr, "/", _parentPath, _filename);
		break;
	case Bracket:
		write_unary_expr(_expr, "()", _parentPath, _filename);
		break;
	case Reminder:
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
	case unary_plus:
		write_unary_expr(_expr, "++", _parentPath, _filename);
		break;
	case unary_minus:
		write_unary_expr(_expr, "--", _parentPath, _filename);
		break;
	}
}

void write_expr_list(struct expr_list_struct* _exprList,
	char* _parentPath,
	FILE* _filename)
{
	char left_operand_path[256];
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

	sprintf(left_operand_path, "%s", "");

	sprintf(buffer, "%d", _variableCounter);
	strcat(left_operand_path, buffer);
	strcat(left_operand_path, "->");

	_variableCounter++;
	while (_exprList != nullptr)
	{
		write_expr(_exprList->expr_value, left_operand_path, _filename);
		_exprList = _exprList->NextExpr;
	}
}

void createLabel(int _variableNum,
	const char* _variableId,
	char* result)
{
	char buffer[50];
	sprintf(buffer, "%d", _variableNum);
	sprintf(result, "%s", "");
	strcat(result, buffer);
	strcat(result, " [label=\"");
	strcat(result, _variableId);
	strcat(result, "\"]\n");
}

void write_binary_expr(struct expr_struct* _expr,
	const char* _sign,
	const char* _parentPath,
	FILE* _filename)
{
	char left_operand_path[256];
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

	sprintf(left_operand_path, "%s", "");

	sprintf(buffer, "%d", _variableCounter);
	strcat(left_operand_path, buffer);
	strcat(left_operand_path, "->");

	_variableCounter++;
	write_expr(_expr->left, left_operand_path, _filename);
	_variableCounter++;
	write_expr(_expr->right, left_operand_path, _filename);
}

void write_unary_expr(struct expr_struct* _expr,
	const char* _sign,
	const char* _parentPath,
	FILE* _filename)
{
	char left_operand_path[256];
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

	sprintf(left_operand_path, "%s", "");

	sprintf(buffer, "%d", _variableCounter);
	strcat(left_operand_path, buffer);
	strcat(left_operand_path, "->");

	_variableCounter++;
	write_expr(_expr->left, left_operand_path, _filename);
}
