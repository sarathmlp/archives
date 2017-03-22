#!/bin/bash -x
if [ $# -ne 3 ]; then
echo "usage: affine.sh <pid> [ -m | -c ] [ mask | cpulist ]"
exit
fi
PID=$1
CPULIST=$3
# get the threads PIDs
TIDS=`pstack $PID | grep Thread | grep LWP | cut -d' ' -f6 | cut -d')' -f1`

for tid in $TIDS
do
if [ -z `echo $2 | grep "\-m" | wc -w` ]; then
taskset -p $CPULIST $tid
else
taskset -pc $CPULIST $tid
fi
done
