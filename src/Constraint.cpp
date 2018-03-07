//
// Created by squadrick on 5/3/18.
//

#include <iostream>
#include "Constraint.h"

void Constraint::addConstraint(std::string rawData) {
    // parse raw data using lexer
    auto f = [](std::string data) -> bool {
        return data.size() > 5;
    };

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

bool Constraint::serialize() {
    return false;
}

Constraint::checker Constraint::buildFunction(std::string rawData) {

}
