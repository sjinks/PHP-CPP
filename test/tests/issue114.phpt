--TEST--
(#114)
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
$a = array();
$a[] = &$a;
$a[] = "hello";
var_dump($a);
var_dump(test114($a));
?>
--EXPECT--
array(2) {
  [0]=>
  &array(2) {
    [0]=>
    *RECURSION*
    [1]=>
    string(5) "hello"
  }
  [1]=>
  string(5) "hello"
}
array(2) {
  [0]=>
  &array(2) {
    [0]=>
    *RECURSION*
    [1]=>
    string(5) "hello"
  }
  [1]=>
  string(5) "hello"
}
