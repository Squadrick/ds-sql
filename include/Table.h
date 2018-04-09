//
// Created by squadrick on 3/3/18.
//

#ifndef DS_SQL_TABLE_H
#define DS_SQL_TABLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include "Attribute.h"
#include <iostream>


class Table {
public:

    bool serialize(std::ofstream *file);

    void deserialize(std::ifstream *file);

<<<<<<< HEAD
    size_t totalMemorySize;
    std::string name;
    std::vector<void *> attributes;
    std::vector<size_t> startIdx;
    std::vector<size_t > endIdx;

    explicit Table(std::string tableName);

    size_t getMemorySize();

    template<typename T>
    void addAttribute(Attribute<T> att);
=======
    size_t getMemorySize();

    void setPrimaryAttribute(Attribute *att);

    void addAttribute(Attribute *att);

    void desc();

    void createTable();

    int operator==(Table other);

    unsigned short totalMemory = 0;
    int primaryKeyIdx = -1;
    int numberOfAttributes = 0;
    std::string name;
    std::vector<Attribute *> attributes;
    std::vector<unsigned int> startIdx, endIdx;
    std::vector<unsigned int> freeList;
    std::unordered_map<std::string, int> attNameToIdx;
>>>>>>> 292a26a... Replace Type with templates
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
