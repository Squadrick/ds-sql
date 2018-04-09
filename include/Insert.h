//
// Created by squadrick on 8/4/18.
//

#ifndef DS_SQL_INSERT_H
#define DS_SQL_INSERT_H

#include "Table.h"
#include "Cursor.h"
#include <fstream>

void values(Table *table, std::vector<std::string> rawVals) {
    // use a cursor to file included in Table -- Cursor c(table);
    // ensure cast(rawVals[table->primIdx]) != c.getRow(j)[i] for all j not in free-list
    // Insert casted rawVals at position c.getFreeLoc
    // Close file and writing to disk

    if(rawVals.size() != table->numberOfAttributes) {
        std::cerr << "NUMBER OF INSERT VALUES NOT EQUAL TO NUMBER OF ATTRIBUTES" << std::endl;
    }

    for(int i = 0; i < table->numberOfAttributes; i++) {
        if(!table->attributes[i]->isValid(rawVals[i])) {
            std::cerr << "INSERTION FAILED" << std::endl;
        }
    }

    Cursor c(table);


}

#endif //DS_SQL_INSERT_H
