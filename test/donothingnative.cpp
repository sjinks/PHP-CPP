#include <Zend/zend.h>
#include <php.h>
#include "donothingnative.h"

static zend_class_entry* dnc_ce;
static zend_object_handlers dnc_object_handlers;

PHP_FUNCTION(doNothing)
{
}

ZEND_BEGIN_ARG_INFO(arginfo_nothing, 0)
ZEND_END_ARG_INFO()

static const zend_function_entry dnc_functions[] = {
	PHP_FE(doNothing, arginfo_nothing)
	PHP_FE_END
};

static zend_object* dnc_create_object(zend_class_entry* ce)
{
	zend_object* intern = static_cast<zend_object*>(ecalloc(1, sizeof(zend_object) + zend_object_properties_size(ce)));
	zend_object_std_init(intern, ce);
	object_properties_init(intern, ce);
	intern->handlers = &dnc_object_handlers;

	return intern;
}

static void dnc_free_obj(zend_object* object)
{
	zend_object_std_dtor(object);
}

static void dnc_dtor_obj(zend_object* object)
{
	zend_object_std_dtor(object);
}

void register_donothingnative()
{
	zend_class_entry dnc;

	INIT_CLASS_ENTRY(dnc, "DoNothingNative", dnc_functions);
	dnc.create_object = dnc_create_object;
	dnc_ce = zend_register_internal_class(&dnc);

	memcpy(&dnc_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	dnc_object_handlers.offset   = 0;
	dnc_object_handlers.free_obj = dnc_free_obj;
	dnc_object_handlers.dtor_obj = dnc_dtor_obj;
}
