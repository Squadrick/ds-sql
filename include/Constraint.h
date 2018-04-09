//
// Created by squadrick on 4/3/18.
//

#ifndef DS_SQL_CONSTRAINT_H
#define DS_SQL_CONSTRAINT_H

#include <iostream>
#include <fstream>
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
<<<<<<< HEAD
    std::vector<Checker> checkers;
=======
    std::vector<checker> checkers;
    std::vector<std::string> rawConsCode;
>>>>>>> 292a26a... Replace Type with templates

    bool isValid(T rawData);

    void addConstraint(Constraint<T>::Checker);

    void serialize(std::ofstream *file);

<<<<<<< HEAD
=======
    void deserialize(std::ifstream *file);

    int operator==(Constraint other);
>>>>>>> 292a26a... Replace Type with templates
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
