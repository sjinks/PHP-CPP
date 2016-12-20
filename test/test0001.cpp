#include "test0001.h"

static Php::Value my_add(Php::Parameters& params)
{
    Php::Value r(0);

    for (unsigned int i=0; i<params.size(); ++i) {
        r += params[i];
    }

    return r;
}

void init_Test0001(Php::Extension& e)
{
    e.add<my_add>("my_add");
}
