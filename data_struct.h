#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/************************* dATA sTRUCTURE ***************************/
enum exprType {Int_val, Float, Id, array_element_access, Plus, Minus, Mul, Div, Brac,Remi, EQ, SEQ, NEQ, GR,SM, GREQ, SMEQ, Assign, Pow, Or, And, Not, Umin, Uplu};
enum stmtType {Null, EXPR, BLOCK, Break, array_handling, If, ElseIf, For, While, doWhile, Switch, ForOf,consoleIn, consoleOut};
enum stmtListType{ Stmt_List, ElseIf_Stmt_List, Case_Stmt_List};
struct expr_struct {
    enum exprType type;
    int Num;
    float Float;
    const char* value;
    struct expr_struct* left;
    struct expr_struct* right;


};
struct expr_list_struct {
    struct expr_struct* expr_value;
    struct expr_list_struct* NextExpr;

};

struct stmt_struct {
    enum stmtType type;
    struct expr_struct* expr_value;
    struct stmt_list_struct* Block;
    struct array_handling_struct* array;
    struct stmt_struct* Stmt;
    struct if_stmt_struct* IfStmt;
    struct for_stmt_struct* ForStmt;
    struct switch_stmt_struct* SwitchStmt;
    struct forOf_stmt_struct* ForOfStmt;


};

struct stmt_list_struct {

    enum stmtListType type;
    struct stmt_struct* First;
    struct stmt_list_struct* Next;

    struct elseif_stmt_list_struct* ElseIfStmtList;
    struct case_stmt_list_struct* SwitchCasesStmtList;
};

struct if_stmt_struct {
    struct expr_struct* expr_value;
    struct stmt_struct* trueBranch;
    struct stmt_struct* falseBranch;
    struct elseif_stmt_list_struct* elseIfBranchs;
};

struct elseif_stmt_struct {
    struct expr_struct* expr_value;
    struct stmt_struct* Stmt;
};

struct elseif_stmt_list_struct {
    struct elseif_stmt_struct* First;
    struct elseif_stmt_list_struct* Next;
};

struct for_stmt_struct {
    struct expr_struct* Initial;
    struct expr_struct* Condition;
    struct expr_struct* Final_expr;
    struct stmt_struct* Stmt;

};

struct switch_stmt_struct {
    struct expr_struct* expr_value;
    struct case_stmt_list_struct* CasesStmtList;
    struct default_stmt_struct* DefaultStmt;

};
struct case_stmt_list_struct {

    struct case_stmt_struct* First;
    struct case_stmt_list_struct* Next;
};

struct default_stmt_struct {
    struct stmt_list_struct* StmtList;
};
struct case_stmt_struct {
    struct expr_struct* expr_value;
    struct stmt_list_struct* StmtList;
};

struct forOf_stmt_struct {
    struct expr_struct* expr_value;
    struct expr_struct* ExprIterable;
    struct stmt_struct* Stmt;
};

struct array_handling_struct {

    struct expr_struct* expr_value;
    struct expr_list_struct* ArrayElements;
};


/************************* fUNCTION dECLARATION ***************************/

