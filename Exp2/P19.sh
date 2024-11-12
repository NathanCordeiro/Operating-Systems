#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: Write a shell script for the following program
# List Of Files
# Number of users of the system
# Todays date
# Quit to UNIX

while true; do
	echo "Enter your choice: 1) List files 2) Number of users 3) Display today's date 4) Exit"
	read ch
	case $ch in
    	1) echo "File directories:"
       	ls ;;
    	2) echo "Number of users logged in:"
       	who | wc -l ;;
    	3) echo "Date:"
       	date ;;
    	4) echo "Exit"
       	exit ;;
    	*) echo "Invalid input" ;;
	esac
done
