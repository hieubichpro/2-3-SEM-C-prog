#!/bin/bash 
name="${1//args.txt/out_test.txt}"
filein="${1//args.txt/out.txt}"

if [ -n "$USE_VALGRIND" ]
then
	valgrind ./app.exe $(cat "$1")
else
	./app.exe $(cat "$1")
fi

if [ ! "$?" ]
then
	exit 1
fi 

bash ./func_tests/script/comparator.sh "$filein" "$name"
exit "$?"




