#!/bin/bash
# This is a simple bash number converter+calculator, which internally uses the
# bash calculator bc, you can pass the second argument as an expression, with
# proper first argument to work it as calculator.
# Usage ". converter.sh d2h 87"
# Usage ". converter.sh d2d 87+13"
# Author:   Sarath V.
case "$1" in
    "d2h") echo "ibase=A;obase=16;$2" | bc;;
    "d2b") echo "ibase=A;obase=2;$2" | bc;;
    "d2o") echo "ibase=A;obase=8;$2" | bc;;
    "d2d") echo "ibase=A;obase=A;$2" | bc;;
    "h2d") echo "ibase=16;obase=A;$2" | bc;;
    "h2b") echo "ibase=16;obase=2;$2" | bc;;
    "h2o") echo "ibase=16;obase=8;$2" | bc;;
    "h2h") echo "ibase=16;obase=10;$2" | bc;;
    "b2d") echo "ibase=2;obase=A;$2" | bc;;
    "b2h") echo "ibase=2;obase=10000;$2" | bc;;
    "b2o") echo "ibase=2;obase=8;$2" | bc;;
    "b2b") echo "ibase=2;obase=2;$2" | bc;;
    "o2b") echo "ibase=8;obase=2;$2" | bc;;
    "o2d") echo "ibase=8;obase=A;$2" | bc;;
# This is because 20 is octal value for 16, if we give 16 it'll convert to
# octal and proceed which is 14, this is because both 1 and 6 are of type octal
    "o2h") echo "ibase=8;obase=20;$2" | bc;;
    "o2o") echo "ibase=8;obase=8;$2" | bc;;
esac
