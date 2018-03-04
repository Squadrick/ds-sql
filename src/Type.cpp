//
// Created by squadrick on 4/3/18.
//

#include "Type.h"

Type::Type(unsigned short int memReq, dataType type) {
    Type::memReq = memReq;
    Type::type = type;
}

bool Type::isValid(std::string rawData) {

    switch (Type::type) {

        case INT:
            try { stoi(rawData); }
            catch (const std::invalid_argument &ia) {
                std::cerr << "Invalid argument: Expected INT but got CHAR type \n";
                return false;
            }
            if (stoi(rawData) != stof(rawData)) {
                std::cerr << "Invalid argument: Expected INT but got DOUBLE type \n";
                return false;
            }
            break;
        case DOUBLE:
            try { stof(rawData); }
            catch (const std::invalid_argument &ia) {
                std::cerr << "Invalid argument: Expected DOUBLE but got CHAR type \n";
                return false;
            }
            break;
    }
    return true;

}

int main() {
    Type::dataType ty = Type::dataType::INT;
    Type t(15, ty);
    t.isValid("13.4");
}