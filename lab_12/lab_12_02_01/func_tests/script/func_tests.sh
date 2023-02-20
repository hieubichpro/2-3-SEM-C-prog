#!/bin/bash

file=$(ls ../data/)
cd ../../
for TEST in $(echo "$file" | grep "pos_[0-9][0-9]_args.txt" | sed 's/_args.txt//g')
do 	
	if bash ./func_tests/script/pos_case.sh ./func_tests/data/"${TEST}"_args.txt
	then
		echo "${TEST}_in.txt: PASSED"
	else
		echo "${TEST}_in.txt: FAILED"
	fi 
done
echo "---------------"
for TEST in $(echo "$file" | grep "neg_[0-9][0-9]_args.txt" | sed 's/_args.txt//g')
do 	
	if bash ./func_tests/script/neg_case.sh ./func_tests/data/"${TEST}"_args.txt
	then	
		echo "${TEST}_in.txt: PASSED"
	else	
		echo "${TEST}_in.txt: FAILED"
	fi
done
