#!/bin/bash
if [ $# -lt 2 ]; then
	echo "number of argument invalid"
	exit 1
fi
data_in=$1
data_expected=$2
file_text_out="text_out.txt"

../../app.exe s "${data_in}"
../scripts/bin_to_text.exe "${data_in}" "${file_text_out}"

if [ $? -ne 0 ]; then
	exit 1
fi

bash ../scripts/comparator.sh "${file_text_out}" "${data_expected}"
if [ $? -eq 0 ]; then
	exit 0
fi
exit 1
