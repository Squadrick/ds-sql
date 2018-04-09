//
// Created by squadrick on 8/4/18.
//

#ifndef DS_SQL_INSERT_H
#define DS_SQL_INSERT_H

#include "Table.h"
#include "Cursor.h"
#include <fstream>
#include <cstring>

namespace Insert {
    void values(Table *table, std::vector<std::string> rawVals) {

        if (rawVals.size() != table->numberOfAttributes) {
            std::cerr << "NUMBER OF INSERT VALUES NOT EQUAL TO NUMBER OF ATTRIBUTES" << std::endl;
        }

        for (int i = 0; i < table->numberOfAttributes; i++) {
            if (!table->attributes[i]->isValid(rawVals[i])) {
                std::cerr << "INSERTION FAILED" << std::endl;
            }
        }

        Cursor c(table);

        auto *buffer = (char *) malloc(table->totalMemory);

        for (int i = 0; i < table->noOfRows; i++) {
            void *buffer = c.getValues(i);
            auto *at = table->attributes[table->primaryKeyIdx];
            auto *tempBuffer = (unsigned char *) malloc(at->attType->memReq);
            std::memcpy(tempBuffer, buffer + table->startIdx[table->primaryKeyIdx], at->attType->memReq);
            if (at->isInt()) {
                int val;
                memcpy(&val, tempBuffer, at->attType->memReq);
                if (std::stoi(rawVals[table->primaryKeyIdx]) == val) {
                    std::cerr << "PRIMARY KEY CONSTRAINT FAILED: " << val << std::endl;
                    return;
                }
            } else if (at->isDouble()) {
                double val;
                memcpy(&val, tempBuffer, at->attType->memReq);
                if (std::stod(rawVals[table->primaryKeyIdx]) == val) {
                    std::cerr << "PRIMARY KEY CONSTRAINT FAILED: " << val << std::endl;
                    return;
                }
            } else if (at->isChar()) {
                if (rawVals[table->primaryKeyIdx] == std::string((char *) tempBuffer)) {
                    std::cerr << "PRIMARY KEY CONSTRAINT FAILED: " << tempBuffer << std::endl;
                    return;
                }
            }
        }

        for (int i = 0; i < table->numberOfAttributes; i++) {
            Attribute *at = table->attributes[i];
            if (at->isInt()) {
                int val = std::stoi(rawVals[i]);
                std::memcpy(buffer + table->startIdx[i], &val, at->attType->memReq);
            } else if (at->isDouble()) {
                double val = std::stod(rawVals[i]);
                std::memcpy(buffer + table->startIdx[i], &val, at->attType->memReq);
            } else {
                auto *arr = (char *) rawVals[i].c_str();
                if (at->attType->memReq > rawVals[i].size()) {
                    std::memcpy(buffer + table->startIdx[i], arr, rawVals[i].size());
                    std::memset(buffer + table->startIdx[i] + rawVals[i].size(), 0,
                                at->attType->memReq - rawVals[i].size());
                }

            }
        }
        c.insertValues(buffer);
        free(buffer);
    }
}

namespace Select {
    void values(Table *table) {
        Cursor c(table);

        for (int i = 0; i < table->noOfRows; i++) {
            void *buffer = c.getValues(i);

            for (int j = 0; j < table->numberOfAttributes; j++) {
                auto *at = table->attributes[j];
                auto *tempBuffer = (unsigned char *) malloc(at->attType->memReq);
                std::memcpy(tempBuffer, buffer + table->startIdx[j], at->attType->memReq);
                if (at->isInt()) {
                    int val;
                    std::memcpy(&val, tempBuffer, sizeof(int));
                    std::cout << val << "\t";
                } else if (at->isDouble()) {
                    double val;
                    std::memcpy(&val, tempBuffer, sizeof(double));
                    std::cout << val << "\t";
                } else if (at->isChar()) {
                    std::cout << tempBuffer << "\t";
                }
                free(tempBuffer);
            }
            std::cout << std::endl;
            free(buffer);
        }
    }
}
#endif //DS_SQL_INSERT_H
