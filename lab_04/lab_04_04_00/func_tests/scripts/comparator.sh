#!/bin/bash
ct1=$(cat "$1")
ct2=$(cat "$2")
ans1=
ans2=

for i in $ct1; do
    ans1=$ans1" "$i
done

for i in $ct2; do
    ans2=$ans2" "$i
done

if [ "$ans1" != "$ans2" ]; then
    exit 1
fi
exit 0