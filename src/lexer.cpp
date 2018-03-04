#include "lexer.h"

using namespace std;

Lexer::Lexer(string inp_query){
    query = inp_query;
    offset = 0;
}

string Lexer::nextToken(){
    string token = "";
    for(int i=offset;i<query.length();i++){
        if((query[i]<'a' || query[i]>'z') && query[i]!='_'){
            offset = i+1;
            return token;
        }
        token = token + query[i];
    }
    return token;
}

void Lexer::parse() {
    StatementType type;
    std::string token = nextToken();
    if(token == "insert") {
        type = STATEMENT_INSERT;
        execute_insert();
    } else if(token == "select") {
        type = STATEMENT_SELECT;
        execute_select();
    } else if(token == "update") {
        type = STATEMENT_UPDATE;
        execute_update();
    } else if(token == "create") {
        type = STATEMENT_CREATE;
        execute_create();
    } else if(token == "delete") {
        type = STATEMENT_DELETE;
        execute_delete();
    } else if(token == "alter") {
        type = STATEMENT_ALTER;
        execute_alter();
    } else {
        std::cerr<<"Unexpected token "<<token;
    }
}

/**
 * Syntax for create table
 * CREATE TABLE <table_name>(<Attribute List>)
 * Each Attribute will be
 * <Attr_name> <Attr_type> <Attr_constraints>
*/
void Lexer::execute_create(){
    string token = nextToken();
    if(token!="table"){
        std::cerr<<"Unexpected token "<<token;
    }
}