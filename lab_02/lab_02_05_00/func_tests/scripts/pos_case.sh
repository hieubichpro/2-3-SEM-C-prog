#!/bin/bash
if [ $# -lt 2 ]; then
	echo "number of argument invalid"
	exit 1
fi
data_in=$1
data_out=$2
args=$3
cmp_file="../data/cmp_file"

if [ ! -v $USE_VALGRIND ]; then
	valgrind ../../app.exe "$args"< "$data_in" > "$cmp_file"
else
	../../app.exe < "$data_in" > "$cmp_file"
fi
stt=$?
if [ $stt -ne 0 ]; then
	exit 1
fi
bash ./comparator.sh "$cmp_file" "$data_out"
stt=$?
if [ $stt -eq 0 ]; then
	exit 0
fi
exit 1

