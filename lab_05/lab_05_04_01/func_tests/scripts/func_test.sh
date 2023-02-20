#!/bin/bash
cd ../data
count_invalid_test=0
echo "Positive test"

file_1="pos_01_in.txt"
etalon_1="pos_01_out.txt"
bin_in_1="bin_in_1.bin"
file_text_out="out_1.txt"
../scripts/text_to_bin.exe "${file_1}" "${bin_in_1}"
if [ $? -ne 0 ]; then
	exit 1
fi
../../app.exe sb "${bin_in_1}" > trash.txt
../scripts/bin_to_text.exe "${bin_in_1}" "${file_text_out}"
bash ../scripts/pos_case.sh "${file_text_out}" "${etalon_1}"
if [ $? -eq 0 ]; then
    echo "PASSED"
else
    echo "FAILED"
    count_invalid_test=$((count_invalid_test+1))
fi

file_2="pos_02_in.txt"
etalon_2="pos_02_out.txt"
bin_in_2="bin_in_2.bin"
bin_out_2="bin_out_2.bin"
file_text_out="out_2.txt"
../scripts/text_to_bin.exe "${file_2}" "${bin_in_2}"
if [ $? -ne 0 ]; then
	exit 1
fi
../../app.exe fb "${bin_in_2}" "${bin_out_2}" hl
../scripts/bin_to_text.exe "${bin_out_2}" "${file_text_out}"
bash ../scripts/pos_case.sh "${file_text_out}" "${etalon_2}"
if [ $? -eq 0 ]; then
    echo "PASSED"
else
    echo "FAILED"
    count_invalid_test=$((count_invalid_test+1))
fi

file_3="pos_03_in.txt"
etalon_3="pos_03_out.txt"
bin_in_3="bin_in_3.bin"
file_text_out="out_3.txt"
../scripts/text_to_bin.exe "${file_3}" "${bin_in_3}"
if [ $? -ne 0 ]; then
	exit 1
fi
../../app.exe db "${bin_in_3}"
../scripts/bin_to_text.exe "${bin_in_3}" "${file_text_out}"
bash ../scripts/pos_case.sh "${file_text_out}" "${etalon_3}"
if [ $? -eq 0 ]; then
    echo "PASSED"
else
    echo "FAILED"
    count_invalid_test=$((count_invalid_test+1))
fi
echo $count_invalid_test

echo "Negative test"
for file in neg_??_in.txt; do
    bash ../scripts/neg_case.sh "${file}"
    if [ $? -eq 0 ]; then
        echo "PASSED"
    fi
done