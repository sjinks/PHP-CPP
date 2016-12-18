--TEST--
Class constants and static properties
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
var_dump(ConstStaticProp::version);
var_dump(ConstStaticProp::PI);
var_dump(ConstStaticProp::IMISNULL);
var_dump(ConstStaticProp::LIE);
var_dump(ConstStaticProp::$exp);
var_dump(ConstStaticProp::$truth);
var_dump(ConstStaticProp::$str);
//new ConstStaticProp();
?>
--EXPECT--
string(11) "v0.01-alpha"
float(3.14159265)
NULL
bool(false)
float(2.71828182846)
bool(true)
string(3) "Hi!"
