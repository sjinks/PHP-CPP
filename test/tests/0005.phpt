--TEST--
Test assignments
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
test0005();
?>
--EXPECT--
[type=10 refcounted=1 isref=1 refcount=2] 1
[type=10 refcounted=1 isref=1 refcount=2] 1
[type=4 refcounted=0 isref=0 refcount=0] 0

[type=6 refcounted=1 isref=0 refcount=3] s
[type=6 refcounted=1 isref=0 refcount=3] s
[type=6 refcounted=1 isref=0 refcount=3] s

[type=10 refcounted=1 isref=1 refcount=2] s
[type=10 refcounted=1 isref=1 refcount=2] s
[type=6 refcounted=1 isref=0 refcount=2] s

