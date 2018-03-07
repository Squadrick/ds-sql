//
// Created by squadrick on 3/3/18.
//

#include "Table.h"

Table::Table(std::string tableName) {
    Table::name = std::move(tableName);
}

void Table::addAttribute(Attribute att) {
    for (auto &attribute : attributes)
        if (attribute.attName == att.attName) {
            std::cerr << attribute.attName << " already exists. Rename the attribute." << std::endl;
            return;
        }
    attributes.push_back(att);
}

bool Table::serialize() {
    return true;
}

int Table::getNumberOfAttributes() {
    return static_cast<int>(Table::attributes.size());
}

size_t Table::getMemorySize() {
    size_t totalMemory = 0;
    for (auto &attribute : attributes)
        totalMemory += attribute.attType.memReq;
    return totalMemory;
}

