//
// Created by squadrick on 7/4/18.
//

#include <cassert>
#include "Table.h"
#include "Insert.h"


int main() {

    Table t("test");
    Type Int(Type::dataType::INT);
    Type Double(Type::dataType::DOUBLE);
    Type String(Type::dataType::CHAR);

    Constraint c;
    c.addConstraint("TEST_CONSTRAINT");

    Attribute attribute("test_att", &Int, &c);
    Attribute attribute2("test_att2", &Double, &c);
    Attribute attribute3("dheeraj", &String, &c);


    t.addAttribute(&attribute);
    t.addAttribute(&attribute2);
    t.addAttribute(&attribute3);
    t.setPrimaryAttribute(&attribute);
    t.createTable();

    std::ofstream o;
    o.open("/home/squadrick/ds-sql/test.ds-meta");
    t.serialize(&o);
    o.close();

    std::ifstream i;
    i.open("/home/squadrick/ds-sql/test.ds-meta");

    Table t1;
    t1.deserialize(&i);
    t1.createTable();
    i.close();

    assert(t == t1);
    Attribute attribute5("ttt", &Double, &c);
    t1.addAttribute(&attribute5);
    t1.setPrimaryAttribute(&attribute5);
    assert(!(t == t1));

    std::vector<std::string> inVals;
    inVals.emplace_back("1");
    inVals.emplace_back("1.25");
    inVals.emplace_back("testing");
    values(&t, inVals);
}