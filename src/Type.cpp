//
// Created by squadrick on 4/3/18.
//

#include "Type.h"

Type::Type(unsigned short int memReq, dataType type) {
    Type::memReq = memReq;
    Type::type = type;
}

Type::Type(dataType type) {
    Type::memReq = getSize(type);
    Type::type = type;
}

bool Type::isValid(std::string rawData) {

    switch (Type::type) {

        case INT:
            try { stoi(rawData); }
            catch (const std::invalid_argument &ia) {
                std::cerr << "Invalid type: Expected INT but got STRING type \n";
                return false;
            }
            if (stoi(rawData) != stof(rawData)) {
                std::cerr << "Invalid type: Expected INT but got DOUBLE type \n";
                return false;
            }
            break;
        case DOUBLE:
            try { stof(rawData); }
            catch (const std::invalid_argument &ia) {
                std::cerr << "Invalid type: Expected DOUBLE but got STRING type \n";
                return false;
            }
            break;
    }
    return true;
}

Type::Type() {
    Type::memReq = 0;
    Type::type = Type::dataType::CHAR;
}

unsigned short Type::getSize(dataType type) {
    switch (type)
    {
        case INT: return 4;
        case DOUBLE: return 8;
    }
}

std::string Type::getName() {
//    switch (Type::type)
//    {
//        case Type::dataType::INT: return "INT";
//        case Type::dataType::DOUBLE: return "DOUBLE";
//        case Type::dataType::CHAR: return "CHAR";
//    }
    return typeNames[Type::type];
}

Type::dataType Type::getType(std::string name) {
    if(name == "INT")
        return dataType::INT;
    else if(name == "DOUBLE")
        return dataType::DOUBLE;
    else if(name == "CHAR")
        return dataType::CHAR;
}

void Type::desc() {
    std::cout << getName();
}

void Type::serialize(std::ofstream *file) {
    (*file) << getName() << std::endl;
    (*file) << memReq << std::endl;
    (*file) << "/type_end" << std::endl;
}

void Type::deserialize(std::ifstream *file) {
    std::string temp;

    getline(*file, temp);
    Type::type = getType(temp);

    getline(*file, temp);
    memReq = (unsigned short)std::stoi(temp);

    getline(*file, temp);
    if(temp == "/type_end")
        return;

    std::cerr << "ERROR DESERIALIZING DB STRUCTURE" << std::endl;
}

int Type::operator==(Type other) {
    return type == other.type &&
            memReq == other.memReq;
}
