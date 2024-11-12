#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: Append content to a file provided file name exists and it has write permission.

echo "Enter a file name"
read filename

if [ -f "$filename" ]; then
	if [ -w "$filename" ]; then
    	echo "Enter content to add:"
    	read content
    	echo "$content" >> "$filename"
    	echo "Content added successfully!"
	else
    	echo "File is not writable"
	fi
else
	echo "File does not exist"
fi
