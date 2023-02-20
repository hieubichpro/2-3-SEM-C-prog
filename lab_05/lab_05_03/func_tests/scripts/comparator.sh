#!/bin/bash
text_out=$1
text_expected=$2
diff "${text_out}" "${text_expected}"
if [ $? -ne 0 ]; then
    exit 1
fi
exit 0