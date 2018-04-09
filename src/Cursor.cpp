//
// Created by squadrick on 9/4/18.
//

#include <cstring>

#include "Cursor.h"

Cursor::Cursor(Table *t) : table(t) {
    f.open(t->fileName, std::ios::out | std::ios::in | std::ios::binary | std::ios::app);
}


unsigned int Cursor::moveToFreeLocation() {
    if (!table->freeList.empty())
        return table->freeList.erase(table->freeList.begin())[0];
    else
        return static_cast<unsigned int>(-1);
}

void *Cursor::getValues(int pos) {
    void *values = malloc(table->totalMemory);
    int start = pos * table->totalMemory;
    f.seekg(start, f.beg);
    std::cout << "FILE POS1 " << f.tellg() << std::endl;
    f.read((char *) values, table->totalMemory);
    std::cout << "FILE POS2 " << f.tellg() << std::endl;
    return values;
}

void Cursor::Cursor::insertValues(void *values) {
    int pos = moveToFreeLocation();
    if (pos == -1) // no deletions yet
    {
        f.seekp(table->noOfRows*table->totalMemory, f.beg);

        table->noOfRows++;
    } else
        f.seekp(pos * table->totalMemory, f.beg);
    f.write((char *) values, table->totalMemory);
}

void Cursor::deleteValues(int pos) {
    table->freeList.push_back((unsigned int) pos);
}

Cursor::~Cursor() {
    f.close();
}
