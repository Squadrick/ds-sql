//
// Created by squadrick on 5/3/18.
//

#include "Attribute.h"

Attribute::Attribute(std::string attName, Type *attType, Constraint *attConstraint) {
    Attribute::attName = std::move(attName);
    Attribute::attType = attType;
    //Attribute::attConstraint = attConstraint;
}

Attribute::Attribute() {
    Attribute::attName = "";
    Attribute::attType = nullptr;
    //Attribute::attConstraint = nullptr;
}

bool Attribute::isValid(const std::string &rawData) {
    return attType->isValid(rawData);// && attConstraint->isValid(rawData);
}

void Attribute::desc() {
    std::cout << attName << "\t";
    attType->desc();
}

void Attribute::serialize(std::ofstream *file) {
    (*file) << attName << std::endl;
    attType->serialize(file);
    //  attConstraint->serialize(file);
    (*file) << "/att_end" << std::endl;
}

void Attribute::deserialize(std::ifstream *file) {
    std::string temp;
    std::getline(*file, temp);
    attName = std::move(temp);

    auto *t = new Type();
    t->deserialize(file);
    attType = t;

//    auto *c = new Constraint();
//    c->deserialize(file);
    //  attConstraint = c;

    getline(*file, temp);
    if (temp == "/att_end")
        return;
    std::cerr << "ERROR DESERIALIZING DB STRUCTURE" << std::endl;
}

int Attribute::operator==(Attribute other) {
    return attName == other.attName &&
           *attType == *(other.attType);
    //*attConstraint == *(other.attConstraint);
}

bool Attribute::isInt() {
    return attType->type == Type::dataType::INT;
}

bool Attribute::isDouble() {
    return attType->type == Type::dataType::DOUBLE;
}

bool Attribute::isChar() {
    return attType->type == Type::dataType::CHAR;
}

