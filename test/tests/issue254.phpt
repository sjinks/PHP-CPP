--TEST--
array_push is showing error (#254)
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
test254();
?>
--EXPECT--
a["b"]["c"]
0
1
