#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: To print all the prime numbers less than 20.


echo "Enter m and n:"
read m n

for a in $(seq $m $n); do
	k=0
	for i in $(seq 2 $(expr $a - 1)); do
    	if [ $(expr $a % $i) -eq 0 ]; then
        	k=1
        	break
    	fi
	done

	if [ $k -eq 0 ]; then
    	echo $a
	fi
done
