#include <ostream>
#include "issue254.h"

static void test254()
{
    Php::Value a;
    a["b"]["c"] = "a[\"b\"][\"c\"]";
    Php::out << a["b"]["c"] << std::endl;
    Php::Value d = Php::Array();
    d.setReferenceFlag(true);
    Php::array_push(d, "0");
    Php::array_push(d, "1");
    a["d"] = d;
    Php::out << a["d"][0] << std::endl;
    Php::out << a["d"][1] << std::endl;
}


void init_Issue254(Php::Extension& e)
{
    e.add<test254>("test254");
}
