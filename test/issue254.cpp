#include <ostream>
#include "issue254.h"

static void test254()
{
    Php::Value a;
    a["b"]["c"] = "a[\"b\"][\"c\"]";
    Php::out << a["b"]["c"] << std::endl;
    a["d"] = Php::Array();
    Php::array_push(a["d"], "0");
    Php::array_push(a["d"], "1");
    Php::out << a["d"][0] << std::endl;
    Php::out << a["d"][1] << std::endl;
}


void init_Issue254(Php::Extension& e)
{
    e.add<test254>("test254");
}
