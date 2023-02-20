#!/bin/bash
path="../data/"

count_f_pos=0
for file in "$path"pos_??_in.txt; do
    count_f_pos=$((count_f_pos+1))
done
i=1
count_invalid_test=0
echo "Positive test: "
while [ $i -le $count_f_pos ]; do
    file_in="../data/pos_0${i}_in.txt"
    file_out="../data/pos_0${i}_out.txt"
    args="../data/pos_0${i}_args.txt"
    bash ./pos_case.sh "$file_in" "$file_out" "$args"
    status=$?
    echo -n "TEST $i: "
    if [ $status -eq 0 ]; then
        echo "PASS"
    else
        echo "FAILED"
        count_invalid_test=$((count_invalid_test+1))
    fi
    i=$((i+1))
done

count_f_neg=0
for file in "$path"neg_??_in.txt; do
    echo "$file" > /dev/null
    count_f_neg=$((count_f_neg + 1))
done
echo "Negative test: "
j=1
while [ $j -le $count_f_neg ]; do
    file_in="../data/neg_0${j}_in.txt"
    args="../data/pos_0${j}_args.txt"
    bash ./neg_case.sh "$file_in" "$args"
    status=$?
    echo -n "TEST $j: "
    if [ $status -eq 0 ]; then
        echo "PASS"
    else
        echo "FAILED"
        count_invalid_test=$((count_invalid_test+1))
    fi
    j=$((j+1))
done
exit $count_invalid_test
