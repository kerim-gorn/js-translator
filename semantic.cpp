#include <iostream>
#include <map>
#include <string>

#include "data_struct.h"
#include "semantic.h"
using namespace std; 




enum constant_type {
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
    constant_table *Next;
};

int varCounter;
map<string,int> varTable;
constant_table *constTable = new constant_table();


void decorate_AST(stmt_list_struct * _stmtlist){

    while(_stmtlist!=0){
        decorate_stmt(_stmtlist->First);
        _stmtlist = _stmtlist->Next;
    }
    printTable();
}

void decorate_stmt(stmt_struct * _stmt){

    switch (_stmt->type){

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
void decorate_expr(expr_struct * _expr){

    switch(_expr->type){
    case Int_val:
        break;
    case Float:
        break;
    case Id:
        if(varTable.find(_expr->value) == varTable.end())
            varTable.insert(std::pair<string, int>(_expr->value,varCounter++));
        break;
    case array_element_access:
        break;
    case Plus:
        break;
    case Minus:
        break;
    case Mul:
        break;
    case Div:
        break;
    case Brac:
        break;
    case Remi:
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
        if(_expr->left->type ==Id){
            decorate_expr(_expr->left);
            decorate_expr(_expr->right);
        }else printf("Invalid left-hand side in assignment expression\n");
        break;
    case Pow:
        break;
    case Or:
        break;
    case And:
        break;
    case Not:
        break;
    case Umin:
        break;
    case Uplu:
        break;

    }
}
void printTable(){
    FILE * _filename;
    _filename = fopen("VarAndConstTable.txt", "w");
    if(_filename == NULL) printf("cannot opening file");
    else{
        map<string, int>::const_iterator iterator = varTable.begin();
        while(iterator !=varTable.end()){
            cout<< iterator->first << ":" << iterator->second <<endl;
        }
    }
}

// restructure all structures here????
// Make a good structure for tree_struct
