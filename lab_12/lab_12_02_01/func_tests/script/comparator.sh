#!/bin/bash

if cmp -s "$1" "$2"
then	
	exit 0
else
	exit 1
fi
