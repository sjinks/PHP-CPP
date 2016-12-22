#include <ostream>
#include "test0005.h"

static void test0005()
{
    {
        Php::Value a = 0;
        Php::Value b = Php::Value::makeReference(a);
        Php::Value c(b);
        a = 1;

        Php::out << a.debugZval() << std::endl;
        Php::out << b.debugZval() << std::endl;
        Php::out << c.debugZval() << std::endl;
        Php::out << std::endl;
    }

    {
        Php::Value a = "s";
        Php::Value b = a;
        Php::Value c = a;

        Php::out << a.debugZval() << std::endl;
        Php::out << b.debugZval() << std::endl;
        Php::out << c.debugZval() << std::endl;
        Php::out << std::endl;
    }

    {
        Php::Value a = 0;
        Php::Value b = Php::Value::makeReference(a);
        Php::Value c(b);
        a = 's';
        b = a;
        c = a;

        Php::out << a.debugZval() << std::endl;
        Php::out << b.debugZval() << std::endl;
        Php::out << c.debugZval() << std::endl;
        Php::out << std::endl;
    }
}

void init_Test0005(Php::Extension& e)
{
    e.add<test0005>("test0005");
}
