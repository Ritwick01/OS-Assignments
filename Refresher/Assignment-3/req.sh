#!/bin/bash
if ( date -d "$1" 2> /dev/null) 
then
    DAY=$(date -d "$1" '+%d')
    MONTH=$(date -d "$1" '+%m')
    YEAR=$(date -d "$1" '+%Y')
    cal $DAY $MONTH $YEAR
else
    echo "Wrong input given"
fi

