--TEST--
Protected properties (#260)
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
$x = new Test260();
echo $x->getProperty(), PHP_EOL;
?>
--EXPECT--
34
