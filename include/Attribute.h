//
// Created by squadrick on 5/3/18.
//

#ifndef DS_SQL_ATTRIBUTE_H
#define DS_SQL_ATTRIBUTE_H

#include "Constraint.h"
#include <string>
#include <iostream>
#include <type_traits>

template<typename T>
class Attribute {
public:
    std::string attName;
    T defVal;
    Constraint<T> attConstraint;
    size_t mem;

    Attribute();

    explicit Attribute(std::string name);

    Attribute(std::string name, Constraint<T> attConstraint);

    bool isValid(T value);

    bool serialize();

    void setDefaultValue(T defaultVal);

    size_t getMemory() {
        return mem;
    };
};

template
class Attribute<int>;

template
class Attribute<double>;

template
class Attribute<std::string>;

#endif //DS_SQL_ATTRIBUTE_H
