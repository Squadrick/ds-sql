//
// Created by squadrick on 4/3/18.
//

#ifndef DS_SQL_CONSTRAINT_H
#define DS_SQL_CONSTRAINT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>

class Constraint {

public:
    struct checker {
        std::function<bool(std::string)> func;
        std::string errorMessage;
    };
    std::vector<checker> checkers;
    std::vector<std::string> rawConsCode;

    bool isValid(std::string rawData);

    void addConstraint(std::string rawData);

    void serialize(std::ofstream *file);

    void deserialize(std::ifstream *file);

    int operator==(Constraint other);
};

#endif //DS_SQL_CONSTRAINT_H
