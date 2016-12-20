#include "test0002.h"

static Php::Value call_php_function(Php::Parameters& params)
{
    if (!params[0].isCallable()) {
        throw Php::Exception("Not a callable type.");
    }

    return params[0](1, 2, 3);
}

void init_Test0002(Php::Extension& e)
{
    e.add<call_php_function>("call_php_function", {
        Php::ByVal("addFunc", Php::Type::Callable)
    });
    e.add<call_php_function>("call_php_function2", {
        Php::ByVal("addFunc")
    });
}
