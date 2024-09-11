#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: To print the largest of 3 numbers entered by the user.

echo "Enter 3 numbers : "
read x
read y
read z

if [ $x -ge $y ] && [ $x -ge $z ]
then
	echo "$x is largest"
elif [ $y -ge $x ] && [ $y -ge $z ]
then
	echo "$y is largest"
else
	echo "$z is largest"
fi
