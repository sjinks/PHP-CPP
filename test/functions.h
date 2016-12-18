#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "phpcpp.h"

Php::Value my_add(Php::Parameters& params);
void swap(Php::Parameters& params);
Php::Value call_php_function(Php::Parameters& params);

#endif // FUNCTIONS_H
