#!/bin/bash

for i in *
do
  echo "$i"
done #read all the files in the directory

n=$(expr `ls -l | tr -s ' ' | wc -l` - 1)
big=0
for((i=0;i<$n;i++))
do
    file=`ls -l | tail -$(expr $n - $i) | head -1`
    field=`echo $file | tr -s ' ' | cut -d ' ' -f 5`
    #field=`echo $file | tr -s ' ' | cut -c 12,28-30`
    if [ $field -gt $big ] #see man test
    then
        big=$field
    fi
done
    echo $big
