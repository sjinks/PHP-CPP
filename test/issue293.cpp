#include <ostream>
#include "issue293.h"

static void test293(Php::Parameters& p)
{
    Php::Value v = p[0];
    int type     = p[1].numericValue();

    switch (type) {
        case 0:
            Php::out << v.numericValue() << " " << p[0].numericValue() << std::endl;
            break;

        case 1:
            Php::out << v.floatValue() << " " << p[0].floatValue() << std::endl;
            break;

        case 2:
            Php::out << v.stringValue() << " " << p[0].stringValue() << std::endl;
            break;
    }
}

void init_Issue293(Php::Extension& e)
{
    e.add<test293>("test293", {
        Php::ByRef("a"),
        Php::ByVal("type", Php::Type::Numeric)
    });
}
