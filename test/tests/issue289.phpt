--TEST--
Memory Leak in Php::Value::Value(const Php::Base*) (#289)
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
$x  = new Test289();
$u1 = memory_get_usage(true);
for ($i=0; $i<100000; ++$i) {
	$x->method();
}
$u2 = memory_get_usage(true);
var_dump($u1 == $u2);
?>
--EXPECT--
bool(true)
