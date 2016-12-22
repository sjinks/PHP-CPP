#include "test0003.h"

class ConstStaticProp : public Php::Base {
public:
};

void init_Test0003(Php::Extension& e)
{
    Php::Class<ConstStaticProp> cspClass("ConstStaticProp");
    cspClass.add(Php::Constant("version", "v0.01-alpha"));
    cspClass.constant("PI", 3.14159265);
    cspClass.property("IMISNULL", nullptr, Php::Const);
    cspClass.property("LIE", false, Php::Const);
    cspClass.property("exp", 2.71828182846, Php::Static);
    cspClass.property("truth", true, Php::Static);
    cspClass.property("str", "Hi!", Php::Static);
    e.add(cspClass);
}
