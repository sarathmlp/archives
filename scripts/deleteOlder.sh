#!/bin/bash

DAYS=30
DIR=/home/pathToFiles
# Delete directories older than DAYS 
# Otherwise (if files removed first)deletion of all files inside 
# that dir modifies it's timestamp and hence the dir wont remove
find $DIR -type d -mtime +$DAYS -exec rm -rf {} \; > /dev/null 2>&1
# Delete files older than DAYS 
find $DIR -type f -mtime +$DAYS -exec rm {} \;
