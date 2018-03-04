//
// Created by squadrick on 3/3/18.
//

#include "repl.h"

Repl::Repl() {
    buffer = "";
    input_length = 0;
}

void Repl::readInput() {
    print_prompt();
    std::cin >> buffer;
    input_length = buffer.length();

    if (buffer[0] == '.') {
        switch (meta_command()) {
            case (META_COMMAND_SUCCESS):
                return;
            case (META_COMMAND_UNRECOGNIZED_COMMAND) :
                printf("Unrecognized\n");
                return;
        }
    }

    StatementType type;

    switch (prepare_statement(&type)) {
        case (PREPARE_SUCCESS):
            break;
        case(PREPARE_SYNTAX_ERROR):
            printf("Syntax error\n");
        case (PREPARE_UNRECOGNIZED_COMMAND):
            printf("Unrecognized\n");
            return;
    }

    execute_statement(type);
    printf("Executed");

}

void Repl::print_prompt() {
    std::printf("db > ");
}

Repl::MetaCommandResult Repl::meta_command() {
    if (buffer == ".exit") {
        exit(EXIT_SUCCESS);
    }
    return META_COMMAND_UNRECOGNIZED_COMMAND;

}

Repl::PrepareResult Repl::prepare_statement(StatementType *type) {
    if (buffer.substr(0, 6) == "insert") {
        *type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }
    if (buffer.substr(0, 6) == "select") {
        *type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }

    return PREPARE_UNRECOGNIZED_COMMAND;
}

void Repl::execute_statement(StatementType type) {
    switch (type) {
        case (STATEMENT_INSERT):
            printf("This is where we would do an insert\n");
            break;

        case (STATEMENT_SELECT):
            printf("This is where we would do a select.\n");
            break;
    }
}

int main() {
    Repl ;
    
    while (true) {
        in.readInput();
    }
}