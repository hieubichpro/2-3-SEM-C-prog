#!/bin/bash 

if [ -n "$USE_VALGRIND" ]
then
	if valgrind ./app.exe $(cat "$1")  >/dev/null;
	then
		exit 1
	else
		exit 0
	fi 
else
	if ./app.exe $(cat "$1") > /dev/null;
	then 	
		exit 1
	else
		exit 0
	fi
fi

