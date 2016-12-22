#!/bin/bash

TEST_DIR=$(readlink -enq "$(dirname $0)/../test")

shopt -s nullglob
export LC_ALL=C
for i in $TEST_DIR/core.*; do
	if [ -f "$i" -a "$(file "$i" | grep -o 'core file')" ]; then
		echo "====== $i ======";
		gdb -q $(php-config --php-binary) "$i" <<EOF
set pagination 0
backtrace full
info registers
x/16i \$pc
thread apply all backtrace
quit
EOF
		echo
	fi
done

echo "====== PHP Modules ======";
$(phpenv which php) -m
echo
echo "====== PHP Settings ======";
$(phpenv which php) -i
