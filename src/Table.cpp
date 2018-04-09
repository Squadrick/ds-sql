//
// Created by squadrick on 3/3/18.
//

#include "Table.h"

Table::Table(std::string tableName) {
    name = std::move(tableName);
    fileName = dir + name + ".ds";
    std::ofstream file(fileName.c_str());
    file.close();
}

Table::Table() = default;

void Table::addAttribute(Attribute *att) {
    if (attNameToIdx.count(att->attName) == 1) {
        std::cerr << att->attName << " already exists. Rename the attribute." << std::endl;
        return;
    }

    startIdx.push_back(totalMemory);
    totalMemory += att->attType->memReq;
    endIdx.push_back((unsigned int) totalMemory - 1);

    attributes.push_back(att);
    attNameToIdx[att->attName] = numberOfAttributes;
    numberOfAttributes++;
}

bool Table::serialize(std::ofstream *file) {
    (*file) << name << std::endl;
    (*file) << std::to_string(primaryKeyIdx) << std::endl;
    (*file) << std::to_string(freeList.size()) << std::endl;

    for (int i = 0; i < freeList.size(); i++) {
        (*file) << std::to_string(freeList[i]) << std::endl;
    }

    (*file) << std::to_string(numberOfAttributes) << std::endl;

    for (int i = 0; i < numberOfAttributes; i++) {
        attributes[i]->serialize(file);
    }
    (*file) << "/table_end" << std::endl;
}


void Table::deserialize(std::ifstream *file) {
    std::string temp;

    getline(*file, name);

    getline(*file, temp);
    primaryKeyIdx = std::stoi(temp);

    getline(*file, temp);
    int iters = std::stoi(temp);
    for (int i = 0; i < iters; i++) {
        getline(*file, temp);
        freeList.push_back((unsigned int) std::stoi(temp));

    }

    getline(*file, temp);
    numberOfAttributes = std::stoi(temp);

    for (int i = 0; i < numberOfAttributes; i++) {
        auto *a = new Attribute();
        a->deserialize(file);
        attributes.push_back(a);
        attNameToIdx.insert(std::make_pair(a->attName, i));
        startIdx.push_back(totalMemory);
        totalMemory += a->attType->memReq;
        endIdx.push_back((unsigned int) totalMemory - 1);
    }

    getline(*file, temp);

    if (temp == "/table_end")
        return;

    std::cerr << "ERROR DESERIALIZING DB STRUCTURE" << std::endl;

}

size_t Table::getMemorySize() {
    return totalMemory;
}

void Table::setPrimaryAttribute(Attribute *att) {

    if (attNameToIdx.count(att->attName) == 0)
        std::cerr << att->attName << " NOT FOUND" << std::endl;
    else if (primaryKeyIdx != -1)
        std::cerr << "PRIMARY ALREADY EXISTS: " << attributes[primaryKeyIdx]->attName << std::endl;
    else
        primaryKeyIdx = attNameToIdx[att->attName];
}

void Table::desc() {
    std::cout << "\nTABLE NAME: " << name << std::endl;
    std::cout << "NO OF ATTRIBUTES: " << numberOfAttributes << std::endl;
    std::cout << "ATTRIBUTES:-" << std::endl;
    for (int i = 0; i < numberOfAttributes; i++) {
        std::cout << "\t";
        attributes[i]->desc();
        if (i == primaryKeyIdx)
            std::cout << "\t\t[PRIMARY KEY]";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Table::createTable() {
    if (primaryKeyIdx == -1) {
        std::cerr << "NO PRIMARY FOR TABLE: " << name << std::endl;
        return;
    }
    std::cout << "TABLE CREATED" << std::endl;
}

int Table::operator==(Table other) {
    int val = totalMemory == other.totalMemory &&
              primaryKeyIdx == other.primaryKeyIdx &&
              numberOfAttributes == other.numberOfAttributes &&
              name == other.name;

    for (int i = 0; i < numberOfAttributes; i++) {
        val = val && ((*attributes[i]) == (*(other.attributes[i])));
    }


    return val;
}

