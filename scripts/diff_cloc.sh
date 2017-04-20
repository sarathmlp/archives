#/bin/bash

if [ -z "$1" ]
then
    echo "./diff_cloc <diff file>"
    exit 1
fi

echo `grep "^-" $1 | grep -v "^---" | wc -l` "lines removed"
echo `grep "^+" $1 | grep -v "^+++" | wc -l` "lines added"
