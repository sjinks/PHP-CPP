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
