//
// Created by squadrick on 3/3/18.
//

#ifndef DS_SQL_INPUTBUFFER_H
#define DS_SQL_INPUTBUFFER_H

#include <iostream>
#include <string>

class Repl {
public:

    Repl();

    void readInput();

private:
    std::string buffer;
    size_t input_length;

    void print_prompt();

    enum MetaCommandResult {
        META_COMMAND_SUCCESS,
        META_COMMAND_UNRECOGNIZED_COMMAND
    };

    enum PrepareResult {
        PREPARE_SUCCESS,
        PREPARE_SYNTAX_ERROR,
        PREPARE_UNRECOGNIZED_COMMAND
    };

    enum StatementType {
        STATEMENT_INSERT,
        STATEMENT_SELECT
    };

    enum ExecuteResult {
        EXECUTE_SUCCESS,
        EXECUTE_TABLE_FULL
    };

    MetaCommandResult meta_command();

    PrepareResult prepare_statement(StatementType *type);

    void execute_statement(StatementType type);

};


#endif //DS_SQL_INPUTBUFFER_H
