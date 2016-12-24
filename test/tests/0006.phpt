--TEST--
Test references
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
function& returnByReference(&$a)
{
    return $a;
}

$a = 5;
$b = returnByReference($a);
echo $b, PHP_EOL;
++$b;
echo $a, ' ', $b, PHP_EOL;

unset($a, $b);
echo PHP_EOL;

$a = 5;
$b = &returnByReference($a);
echo $b, PHP_EOL;
++$b;
echo $a, ' ', $b, PHP_EOL;
echo PHP_EOL;

test0006_1();
?>
--EXPECT--
5
5 6

5
6 6

[type=10 refcounted=1 isref=1 refcount=1] 5
5 5
6 6
7 7

[type=10 refcounted=1 isref=1 refcount=1] 5
5 5
6 6
7 7

