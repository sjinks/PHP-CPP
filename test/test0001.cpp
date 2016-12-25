#include <ostream>
#include "test0001.h"

static Php::Value my_add(Php::Parameters& params)
{
    Php::Value r(0);

    for (unsigned int i=0; i<params.size(); ++i) {
        r += params[i];
    }

    return r;
}

static Php::Value test1_my_no_parameters_function()
{
    return 42;
}

static void test1_my_function_void()
{
    Php::out << "In test1_my_function_void()" << std::endl;
}

void test1_my_with_undefined_parameters_function(Php::Parameters &params)
{
    for (unsigned int i=0; i<params.size(); ++i) {
        Php::out << "Parameter " << i << ": " << params[i] << std::endl;
    }
}

Php::Value test1_my_with_defined_parameters_function(Php::Parameters &params)
{
    for (unsigned int i=0; i<params.size(); ++i) {
        Php::out << "Parameter " << i << ": " << params[i] << std::endl;
    }

    return params[0] + params[1];
}

void test1_my_with_defined_parameters_reference_function(Php::Parameters &params)
{
    params[0] = "I changed!";
}

void test1_my_with_defined_array_parameters_function(Php::Parameters &params)
{
    for (int i=0; i<params[0].size(); ++i) {
        Php::out << "The array: " << params[0][i] << std::endl;
    }
}

void test1_my_with_defined_object_parameters_function(Php::Parameters &params)
{
    for (unsigned int i=0; i<params.size(); ++i) {
        Php::out << params[i] << std::endl;
    }
}


void init_Test0001(Php::Extension& e)
{
    e.add<my_add>("my_add");
    e.add<test1_my_no_parameters_function>("test1_my_no_parameters_function");
    e.add<test1_my_function_void>("test1_my_function_void");

    e.add<test1_my_with_undefined_parameters_function>("test1_my_with_undefined_parameters_function");
    e.add<test1_my_with_defined_parameters_function>("test1_my_with_defined_parameters_function", {
        Php::ByVal("x", Php::Type::Numeric),
        Php::ByVal("y", Php::Type::Numeric)
    });

    e.add<test1_my_with_defined_parameters_reference_function>("test1_my_with_defined_parameters_reference_function", {
        Php::ByRef("string", Php::Type::String)
    });

    e.add<test1_my_with_defined_array_parameters_function>("test1_my_with_defined_array_parameters_function", {
        Php::ByVal("array", Php::Type::Array)
    });

    e.add<test1_my_with_defined_object_parameters_function>("test1_my_with_defined_object_parameters_function", {
        Php::ByVal("myClassObjVar", "MyPhpClass")
    });
}
