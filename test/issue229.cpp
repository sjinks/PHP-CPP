#include "issue229.h"

static Php::Value test229_get(Php::Parameters& p)
{
    std::string key = p[0].stringValue();
    return Php::REQUEST[key];
}

static Php::Value test229_get2(Php::Parameters& p)
{
    std::string key = p[0].stringValue();
    Php::Value v = Php::REQUEST[key];
    Php::Value x = Php::REQUEST[key];
    x = x + x;
    return v;
}

static void test229_set(Php::Parameters& p)
{
    std::string key   = p[0].stringValue();
//    Php::REQUEST[key] = p[1];
    Php::Value x = Php::REQUEST[key];
    x = p[1];
}

void init_Issue229(Php::Extension& e)
{
    e.add<test229_get>("test229_get",   { Php::ByVal("key", Php::Type::String) });
    e.add<test229_get2>("test229_get2", { Php::ByVal("key", Php::Type::String) });
    e.add<test229_set>("test229_set",   { Php::ByVal("key", Php::Type::String), Php::ByVal("value") });
}
