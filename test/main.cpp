#include "phpcpp.h"
#include "functions.h"
#include "donothing.h"
#include "donothingnative.h"
#include "conststaticprop.h"

extern "C"
{
    PHPCPP_EXPORT void* get_module()
    {
        static Php::Extension extension("phpcpptest", "1.0");

        extension.onStartup([](){
            register_donothingnative();
        });

        extension.add<my_add>("my_add");
        extension.add<swap>("swap", {
            Php::ByRef("a", Php::Type::Numeric),
            Php::ByRef("b", Php::Type::Numeric)
        });
        extension.add<call_php_function>("call_php_function", {
            Php::ByVal("addFunc", Php::Type::Callable)
        });
        extension.add<call_php_function>("call_php_function2", {
            Php::ByVal("addFunc")
        });
        extension.add<test269>("test269", {
            Php::ByRef("obj", Php::Type::Null, false)
        });
        extension.add<my_throw_exception_function>("my_throw_exception_function");
        extension.add<my_catch_exception_function>("my_catch_exception_function");
        extension.add<test254>("test254");
        extension.add<test273>("test273");

        Php::Class<DoNothingClass> doNothingClass("DoNothingClass");
        doNothingClass.method<&DoNothingClass::DoNothing>("DoNothing");
        extension.add(doNothingClass);

        Php::Class<ConstStaticProp> cspClass("ConstStaticProp");
        cspClass.add(Php::Constant("version", "v0.01-alpha"));
        cspClass.constant("PI", 3.14159265);
        cspClass.property("IMISNULL", nullptr, Php::Const);
        cspClass.property("LIE", false, Php::Const);
        cspClass.property("exp", 2.71828182846, Php::Static);
        cspClass.property("truth", true, Php::Static);
        cspClass.property("str", "Hi!", Php::Static);
        cspClass.method<&ConstStaticProp::__construct>("__construct", Php::Private);
        extension.add(cspClass);

        return extension.module();
    }
}
