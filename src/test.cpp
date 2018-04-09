//
// Created by squadrick on 7/4/18.
//

#include <cassert>
#include "Table.h"
#include "Operations.h"


int main() {

    Table t("table1");
    Type Int(Type::dataType::INT);
    Type Double(Type::dataType::DOUBLE);
    Type String(32, Type::dataType::CHAR);

    Constraint c;
    c.addConstraint("TEST_CONSTRAINT");

    Attribute attribute("test_att", &Int, &c);
    Attribute attribute2("test_att2", &Double, &c);
    Attribute attribute3("dheeraj", &String, &c);
    std::vector<std::string> inVals;
    inVals.emplace_back("123456789");
    inVals.emplace_back("1.25");
    inVals.emplace_back("testfuck");

    t.addAttribute(&attribute);
    t.addAttribute(&attribute2);
    t.addAttribute(&attribute3);
    t.setPrimaryAttribute(&attribute);
    t.createTable();
    Insert::values(&t, inVals);
    Insert::values(&t, inVals);

    std::vector<std::string> inVals1;
    inVals1.emplace_back("987654321");
    inVals1.emplace_back("1.25");
    inVals1.emplace_back("testfuck");



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

    std::cout << t1.noOfRows << std::endl;

    Insert::values(&t1, inVals);
    Insert::values(&t1, inVals);
    Insert::values(&t1, inVals1);
    std::cout << t1.noOfRows << std::endl;
    Select::values(&t1);


}