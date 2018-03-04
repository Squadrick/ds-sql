//
// Created by squadrick on 3/3/18.
//

#ifndef DS_SQL_TABLE_H
#define DS_SQL_TABLE_H

#include <string>
#include <vector>
#include "Type.h"
#include "Constraint.h"


class Table {
public:

    struct Attribute {
        std::string attName;
        Type attType;
        Constraint attConstraint;
    };

    Table(string tableName);

    ~Table();

    void addAttribute(Attribute att);

    std::string name;
    std::vector<Attribute> attributes;
};


#endif //DS_SQL_TABLE_H

