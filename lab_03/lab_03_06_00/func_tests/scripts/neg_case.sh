#!/bin/bash
if [ $# -lt 1 ]; then
	echo "number of parameter invalid"
	exit 1
fi
data_in=$1
args=$2
out="../data/out"
if [ ! -v $USE_VALGRIND ]; then
	valgrind ../../app.exe "$args"< "$data_in" > "$out"
else
	../../app.exe < "$data_in" > "$out"
fi
stt=$?
if [ $stt -eq 0 ]; then
	exit 1
fi
exit 0