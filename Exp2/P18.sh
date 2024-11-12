#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: To sort given numbers in descending order.

# Input: Read space-separated numbers into an array
echo "Enter the numbers (separated by spaces):"
read -a arr

# Bubble sort (descending order)
n=${#arr[@]}
for ((i = 0; i < n; i++)); do
	for ((j = 0; j < n - i - 1; j++)); do
    	if [ ${arr[j]} -lt ${arr[$((j + 1))]} ]; then
        	temp=${arr[j]}
        	arr[j]=${arr[$((j + 1))]}
        	arr[$((j + 1))]=$temp
    	fi
	done
done

# Output: Display the sorted array
echo "Array in descending order:"
echo "${arr[@]}"
