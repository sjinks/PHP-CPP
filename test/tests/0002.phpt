--TEST--
Call PHP Function
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
class MyClass
{
	function method($a, $b, $c)
	{
		return $a + $b + $c;
	}
}

function myFunction($a, $b, $c)
{
	return $a + $b + $c;
}

echo call_php_function(function($a, $b, $c) { return $a + $b + $c; }), PHP_EOL;
echo call_php_function("myFunction"), PHP_EOL;
echo call_php_function(array(new MyClass(), 'method')), PHP_EOL;

try {
	call_php_function(123);
	echo "FAIL", PHP_EOL;
}
catch (Throwable $e) {
	echo $e->getMessage(), PHP_EOL;
}

try {
	call_php_function2(123);
	echo "FAIL", PHP_EOL;
}
catch (Throwable $e) {
	echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECT--
6
6
6
Argument 1 passed to call_php_function() must be callable, integer given
Not a callable type.
