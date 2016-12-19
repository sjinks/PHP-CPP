#include <iostream>
#include "functions.h"

Php::Value my_add(Php::Parameters& params)
{
    Php::Value r(0);

    for (unsigned int i=0; i<params.size(); ++i) {
        r += params[i];
    }

    return r;
}

void swap(Php::Parameters& params)
{
    Php::Value temp = params[0];
    params[0] = params[1];
    params[1] = temp;
}

Php::Value call_php_function(Php::Parameters& params)
{
    if (!params[0].isCallable()) {
        throw Php::Exception("Not a callable type.");
    }

    return params[0](1, 2, 3);
}

void test269(Php::Parameters& params)
{
    Php::Value obj = params[0];
    std::cout << obj["test"] << std::endl;
}

void my_throw_exception_function()
{
    throw Php::Exception("I threw an exception in my_throw_exception_function()");
}

void my_catch_exception_function(Php::Parameters& params)
{
    Php::Value callback = params[0];

    if (!callback.isCallable()) {
        throw Php::Exception("Parameter 0 is not a function");
    }

    try {
        callback("some", "example", "parameters");
    }
    catch (const Php::Exception& exception) {
        std::cout << "Exception caught in CPP code: " << exception.message() << std::endl;
    }
}

void test254()
{
    Php::Value a;
    a["b"]["c"] = "a[\"b\"][\"c\"]";
    Php::out << a["b"]["c"] << std::endl;
    a["d"] = Php::Array();
    Php::array_push(a["d"], "0");
    Php::array_push(a["d"], "1");
    Php::out << a["d"][0] << std::endl;
    Php::out << a["d"][1] << std::endl;
}

Php::Value test273(Php::Parameters& params)
{
    return nullptr;
}
