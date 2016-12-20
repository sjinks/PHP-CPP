#include "test0003.h"

class ConstStaticProp : public Php::Base {
public:
    ConstStaticProp() {}
    virtual ~ConstStaticProp() {}
    virtual void __construct() {}
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
    cspClass.method<&ConstStaticProp::__construct>("__construct", Php::Private);
    e.add(cspClass);
}
