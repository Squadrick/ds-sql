//
// Created by squadrick on 5/3/18.
//

#ifndef DS_SQL_ATTRIBUTE_H
#define DS_SQL_ATTRIBUTE_H

#include "Type.h"
#include "Constraint.h"
#include <string>

class Attribute {
public:
    std::string attName;
    Type attType;
    Constraint attConstraint;


    Attribute();

    Attribute(std::string name, Type attType, Constraint attConstraint);

    bool serialize();

    bool isValid(const std::string &rawData);
};

#endif //DS_SQL_ATTRIBUTE_H
