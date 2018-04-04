//
// Created by squadrick on 4/3/18.
//

#ifndef DS_SQL_CONSTRAINT_H
#define DS_SQL_CONSTRAINT_H

#include <vector>
#include <functional>
#include <iostream>

template<typename T>
class Constraint {

public:

    struct Checker {
        std::function<bool(T)> func;
        std::string errorMessage;
    };
    std::vector<Checker> checkers;

    bool isValid(T rawData);

    void addConstraint(Constraint<T>::Checker);

    bool serialize();

};

template<typename T>
void Constraint<T>::addConstraint(Constraint<T>::Checker checker) {
    checkers.emplace_back(checker);
}

template<typename T>
bool Constraint<T>::isValid(T rawData) {
    for (auto &checker: checkers)
        if (!checker.func(rawData)) {
            std::cerr << checker.errorMessage << std::endl;
            return false;
        }
    return true;
}

template<typename T>
bool Constraint<T>::serialize() {
    return false;
}

#endif //DS_SQL_CONSTRAINT_H
