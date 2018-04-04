//
// Created by squadrick on 3/3/18.
//

#include "Table.h"

Table::Table(std::string tableName) {
    Table::name = std::move(tableName);
    totalMemorySize = 0;
}


bool Table::serialize() {
    return true;
}

int Table::getNumberOfAttributes() {
    return static_cast<int>(Table::attributes.size());
}

size_t Table::getMemorySize() {
    return totalMemorySize;
}