struct expr_struct * createDigitExpr(int _num);
struct expr_struct * createFloatExpr(float _float);
struct expr_struct * createVariableExpr(char * _value);
struct expr_struct * createBinaryOpeartionExpr(enum exprType _type, struct expr_struct	*_left, struct expr_struct *_right);
struct expr_struct * createUnaryOpeartionExpr(enum exprType _type, struct expr_struct	*_left);
struct stmt_struct * createStmt(struct expr_struct * _expr);
struct stmt_struct * createStmtNull();
struct stmt_struct * createStmtBreak();
struct stmt_struct * createBlockStmt(struct stmt_list_struct * _block);
struct stmt_list_struct * createStmtList(struct stmt_struct *_stmt);
struct stmt_list_struct * addToStmtList(struct stmt_list_struct* _head, struct stmt_struct *_stmt );
struct stmt_struct * FillIfStmt(struct if_stmt_struct* _ifStmtStruct);
struct if_stmt_struct * createIfStmt(struct expr_struct * _expr, struct stmt_struct * _stmtTrue, struct stmt_struct *_stmtFalse);
struct if_stmt_struct * createElseIfStmt(struct expr_struct * _expr, struct stmt_struct * _stmtTrue,struct elseif_stmt_list_struct *_elseIfStmtList,struct stmt_struct *_stmtFalse );
struct elseif_stmt_struct * createSimpleElseIfStmt(struct expr_struct* _expr, struct stmt_struct *_stmt);
struct elseif_stmt_list_struct * createElseIfStmtList(struct elseif_stmt_struct *_stmt);
struct elseif_stmt_list_struct * addToElseIfStmtList(struct elseif_stmt_list_struct *_elseIfHead, struct elseif_stmt_struct *_stmt);
struct stmt_struct * FillForStmt(struct for_stmt_struct * _forStmt);
struct for_stmt_struct * createForStmt(struct expr_struct* _initial, struct expr_struct* _condition, struct expr_struct* _finalExp, struct stmt_struct * _stmt);
struct stmt_struct *createWhileStmt(struct expr_struct* _condition, struct stmt_struct * _stmt );
struct stmt_struct *createDoWhileStmt( struct stmt_struct * _stmt ,struct expr_struct* _condition);
struct stmt_struct *createConsoleInStmt(struct expr_struct* _expr);
struct stmt_struct *createConsoleOutStmt(struct expr_struct* _expr);
struct stmt_struct * fillSwitchStmt(struct switch_stmt_struct *_switchStmt);
struct switch_stmt_struct *createSwitchStmt(struct expr_struct* _expr, struct case_stmt_list_struct * _caseStmtList, struct default_stmt_struct * _defaultStmt);
struct case_stmt_list_struct *createCaseStmtList(struct case_stmt_struct* _caseStmt);
struct case_stmt_list_struct * addToCaseStmtList(struct case_stmt_list_struct *_caseHead, struct case_stmt_struct *_stmt);
struct case_stmt_struct * createCaseStmt(struct expr_struct *_expr, struct stmt_list_struct *_stmtList);
struct default_stmt_struct * createDefaultStmt(struct stmt_list_struct *_stmtList);
struct stmt_struct * fillForOfStmt(struct forOf_stmt_struct* _forOfStmt);
struct forOf_stmt_struct * createForOfStmt(struct expr_struct *_expr, struct expr_struct *_exprIterable, struct stmt_struct *_stmt);
struct stmt_struct * createArray(struct array_handling_struct* _array);
struct array_handling_struct * createArrayHandlingStmt(struct expr_struct * _expr, struct expr_list_struct *_arrayElements);
struct expr_list_struct* createExprList(struct expr_struct* _expr);
struct expr_list_struct* addToExprList(struct expr_list_struct* _exprHead, struct expr_struct* _expr);

/************************* pRINTING tREE fUNCTIONS ***************************/
inline struct stmt_list_struct * root;
inline int _variableCounter=1;
void yyerror(char const *s);
int yylex(void);
void decorate_AST(struct stmt_list_struct * root);
void write_tree(FILE *_filename);
void write_stmt_list(struct stmt_list_struct* _stmtList,
                    char *_parentPath,
                    FILE *_filename);
void write_elseif_stmt_list(struct elseif_stmt_list_struct* _stmtList,
                    char *_parentPath,
                    FILE *_filename);

void write_stmt(struct stmt_struct* _stmt,
                    char *_parentPath,
                    FILE *_filename);

void write_expr(struct expr_struct* _expr,
                char * _parentPath,
                FILE *_filename);
void write_expr_list(struct expr_list_struct* _expr,
                char * _parentPath,
                FILE *_filename);
void write_case_stmt_list(struct case_stmt_list_struct * _stmtList,
                            char *_parentPath,
                            FILE *_filename);
void createLabel(int _variableNum,
                    const char *_variableId,
                    char* result);
void write_binary_expr(struct expr_struct *_expr,
                        const char* _sign,
                         const char* _parentPath,
                        FILE* _filename);
void write_unary_expr(struct expr_struct *_expr,
                        const char* _sign,
                        const char* _parentPath,
                        FILE* _filename);
