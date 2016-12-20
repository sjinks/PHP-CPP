--TEST--
Php::Value::xxxValue() and references (#293)
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
$a = 73;
test293($a, 0);
$a = 3.14159;
test293($a, 1);
$a = "Venceremos!";
test293($a, 2);
?>
--EXPECT--
73 73
3.14159 3.14159
Venceremos! Venceremos!
