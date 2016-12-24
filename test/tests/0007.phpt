--TEST--
Test constants (define/defined/constant)
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
test7_define();
var_dump(defined('ROSE'));
var_dump(defined('VIOLET'));
echo constant('ROSE'), PHP_EOL;
echo constant('VIOLET'), PHP_EOL;
$a = test7_defined();
var_dump($a);
$a = test7_constant();
var_dump($a);
test7_defineConstant('HONEY', 'sweet');
var_dump(test7_constantDefined('HONEY'));
var_dump(test7_constantDefined('HONEYPOT'));
echo test7_getConstant('HONEY'), PHP_EOL;
define('FIELDS', 'white');
var_dump(test7_constantDefined('FIELDS'));
echo test7_getConstant('FIELDS'), PHP_EOL;
?>
--EXPECT--
bool(true)
bool(true)
red
blue
array(2) {
  [0]=>
  bool(true)
  [1]=>
  bool(true)
}
array(2) {
  [0]=>
  string(3) "red"
  [1]=>
  string(4) "blue"
}
bool(true)
bool(false)
sweet
bool(true)
white
