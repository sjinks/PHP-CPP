--TEST--
Refernces not working (#261)
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
$a = 1;
$b = 2;

echo $a, ' ', $b, PHP_EOL;
swap($a, $b);
echo $a, ' ', $b, PHP_EOL;
?>
--EXPECT--
1 2
2 1
