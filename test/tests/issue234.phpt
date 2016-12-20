--TEST--
Setting a Php::GLOBALS value causes segfault (#234)
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
global $rose;
$rose = 'red';
echo test234_getglobal("rose"), PHP_EOL;

test234_setglobal("fields", "white");
echo test234_getglobal("fields"), PHP_EOL;

test234_setglobal("violet", "blue");
echo $GLOBALS['violet'], PHP_EOL;
?>
--EXPECT--
red
white
blue
