#!/bin/bash
diff "$1" "$2"
stt=$?
if [ $stt -eq 0 ]; then
    exit 0
else
    exit 1
fi