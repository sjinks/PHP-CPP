--TEST--
Segmentation fault on accessing Php::REQUEST (#229)
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
$_REQUEST['key'] = 'value';
echo test229_get('key'), PHP_EOL;

test229_set("k", "v");
echo $_REQUEST["k"], PHP_EOL;

test229_set("k", "z");
echo $_REQUEST["k"], PHP_EOL;

test229_set("a", "b");
echo test229_get('a'), PHP_EOL;

test229_set("key", "val");
$val = test229_get('key');
echo $val, PHP_EOL;

$val = 'strange';
echo $_REQUEST['key'], PHP_EOL;

$val = test229_get('key');
echo $val, PHP_EOL;
?>
--EXPECT--
value
v
z
b
val
val
val
