//
// Created by squadrick on 5/4/18.
//

#ifndef DS_SQL_VALUE_H
#define DS_SQL_VALUE_H

#include "Type.h"
#include <string>

class Value
{
    Type type;
    void *data;


    Type(void *data, Type type);

    void getInt(int&);
    void getDouble(double&);
    void getString(std::string&);

};
#endif //DS_SQL_VALUE_H
