#!/bin/bash
args=("$@")
SYMBOL=$1
case $SYMBOL in 
    "add" )
        sum=0
        for (( i=1; i<$#; i++))
        do 
            (( sum += ${args[i]} ))
        done
        echo $sum ;;
    "sub" )
        sum=$2
        for (( i=2; i<$#; i++))
        do 
            (( sum -= ${args[i]} ))
        done
        echo $sum ;;
    "mul" )
        sum=1
        for (( i=1; i<$#; i++))
        do 
            (( sum *= ${args[i]} ))
        done
        echo $sum ;;
    "div" )
        sum=$2
        count=0
        for (( i=2; i<$#; i++))
        do 
            if [ ${args[i]} -eq 0 ]; then
                echo "Division by 0 not allowed"
                count=1
            else
                (( sum /= ${args[i]} ))
            fi
        done
        if [ $count -eq 0 ]; then
            echo $sum
        fi;;
    "exp" )
        sum=${args[$#-1]}
        for (( i=$#-2; i>=1; i--))
        do 
            (( sum = ${args[i]}**$sum ))
        done
        echo $sum ;;
esac

