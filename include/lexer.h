#ifndef DS_SQL_LEXER
#define DS_SQL_LEXER

#include <string>
#include <iostream>

using namespace std;
class Lexer{
public:
    Lexer(std::string query);
    void parse();
private:
    string query;
    int offset;
    string nextToken();
    void execute_insert();
    void execute_select();
    void execute_create();
    void execute_update();
    void execute_delete();
    void execute_alter();

    enum StatementType {
        STATEMENT_INSERT,
        STATEMENT_SELECT,
        STATEMENT_CREATE,
        STATEMENT_UPDATE,
        STATEMENT_DELETE,
        STATEMENT_ALTER
    };
};

#endif