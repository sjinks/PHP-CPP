#include <string>
#include "test0007.h"

static void test7_define()
{
    Php::define("ROSE", "red");
    Php::define(std::string("VIOLET"), "blue");
}

static Php::Value test7_defined()
{
    Php::Array res;
    res[0] = Php::defined("ROSE");
    res[1] = Php::defined(std::string("VIOLET"));
    return res;
}

static Php::Value test7_constant()
{
    Php::Array res;
    res[0] = Php::constant("ROSE");
    res[1] = Php::constant(std::string("VIOLET"));
    return res;
}

static void test7_defineConstant(Php::Parameters& p)
{
    std::string name = p[0].stringValue();
    Php::define(name, p[1]);
}

static Php::Value test7_constantDefined(Php::Parameters& p)
{
    std::string name = p[0].stringValue();
    return Php::defined(name);
}

static Php::Value test7_getConstant(Php::Parameters& p)
{
    std::string name = p[0].stringValue();
    return Php::constant(name);
}

void init_Test0007(Php::Extension& e)
{
    e.add<test7_define>("test7_define");
    e.add<test7_defined>("test7_defined");
    e.add<test7_constant>("test7_constant");
    e.add<test7_defineConstant>("test7_defineConstant", { Php::ByVal("name", Php::Type::String), Php::ByVal("value") });
    e.add<test7_constantDefined>("test7_constantDefined", { Php::ByVal("name", Php::Type::String) });
    e.add<test7_getConstant>("test7_getConstant", { Php::ByVal("name", Php::Type::String) });
}
