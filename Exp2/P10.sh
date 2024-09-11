#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: Check Whether a given year is a leap year or not.

read -p "Enter a year: " year

if [ $((year % 4)) -eq 0 ]; then
	echo "$year is a leap year"
elif [ $((year % 100)) -eq 0 ]; then
	echo "$year is a leap year"
elif [ $((year % 400)) -eq 0 ]; then
	echo "$year is a leap year"
else
	echo "$year is not a leap year"
fi
