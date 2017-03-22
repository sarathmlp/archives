#!/bin/bash

VAR="vi idc_client.cpp:"

echo $VAR | grep ':' > /dev/null 2>&1
if [ "$?" -eq "0" ]; then
    R1=$(echo $VAR | tr ':' ' ')
    R2=$(echo $R1 | cut -d ' ' -f 1,2)
    R3=' +'$(echo $R1 | cut -d ' ' -f 3)
    echo $R2$R3
else
    echo "$@"
fi
