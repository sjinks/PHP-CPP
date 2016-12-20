#include "issue234.h"

static void test234_setglobal(Php::Parameters& p)
{
    std::string name = p[0].stringValue();
    Php::Value  val  = p[1];

    Php::GLOBALS[name] = val;
}

static Php::Value test234_getglobal(Php::Parameters& p)
{
    std::string name = p[0].stringValue();
    return Php::GLOBALS[name];
}

void init_Issue234(Php::Extension& e)
{
    e.add<test234_setglobal>(
        "test234_setglobal",
        {
            Php::ByVal("name",  Php::Type::String),
            Php::ByVal("value")
        }
    );

    e.add<test234_getglobal>(
        "test234_getglobal",
        {
            Php::ByVal("name",  Php::Type::String)
        }
    );
}
