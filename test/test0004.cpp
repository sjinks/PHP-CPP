#include <ostream>
#include "test0004.h"

static void my_throw_exception_function()
{
    throw Php::Exception("I threw an exception in my_throw_exception_function()");
}

static void my_catch_exception_function(Php::Parameters& params)
{
    Php::Value callback = params[0];

    if (!callback.isCallable()) {
        throw Php::Exception("Parameter 0 is not a function");
    }

    try {
        callback("some", "example", "parameters");
    }
    catch (const Php::Exception& exception) {
        Php::out << std::string("Exception caught in CPP code: ") << exception.message() << std::endl;
    }
}

void init_Test0004(Php::Extension& e)
{
    e.add<my_throw_exception_function>("my_throw_exception_function");
    e.add<my_catch_exception_function>("my_catch_exception_function");
}
