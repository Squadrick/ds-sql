//
// Created by squadrick on 4/3/18.
//

#ifndef DS_SQL_TYPE_H
#define DS_SQL_TYPE_H

class Type {
public:
    unsigned short int memReq;
    enum dataType {
        INT, DOUBLE, CHA
    };

    Type(unsigned memReq, dataType type);
    bool isValid(std::string rawData);

};

#endif //DS_SQL_TYPE_H
