--TEST--
Call extension functions from PHP
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
echo my_add(1, 2, 3, 4, 5), PHP_EOL;
echo test1_my_no_parameters_function(), PHP_EOL;
test1_my_function_void();
?>
--EXPECT--
15
42
In test1_my_function_void()
