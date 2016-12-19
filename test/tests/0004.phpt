--TEST--
Exceptions
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
my_catch_exception_function(
	function($a, $b, $c)
	{
		throw new Exception("Sample exception");
	}
);

try {
	my_throw_exception_function();
}
catch (Exception $exception) {
	echo $exception->getMessage(), PHP_EOL;
}
?>
--EXPECT--
Exception caught in CPP code: Sample exception
I threw an exception in my_throw_exception_function()
