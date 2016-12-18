#ifndef DONOTHING_H
#define DONOTHING_H

#include "phpcpp.h"

class DoNothingClass : public Php::Base {
public:
	DoNothingClass() = default;

	void DoNothing(Php::Parameters&) {}
};

#endif // DONOTHING_H
