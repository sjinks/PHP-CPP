--TEST--
Globals test (Globals sample extension)
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
$b = 10;
$d = function($a, $b, $c) {
    return $a+$b+$c;
};

$e = array(
    function($a) {
        return $a;
    }
);

$d = test8();

echo "a = {$a}", PHP_EOL;
echo "b = {$b}", PHP_EOL;
echo "c['member'] = {$c['member']}", PHP_EOL;
echo "d = {$d}", PHP_EOL;
echo "e = {$e}", PHP_EOL;
?>
--EXPECT--
a = 1
b = 11
c['member'] = 200
d = 6
e = hello
