#include <vector>
#include "issue114.h"

static Php::Value test114(Php::Parameters& p)
{
    int count = p[0].size();
    std::vector<Php::Value> v;
    for (int i = 0; i<count; ++i) {
        v.push_back(p[0][i]);
    }

    return v;
}

void init_Issue114(Php::Extension& e)
{
    e.add<test114>("test114");
}
