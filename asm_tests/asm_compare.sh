#!/bin/bash 

if [ "$#" -ne 2 ]; then
	echo "Please provide two .cor files as parameters"
	exit
fi

hexdump -v $1 >> hex1.txt
hexdump -v $2 >> hex2.txt

if cmp -s hex1.txt hex2.txt; then
	echo "Files are identical, bravo"
	exit
else
	diff hex1.txt hex2.txt >> diff_"$1"-"$2".txt
	exit
fi