//
// Created by squadrick on 7/4/18.
//

#include <cassert>
#include "Table.h"


int main() {

    Table t("test");
    Type Int(Type::dataType::INT);
    Type Double(Type::dataType::DOUBLE);
    Type String(Type::dataType::CHAR);

    Constraint c;
    c.addConstraint("TEST_CONSTRAINT");

    Attribute attribute("test_att", &Int, &c);
    Attribute attribute2("test_att2", &Int, &c);
    Attribute attribute3("dheeraj", &String, &c);
    Attribute attribute4("dheeraj", &Double, &c);

    t.addAttribute(&attribute);
    t.addAttribute(&attribute2);
    t.addAttribute(&attribute3);
    t.addAttribute(&attribute4);
    t.setPrimaryAttribute(&attribute);
    t.createTable();

    std::ofstream o;
    o.open("/home/squadrick/ds-sql/test.txt");
    t.serialize(&o);
    o.close();

    std::ifstream i;
    i.open("/home/squadrick/ds-sql/test.txt");

    Table t1("temp");
    t1.deserialize(&i);
    t1.createTable();
    i.close();

    assert(t == t1);
    Attribute attribute5("ttt", &Double, &c);
    t1.addAttribute(&attribute5);
    t1.setPrimaryAttribute(&attribute5);
    assert(!(t == t1));

}