//
// Created by squadrick on 8/4/18.
//

#ifndef DS_SQL_CURSOR_H
#define DS_SQL_CURSOR_H

#include "Table.h"
#include <fstream>
#include <cstdlib>
#include <iostream>

class Cursor {
    Table *table;

    std::fstream f;
public:


    explicit Cursor(Table *t);
    ~Cursor();
    unsigned int moveToFreeLocation();

    void insertValues(void *);

    void deleteValues(int pos);
    void *getValues(int pos);

    void *index;
};

#endif //DS_SQL_CURSOR_H
