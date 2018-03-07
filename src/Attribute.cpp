//
// Created by squadrick on 5/3/18.
//

#include "Attribute.h"

Attribute::Attribute(std::string attName, Type attType, Constraint attConstraint) {
    Attribute::attName = std::move(attName);
    Attribute::attType = attType;
    Attribute::attConstraint = std::move(attConstraint);
}

Attribute::Attribute() {
    Attribute::attName = "";
    Attribute::attType = Type();
    Attribute::attConstraint;
}

bool Attribute::serialize() {
    return true;
}

bool Attribute::isValid(const std::string &rawData) {
    return attType.isValid(rawData) && attConstraint.isValid(rawData);
}
