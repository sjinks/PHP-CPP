#!/bin/bash

PREFIX=$(readlink -enq "$(dirname $0)/../")

rm -rf   "$PREFIX/.gcov"
mkdir -p "$PREFIX/.gcov"

(cd test && gcov -ablpr -s "$PREFIX" -o .build/ *.cpp;   mv *.gcov "$PREFIX/.gcov/")
gcov -ablpr -s "$PREFIX" -o shared/zend/   zend/*.cpp;   mv *.gcov "$PREFIX/.gcov/"
gcov -ablpr -s "$PREFIX" -o shared/common/ common/*.cpp; mv *.gcov "$PREFIX/.gcov/"

/bin/bash <(curl -s https://codecov.io/bash) -f "$PREFIX/gcov/*.gcov" -X gcov
