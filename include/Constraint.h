//
// Created by squadrick on 4/3/18.
//

#ifndef DS_SQL_CONSTRAINT_H
#define DS_SQL_CONSTRAINT_H

#include <vector>
#include <functional>

class Constraint {

public:
    struct checker {
        std::function<bool(std::string)> func;
        std::string errorMessage;
    };
    std::vector<checker> checkers;

    bool isValid(std::string rawData);

    void addConstraint(std::string rawData);

    bool serialize();

    checker buildFunction(std::string rawData);
};

#endif //DS_SQL_CONSTRAINT_H
