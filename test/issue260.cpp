#include "issue260.h"

class Test260 : public Php::Base {
public:
    void __construct()
    {
        Php::Value self(this);
        self.set("property", 34);
    }

    Php::Value getProperty()
    {
        Php::Value self(this);
        return self["property"];
    }
};

void init_Issue260(Php::Extension& e)
{
    Php::Class<Test260> c("Test260");
    c.method<&Test260::__construct>("__construct");
    c.method<&Test260::getProperty>("getProperty");
    c.property("property", -1, Php::Protected);
    e.add(c);
}
