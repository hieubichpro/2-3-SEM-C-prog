#!/bin/bash
trash="../data/trash"
content1=$(cat $1)
content2=$(cat $2)
ans1=
ans2=
flag=0
for i in $ct1; do
	if [ "$i" == "Result:" ]; then
		flag=1
	fi
	if [ $flag -eq 1 ]; then
		ans1=$ans1" "$i
	fi
done
flag=0
for i in $ct2; do
	if [ "$i" == "Result:" ]; then
		flag=1
	fi
	if [ $flag -eq 1 ]; then
		ans2=$ans2" "$i
	fi
done
if [ "$ans1" != "$ans2" ]; then
	exit 1
fi
exit 0