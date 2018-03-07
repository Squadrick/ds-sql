//
// Created by squadrick on 4/3/18.
//

#ifndef DS_SQL_TYPE_H
#define DS_SQL_TYPE_H

#include <string>
#include <stdexcept>
#include <iostream>

class Type {

public:
    unsigned short int memReq;
    enum dataType {
        INT, DOUBLE, CHAR
    };
    dataType type;


    Type(unsigned short int memReq, dataType type);

    Type();

    bool isValid(std::string rawData);

    bool serialize();
};

#endif //DS_SQL_TYPE_H
