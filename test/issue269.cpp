#include <ostream>
#include "issue269.h"

static void test269(Php::Parameters& params)
{
    Php::Value obj = params[0];
    Php::out << obj["test"] << std::endl;
}

void init_Issue269(Php::Extension& e)
{
    e.add<test269>("test269", {
        Php::ByRef("obj", Php::Type::Null, false)
    });
}
