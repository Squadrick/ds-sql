//
// Created by squadrick on 8/4/18.
//

#ifndef DS_SQL_CURSOR_H
#define DS_SQL_CURSOR_H

#include "Table.h"
#include <fstream>

class Cursor {

    Table *table;

    std::ifstream f;

    Cursor(Table *t);

    unsigned int getFreLocation() {
        return table->freeList.erase(table->freeList.begin());
    }


};

#endif //DS_SQL_CURSOR_H
