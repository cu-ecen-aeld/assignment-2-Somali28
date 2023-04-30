#!/bin/bash
#Author : Somali Majumder

filesdir=$1
archstr=$2

if [ $# -lt 2 ]
then
    echo "ERROR : Invalid Number of Arguments
        Total Number of Arguments should be 2
        The order of the arguments should be:
	       1')' Path to a directory on the filesystem.
	       2')' String to be searched within the specified filesystem."
    exit 1
fi

if [ -d $filesdir ]
then
    # echo "$archstr"
    # echo "$filesdir"
    echo "$filesdir is a directory"
    X=$(grep -l "$archstr" "$filesdir"/* | wc -l)
    Y=$(grep -c "$archstr" "$filesdir"/* | awk -F: '{s+=$2} END {print s}')
    echo "The number of files are $X and the number of matching lines are $Y"
    exit 0
else
    echo "$filesdir doesnot exists on your filesystem."
    exit 1
fi
