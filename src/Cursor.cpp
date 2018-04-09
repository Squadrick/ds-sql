//
// Created by squadrick on 9/4/18.
//

#include <cstring>

#include "Cursor.h"

Cursor::Cursor(Table *t) : table(t) {
    f.open(t->fileName, std::ios::out | std::ios::in | std::ios::binary);
    f.clear();
    f.seekg(0, f.end);
}


unsigned int Cursor::moveToFreeLocation() {
    if(!table->freeList.empty())
        return table->freeList.erase(table->freeList.begin())[0];
    else
        return static_cast<unsigned int>(-1);
}

void *Cursor::getValues(int pos) {
    void *values = malloc(table->totalMemory);
    int start = pos * table->totalMemory;
    f.seekg(start, f.beg);
    f.read((char*)values, table->totalMemory);
    return values;
}

void Cursor::Cursor::insertValues(void *values) {
    int pos = moveToFreeLocation();
    if(pos == -1) // no deletions yet
        f.seekp(0, f.end);
    else
        f.seekp(pos * table->totalMemory, f.beg);
    f.write((char*)values, table->totalMemory);
}

void Cursor::deleteValues(int pos) {
    table->freeList.push_back((unsigned int) pos);
}

Cursor::~Cursor() {
    f.close();
}
