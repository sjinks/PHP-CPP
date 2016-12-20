#include "issue249.h"

class DoNothingClass : public Php::Base {
public:
    DoNothingClass() = default;

    void DoNothing(Php::Parameters&) {}
};

void init_Issue249(Php::Extension& e)
{
    Php::Class<DoNothingClass> doNothingClass("DoNothingClass");
    doNothingClass.method<&DoNothingClass::DoNothing>("DoNothing");
    e.add(doNothingClass);
}
