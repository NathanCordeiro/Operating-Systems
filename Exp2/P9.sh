#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: Check whether the entered number is odd or even.

read -p "Enter a number: " num

if [ $((num % 2)) -eq 0 ]; then
	echo "$num is even."
else
	echo "$num is odd."
fi
