#include "issue273.h"

static Php::Value test273(Php::Parameters& params)
{
    return nullptr;
}

void init_Issue273(Php::Extension& e)
{
    e.add<test273>("test273");
}
