#!/bin/bash

for i in $1
do
    cat $i | grep error | tr -s ' ' | cut -d ' ' -f 2,3,4 | tr  '"' ' ' | tr -s ' ' | awk '{print$6,$2,$4}' | tr ' ' ':''"' >> supp
done

