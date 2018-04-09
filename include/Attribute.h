//
// Created by squadrick on 5/3/18.
//

#ifndef DS_SQL_ATTRIBUTE_H
#define DS_SQL_ATTRIBUTE_H

<<<<<<< HEAD
#include "Constraint.h"
#include <string>
#include <iostream>
#include <type_traits>
=======
#include <string>
#include <iostream>
#include <fstream>
#include "Type.h"
#include "Constraint.h"

>>>>>>> 292a26a... Replace Type with templates

template<typename T>
class Attribute {
public:
<<<<<<< HEAD
    std::string attName;
    T defVal;
    Constraint<T> attConstraint;
    size_t mem;
=======
    Attribute();

    Attribute(std::string name, Type *attType, Constraint *attConstraint);
>>>>>>> 292a26a... Replace Type with templates

    bool isValid(const std::string &rawData);

<<<<<<< HEAD
    explicit Attribute(std::string name);

    Attribute(std::string name, Constraint<T> attConstraint);

    bool isValid(T value);
=======
    void serialize(std::ofstream *file);
>>>>>>> 292a26a... Replace Type with templates

    void deserialize(std::ifstream *file);

<<<<<<< HEAD
    void setDefaultValue(T defaultVal);

    size_t getMemory() {
        return mem;
    };
=======
    void desc();

    int operator==(Attribute other);

    std::string attName;
    Type *attType;
    Constraint *attConstraint;
>>>>>>> 292a26a... Replace Type with templates
};

template
class Attribute<int>;

template
class Attribute<double>;

template
class Attribute<std::string>;

#endif //DS_SQL_ATTRIBUTE_H
