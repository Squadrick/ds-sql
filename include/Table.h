//
// Created by squadrick on 3/3/18.
//

#ifndef DS_SQL_TABLE_H
#define DS_SQL_TABLE_H

#include <string>
#include <vector>
#include "Attribute.h"
#include <iostream>


class Table {
public:

    bool serialize();

    int getNumberOfAttributes();

    size_t totalMemorySize;
    std::string name;
    std::vector<void *> attributes;
    std::vector<size_t> startIdx;
    std::vector<size_t > endIdx;

    explicit Table(std::string tableName);

    size_t getMemorySize();

    template<typename T>
    void addAttribute(Attribute<T> att);
};

/*
 * This had to be included here otherwise C++ was being a bitch about it
 */
template<typename T>
void Table::addAttribute(Attribute<T> att) {
    for (auto &attribute : attributes) {
        if (((Attribute<T> *) attribute)->attName == att.attName) {
            std::cerr << ((Attribute<T>*) attribute)->attName << " already exists. Rename the attribute." << std::endl;
            return;
        }
    }

    Table::startIdx.push_back(totalMemorySize);
    totalMemorySize += att.getMemory();
    attributes.push_back(&att);
    Table::endIdx.push_back(totalMemorySize-1);
}

#endif //DS_SQL_TABLE_H
