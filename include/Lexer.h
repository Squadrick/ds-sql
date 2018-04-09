#ifndef DS_SQL_LEXER_H
#define DS_SQL_LEXER_H

#include <string>
#include <regex>
#include <vector>
#include <sstream>

class Lexer {
public:
    Lexer(std::string command);
    void evaluate();

private:
    std::string query;
    std::regex create_regex;
    std::regex insert_regex;
    void select();
    void insert(std::string tablename,std::string attributes);
    void create(std::string tablename,std::string attributes);
    void update();
    void remove();
    std::vector<std::string> split(std::string s);
};

#endif