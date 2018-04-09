//
// Created by squadrick on 5/3/18.
//

#include <iostream>
#include "Constraint.h"

void Constraint::addConstraint(std::string rawData) {
    // parse rawData using lexer
    auto f = [](std::string data) -> bool {
        return data.size() > 5;
    };
    rawConsCode.push_back(rawData);
    checkers.emplace_back((checker) {f, "error, length of data should be more than 5"});
}

bool Constraint::isValid(std::string rawData) {
    for (auto &checker : checkers)
        if (!checker.func(rawData)) {

            std::cerr << checker.errorMessage << std::endl;
            return false;
        }
    return true;
}


void Constraint::serialize(std::ofstream *file) {
    (*file) << std::to_string(rawConsCode.size()) << std::endl;
    for(int i = 0; i < rawConsCode.size(); i++) {
        (*file) << rawConsCode[i] << std::endl;
        (*file) << checkers[i].errorMessage << std::endl;
    }
    (*file) << "/cons_end" << std::endl;
}

void Constraint::deserialize(std::ifstream *file) {
    std::string temp;
    std::getline(*file, temp);
    int n = std::stoi(temp);

    for(int i = 0; i < n; i++) {
        std::getline(*file, temp);
        rawConsCode.push_back(temp);
        //auto f = lex(temp);
        auto f = [](std::string data) -> bool {
            return data.size() > 5;
        };
        std::getline(*file, temp);
        checkers.push_back((checker) {f, temp});
    }

    std::getline(*file, temp);
    if(temp == "/cons_end")
        return;
    std::cerr << "ERROR DESERIALIZING DB STRUCTURE" << std::endl;
}

int Constraint::operator==(Constraint other) {
    int val = rawConsCode.size() == other.rawConsCode.size();
    for(int i = 0; i < rawConsCode.size(); i++) {
        val = val && (rawConsCode[i] == other.rawConsCode[i])
                && (checkers[i].errorMessage == other.checkers[i].errorMessage);
    }
    return val;
}
