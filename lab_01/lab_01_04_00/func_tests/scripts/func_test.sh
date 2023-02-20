#!/bin/bash
path="../data/"

count_f_pos=0
for file in "$path"pos_??_in.txt; do
    count_f_pos=$((count_f_pos+1))
done
echo "Positive test: "
i=1
while [ $i -le $count_f_pos ]; do
	file_in=$path""$(ls $path | grep "pos_0"$i"_in")
	file_out=$path"""$(ls $path | grep "pos_0"$i"_out")"
    args=$(ls $path | grep "pos_0"$i"_args")
    bash ./pos_case.sh "$file_in" "$file_out" "$args"
    status=$?
    echo -n "TEST $i: "
    if [ $status -eq 0 ]; then
        echo "PASS"
    else
        echo "FAILED"
    fi
    i=$((i+1))
done