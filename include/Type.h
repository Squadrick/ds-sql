//
// Created by squadrick on 4/3/18.
//

#ifndef DS_SQL_TYPE_H
#define DS_SQL_TYPE_H

#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>

class Type {

public:
    enum dataType {
        INT, DOUBLE, CHAR
    };
    dataType type;

    Type(unsigned short int memReq, dataType type);

    explicit Type(dataType type);

    Type();

    unsigned short getSize(dataType type);

    std::string getName();

    dataType getType(std::string name);

    bool isValid(std::string rawData);

    void desc();

    void serialize(std::ofstream *file);

    void deserialize(std::ifstream *file);

    int operator==(Type other);

    unsigned short int memReq;
    std::string typeNames[3] = {"INT", "DOUBLE", "CHAR"};

};

#endif //DS_SQL_TYPE_H
