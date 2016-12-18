--TEST--
Memory Leak (#249)
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php
$u1 = -1;
$u2 = -1;
for ($i=0; $i<65536; ++$i) {
    $testClass1 = new DoNothingClass();
    $testClass2 = new DoNothingClass();
    $testClass1->DoNothing($testClass2);
    if ($u1 == -1) {
        $u1 = memory_get_usage(true);
    }
    else {
        $u2 = memory_get_usage(true);
    }
};

echo (($u1 == $u2) ? "OK" : "FAIL"), PHP_EOL;

$u1 = -1;
$u2 = -1;
for ($i=0; $i<65536; ++$i) {
    $testClass1 = new DoNothingNative();
    $testClass2 = new DoNothingNative();
    $testClass1->DoNothing($testClass2);
    if ($u1 == -1) {
        $u1 = memory_get_usage(true);
    }
    else {
        $u2 = memory_get_usage(true);
    }
};

echo (($u1 == $u2) ? "OK" : "FAIL"), PHP_EOL;
?>
--EXPECT--
OK
OK
