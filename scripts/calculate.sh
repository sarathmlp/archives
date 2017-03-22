#!/bin/bash

#echo $(cat $1 | grep $2 | tr -s ' ' | cut -f 2 -d ' ' | tr '\n' '+')
VAR=$(cat $1 | grep $2 | tr -s ' ' | cut -f 2 -d ' ' )
echo $VAR | tr ' ' '+'  | bc
