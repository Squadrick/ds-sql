//
// Created by squadrick on 5/3/18.
//

#include "Attribute.h"

template<typename T>
Attribute<T>::Attribute(std::string attName, Constraint<T> attConstraint) {
    Attribute::attConstraint = std::move(attConstraint);
    Attribute::attName = std::move(attName);
    Attribute::mem = sizeof(T);
}

template<typename T>
Attribute<T>::Attribute(std::string name) {
    Attribute::attName = std::move(name);
    Attribute::mem = sizeof(T);
}

template<typename T>
Attribute<T>::Attribute() {
    Attribute::mem = sizeof(T);
}

template<typename T>
bool Attribute<T>::serialize() {
    return true;
}

template<typename T>
void Attribute<T>::setDefaultValue(T defaultVal) {
    Attribute::defVal = defaultVal;
}

template<typename T>
bool Attribute<T>::isValid(T value) {
    return attConstraint.isValid(value);
}




