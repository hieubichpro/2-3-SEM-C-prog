#!/bin/bash
path="../data/"

count_f_pos=0
for file in "$path"pos_??_in.txt; do
    count_f_pos=$((count_f_pos+1))
done
i=1
echo "Positive test: "
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

count_f_neg=0
for file in "$path"neg_??_in.txt; do
    count_f_neg=$((count_f_neg + 1))
done
echo "Negative test: "
j=1
while [ $j -le $count_f_neg ]; do
    file_in=$path""$(ls $path | grep "neg_0"$j"_in")
	args=$(ls $path | grep "neg_0"$j"_args")
    bash ./neg_case.sh "$file_in" "$args"
    status=$?
    echo -n "TEST $j: "
    if [ $status -eq 0 ]; then
        echo "PASS"
    else
        echo "FAILED"
    fi
    j=$((j+1))
done