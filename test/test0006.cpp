#include <main/php.h>
#include <ostream>
#include "test0006.h"

static void test0006_1(Php::Parameters& p)
{
    {
        Php::Value a = 5;
        a.setReferenceFlag(true);
        Php::out << a.debugZval() << std::endl;

        Php::Value b = Php::Value::makeReference(Php::call("returnByReference", a));

        Php::out << a << " " << b << std::endl;
        b = b + 1.0;
        Php::out << a << " " << b << std::endl;
        b = b + 1.0;
        Php::out << a << " " << b << std::endl;
    }

    Php::out << std::endl;

    {
        Php::Value a = 5;
        a.setReferenceFlag(true);
        Php::out << a.debugZval() << std::endl;

        Php::Value func("returnByReference");
        Php::Value b = Php::Value::makeReference(func.operator ()(a));
        Php::out << a << " " << b << std::endl;
        b = b + 1.0;
        Php::out << a << " " << b << std::endl;
        b = b + 1.0;
        Php::out << a << " " << b << std::endl;
    }
}

void init_Test0006(Php::Extension& e)
{
    e.add<test0006_1>("test0006_1");
}
