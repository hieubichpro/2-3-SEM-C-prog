#!/bin/bash
if [ $# -lt 2 ]; then
	echo "number of argument invalid"
	exit 1
fi
data_out=$1
data_expected=$2

bash ../scripts/comparator.sh "${data_out}" "${data_expected}"
if [ $? -eq 0 ]; then
	exit 0
fi
exit 1
