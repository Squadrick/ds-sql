#include "Lexer.h"
#include "Table.h"
#include "Type.h"
#include "Attribute.h"
#include "Constraint.h"

Lexer::Lexer(std::string command):
    create_regex("CREATE TABLE ([A-Z_]+) ?\(([A-Z0-9 \(\),]+)+\);"),
    insert_regex("INSERT INTO ([A-Z_]+) VALUES ?\((.+)\);") {
    query = command;
}

void Lexer::evaluate() {
    std::smatch sm;
    if(std::regex_match(query,sm,create_regex)) {  //CREATE_TABLE
        create(sm[1].str(),sm[2].str().substr(1, sm[2].str().size()-2));
    } else if(std::regex_match(query,sm,insert_regex)) { //INSERT
        // insert(sm[1].str(),sm[2].str().substr(1, sm[2].str().size()-2));
    // } else if() { //SELECT

    } else { //SYNTAX ERROR
        std::cout<<"SYNTAX ERROR"<<std::endl;
    }
}

void Lexer::create(std::string table,std::string attributes){
    Type Int(Type::dataType::INT);
    Type Double(Type::dataType::DOUBLE);
    Table t(table);
    std::vector<std::string> v = split(attributes,',');
    std::regex attrparser("");
    for(std::string attr:v){
        std::vector<std::string> comps = split(attr,' ');
        if(comps[1].substr(0,3)=="INT"){
            Attribute att(comps[0], &Int);
        }
    }
}

std::vector<std::string> Lexer::split(std::string s,char ch){
    std::vector<std::string> v;
    std::stringstream ss(s);
    std::string token;
    while(getline(ss,token, ch))
        v.push_back(token);
    return v;
}