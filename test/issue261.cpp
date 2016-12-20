#include "issue261.h"

static void swap(Php::Parameters& params)
{
    Php::Value temp = params[0];
    params[0] = params[1];
    params[1] = temp;
}

void init_Issue261(Php::Extension& e)
{
    e.add<swap>("swap", {
        Php::ByRef("a", Php::Type::Numeric),
        Php::ByRef("b", Php::Type::Numeric)
    });
}
