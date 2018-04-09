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

#define dir "/home/squadrick/ds-sql/"

class Table {
public:
    explicit Table(std::string tableName);

    Table();

    bool serialize(std::ofstream *file);

    void deserialize(std::ifstream *file);

    size_t getMemorySize();

    void setPrimaryAttribute(Attribute *att);

    void addAttribute(Attribute *att);

    void desc();

    void createTable();

    int operator==(Table other);

    unsigned short totalMemory = 0;
    int primaryKeyIdx = -1;
    int numberOfAttributes = 0;
    int noOfRows = 0;
    std::string name;
    std::string fileName;
    std::vector<Attribute *> attributes;
    std::vector<unsigned int> startIdx, endIdx;
    std::vector<unsigned int> freeList;
    std::unordered_map<std::string, int> attNameToIdx;
};


#endif //DS_SQL_TABLE_H
