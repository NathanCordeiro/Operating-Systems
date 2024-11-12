#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: Write a shell script to prompt user to enter 2 numbers and perform various arithmetic operations using switch statement.

echo "Enter two numbers:"
read a b

echo "Choose an option:"
echo "1) Addition"
echo "2) Subtraction"
echo "3) Multiplication"
echo "4) Division"
echo "5) Modulus"
read choice

case $choice in
	1) r=$((a + b));;
	2) r=$((a - b));;
	3) r=$((a * b));;
	4) r=$((a / b));;
	5) r=$((a % b));;
	*) echo "Invalid Option";;
esac

echo "Result is $r"
