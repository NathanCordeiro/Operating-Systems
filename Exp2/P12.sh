#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: To check if the entered string is palindrome or not.


read -p "Enter a string: " input_string
# Initialize pointers
left=0
right=$(( ${#input_string} - 1 ))

# Compare characters from both ends
while [ $left -lt $right ]; do
	if [ "${input_string:$left:1}" != "${input_string:$right:1}" ]; then
    	echo "The entered string '$input_string' is not a palindrome."
    	exit
	fi
	left=$(( left + 1 ))
	right=$(( right - 1 ))
done

echo "The entered string '$input_string' is a palindrome."
