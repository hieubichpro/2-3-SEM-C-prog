#!/bin/bash
trash="../data/trash"
ans1=
ans2=
content1=$(cat "$1")
content2=$(cat "$2")
for i in $content1; do
	echo "$i" | grep -E "[-+]?[0-9]+$" > "$trash"
	status=$?
	if [ $status -eq 0 ]; then
		ans1=$ans1" "$i
	fi
done
for i in $content2; do
	echo "$i" | grep -E "[-+]?[0-9]+$" > "$trash"
	status=$?
	if [ $status -eq 0 ]; then
		ans2=$ans2" "$i
	fi
done
if [ "$ans1" != "$ans2" ]; then
	exit 1
fi
exit 0