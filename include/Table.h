//
// Created by squadrick on 3/3/18.
//

#ifndef DS_SQL_TABLE_H
#define DS_SQL_TABLE_H

#include <string>
#include <vector>
#include "Attribute.h"


class Table {
public:
    explicit Table(std::string tableName);

    bool serialize();

    int getNumberOfAttributes();

    size_t getMemorySize();
    void addAttribute(Attribute att);

    std::string name;
    std::vector<Attribute> attributes;

};


#endif //DS_SQL_TABLE_H
