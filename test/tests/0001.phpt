--TEST--
Call extension functions from PHP
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
echo my_add(1, 2, 3, 4, 5), PHP_EOL;
?>
--EXPECT--
15
