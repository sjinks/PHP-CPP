#!/bin/bash

TEST_DIR=$(readlink -enq "$(dirname $0)/../test")

shopt -s nullglob
export NO_INTERACTION=1
export REPORT_EXIT_STATUS=1
unset TRAVIS

ulimit -c unlimited
sudo sh -c "echo $TEST_DIR/core.%p > /proc/sys/kernel/core_pattern"

make -C "$TEST_DIR" test
TEST_RESULT_EXIT_CODE=$?
for i in $TEST_DIR/tests/*.log; do
	echo "====== $i ======";
	cat "$i";
done

for i in $TEST_DIR/tests/*.mem; do
	echo "====== $i ======";
	cat "$i";
done

exit $TEST_RESULT_EXIT_CODE
