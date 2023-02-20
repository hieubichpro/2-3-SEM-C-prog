#!/bin/bash

content1=$1
content2=$2

cmp $content1 $content2
if [ $? -ne 0 ]; then
	exit 1
fi
exit 0