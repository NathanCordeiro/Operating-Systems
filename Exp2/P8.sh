#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: To reverse a string.

read -p "Enter a string to reverse: " original_string
reversed_string=$(echo "$original_string" | rev)

echo "Original String: $original_string"
echo "Reversed String: $reversed_string"
