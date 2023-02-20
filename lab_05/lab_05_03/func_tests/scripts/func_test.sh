#!/bin/bash
cd ../data
count_invalid_test=0
echo "Positive test"
for file in pos_??_in.txt; do
    file_etalon=${file//in/out}
    file_bin_in="bin_in.bin"
    ../scripts/text_to_bin.exe "${file}" "${file_bin_in}"
    if [ $? -ne 0 ]; then
	    exit 1
    fi
    bash ../scripts/pos_case.sh "${file_bin_in}" "${file_etalon}"
    if [ $? -eq 0 ]; then
        echo "PASSED"
    else
        echo "FAILED"
        count_invalid_test=$((count_invalid_test+1))
    fi
done
echo "Negative test"
for file in neg_??_in.txt; do
    bash ../scripts/neg_case.sh "${file}"
    if [ $? -eq 0 ]; then
        echo "PASSED"
    fi
done
cd ../scripts