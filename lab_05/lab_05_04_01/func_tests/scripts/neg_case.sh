#!/bin/bash
if [ $# -lt 1 ]; then
	echo "number of parameter invalid"
	exit 1
fi
data_in=$1
out="bin_out.bin"

../scripts/text_to_bin.exe "${data_in}" "${out}"
if [ $? -ne 0 ]; then
	exit 0
fi
exit 1