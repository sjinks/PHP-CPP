--TEST--
#249 (orig)
--FILE--
<?php
$iterations = 0;
$memoryUsages = [];
$maxMemory = 64000000;
do {
    $iterations++;

    $DoNothingClass1 = new DoNothingClass();
    $DoNothingClass2 = new DoNothingClass();
    $DoNothingClass1->DoNothing($DoNothingClass2);
    $memoryUsage = memory_get_usage(true);
    if (!in_array($memoryUsage, $memoryUsages)) {
        $memoryUsages[] = $memoryUsage;
        $output = sprintf('iterations: %d; memory_usage: %s B'."\n",
            $iterations,
            number_format($memoryUsage, 0, '.', '\'')
        );
        print $output;
        if ($memoryUsage >= $maxMemory) {
            print 'stopping, because memory_usage is over '.number_format($maxMemory, 0, '.', '\'')." B\n";
            break;
        } // if ($memoryUsage >= $maxMemory)
    }
} while($iterations < 655360);
?>
--EXPECTF--
iterations: %d; memory_usage: %s B
