#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: To reverse a number.

read -p "Enter a number:" n

# Initialize a variable to store the reversed number
num=0

while [ $n -gt 0 ]
do
	num=$((num * 10))  # Multiply the current reversed number by 10
	k=$((n % 10))  	# Get the last digit of the input number
	num=$((num + k))   # Add the last digit to the reversed number
	n=$((n / 10))  	# Remove the last digit from the input number
done

echo "Reversed number is: $num"
