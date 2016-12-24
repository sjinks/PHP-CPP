--TEST--
ReturnObject extension
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
$master = new Master();
$child1 = new Child();
$child2 = $master->child();

echo strval($master), PHP_EOL;
echo strval($child1), PHP_EOL;
echo strval($child2), PHP_EOL;
?>
--EXPECT--
this is the master
this is the child
this is the child
