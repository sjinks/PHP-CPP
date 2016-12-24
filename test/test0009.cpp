#include "test0009.h"

class Child : public Php::Base {
public:
    const char* __toString() const
    {
        return "this is the child";
    }
};

class Master : public Php::Base {
private:
    /**
     *  One child
     */
    Php::Value _value;

public:
    Master()
    {
        _value = Php::Object("Child", new Child());
    }

    Php::Value child() const
    {
        return _value;
    }

    const char* __toString() const
    {
        return "this is the master";
    }
};


void init_Test0009(Php::Extension& e)
{
    Php::Class<Master> master("master");
    Php::Class<Child> child("child");

    // the master class has one method - to return a child
    master.method<&Master::child>("child");

    e.add(master);
    e.add(child);
}
