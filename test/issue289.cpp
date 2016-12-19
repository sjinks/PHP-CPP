#include "issue289.h"

class Test289 : public Php::Base {
public:
    void method()
    {
        Php::Value self(this);
    }
};

void init_Issue289(Php::Extension& e)
{
    Php::Class<Test289> c("Test289");
    c.method<&Test289::method>("method");
    e.add(c);
}
