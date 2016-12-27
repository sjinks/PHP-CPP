#include <ostream>
#include "test0008.h"

static Php::Value test8(void)
{
    // all global variables can be accessed via the Php::GLOBALS variable,
    // which is more or less the same as the PHP $_GLOBALS variable

    // set a global variable
    Php::GLOBALS["a"] = 1;

    // increment a global variable
    Php::GLOBALS["b"] += 1;

    // set a global variable to be an array
    Php::GLOBALS["c"] = Php::Array();

    // add a member to an array
    Php::GLOBALS["c"]["member"] = 123;

    // and increment it
    Php::GLOBALS["c"]["member"] += 77;

    // change value e
    Php::GLOBALS["e"] = Php::GLOBALS["e"][0]("hello");

    // if a global variable holds a function, we can call it
    return Php::GLOBALS["d"](1, 2, 3);
}

void init_Test0008(Php::Extension& e)
{
    e.add<test8>("test8");
}
