--TEST--
Call extension functions from PHP
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
echo my_add(1, 2, 3, 4, 5), PHP_EOL;
echo test1_my_no_parameters_function(), PHP_EOL;
test1_my_function_void();

class MyPhpClass 
{
    public $aMemberVar = "aMemberVar";

    public function __toString()
    {
        return "myPhpClass.__toString()";
    }

    public function getMemberVar()
    {
        return $this->aMemberVar;
    }
}

echo PHP_EOL;
echo test1_my_with_undefined_parameters_function('1st', '2nd', '3rd', '4th'), PHP_EOL, PHP_EOL;
echo test1_my_with_defined_parameters_function(21, 42), PHP_EOL, PHP_EOL;
$referenceVar = "I am unchanged.";
echo "The value of referenceVar: ", $referenceVar, PHP_EOL;
echo test1_my_with_defined_parameters_reference_function($referenceVar), PHP_EOL;
echo "New value of referenceVar: ", $referenceVar, PHP_EOL, PHP_EOL;
$myArray = array("a", "b", "c", "d");
echo test1_my_with_defined_array_parameters_function($myArray), PHP_EOL, PHP_EOL;
$myPhpClass = new MyPhpClass;
echo test1_my_with_defined_object_parameters_function($myPhpClass);
?>
--EXPECT--
15
42
In test1_my_function_void()

Parameter 0: 1st
Parameter 1: 2nd
Parameter 2: 3rd
Parameter 3: 4th


Parameter 0: 21
Parameter 1: 42
63

The value of referenceVar: I am unchanged.

New value of referenceVar: I changed!

The array: a
The array: b
The array: c
The array: d


myPhpClass.__toString()
