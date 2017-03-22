#!/bin/bash
# Author : Sarath V.
# Usage: ./compile.sh arg
# All rights reserved.

status()
{
    if [ $? -ne 0 ]; then
        echo -e "---------------------------"
        echo -e "\e[0;31mCompilation of $1 Failed.\e[0m"
        exit -1
    else
        echo -e "---------------------------"
        echo -e "\e[0;32mCompilation of $1 Success.\e[0m"
    fi
}

display()
{
    echo -e "---------------------------"
    echo -e "\e[0;32mCompiling $1.\e[0m"
}

if [ $# == 0 ]; then
    cd AcceleroCore;
    display "AcceleroCore"
    make clean > err 2>&1;make > err 2>&1
    status "AcceleroCore"

    cd - > /dev/null 2>&1;cd eAccelero;
    display "eAccelero"
    make > err 2>&1
    status "eAccelero"

    cd - > /dev/null 2>&1;cd imsdia;
    display "imsdia"
    make clean > err 2>&1;make > err 2>&1
    status "imsdia"

    cd - > /dev/null 2>&1;cd dre;
    display "dre"
    make clean > err 2>&1;make > err 2>&1
    status "dre"
else
    display $1
    make $1 > err 2>&1 
    status $1
fi
