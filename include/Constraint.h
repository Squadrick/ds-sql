//
// Created by squadrick on 4/3/18.
//

#ifndef DS_SQL_CONSTRAINT_H
#define DS_SQL_CONSTRAINT_H

#include<vector>
#include <functional>

class Constraint {
    std::vector<std::function<bool()>> checkers;
    bool isValid(std::string rawData);

    void addConstraint(std::function<bool()> func);

};
#endif //DS_SQL_CONSTRAINT_H
