--TEST--
Memleak if pass a callback as a parameter (#273)
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
function test_promise()
{
	$promise = test273(function() {});
}

$u1 = memory_get_usage(true);
for ($i=0; $i<100000; ++$i) {
	test_promise();
}
$u2 = memory_get_usage(true);
var_dump($u1 == $u2);
?>
--EXPECT--
bool(true)
