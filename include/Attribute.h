//
// Created by squadrick on 5/3/18.
//

#ifndef DS_SQL_ATTRIBUTE_H
#define DS_SQL_ATTRIBUTE_H

#include <string>
#include <iostream>
#include <fstream>
#include "Type.h"
#include "Constraint.h"


class Attribute {
public:
    Attribute();

    Attribute(std::string name, Type *attType, Constraint *attConstraint);

    bool isValid(const std::string &rawData);

    void serialize(std::ofstream *file);

    void deserialize(std::ifstream *file);

    void desc();

    int operator==(Attribute other);

    bool isInt();
    bool isDouble();
    bool isChar();

    std::string attName;
    Type *attType;
    Constraint *attConstraint;
};

#endif //DS_SQL_ATTRIBUTE_H
