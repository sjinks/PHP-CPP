--TEST--
Segmentation fault when accessing object passed by reference (#269)
--XFAIL--
TBD
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
$foo = new stdClass;
$foo->test = 23;
test269($foo);
?>
--EXPECT--
23
