#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: Write a menu driven shell script to
# Create a file
# To read from a file
# To append to an existing file
# To delete file
# Rename alredy existing file

#!/bin/bash

while true; do
	echo "Menu:"
	echo "1. Create a file"
	echo "2. Read from a file"
	echo "3. Append to a file"
	echo "4. Delete a file"
echo "5. Rename a file"
	echo "6. Exit"
	echo -n "Enter your choice: "
	read choice

	case $choice in
    	1)
        	echo -n "Enter the name of the file to create: "
        	read filename
        	touch "$filename"
        	echo "File '$filename' created."
        	;;
    	2)
        	echo -n "Enter the name of the file to read: "
        	read filename
        	if [ -f "$filename" ]; then
            	cat "$filename"
        	else
            	echo "File '$filename' does not exist."
        	fi
        	;;
    	3)
        	echo -n "Enter the name of the file to append to: "
        	read filename
        	if [ -f "$filename" ]; then
            	echo -n "Enter the text to append: "
            	read text
            	echo "$text" >> "$filename"
            	echo "Text appended to '$filename'."
        	else
            	echo "File '$filename' does not exist."
        	fi
        	;;
    	4)
        	echo -n "Enter the name of the file to delete: "
        	read filename
        	if [ -f "$filename" ]; then
            	rm "$filename"
            	echo "File '$filename' deleted."
        	else
            	echo "File '$filename' does not exist."
        	fi
        	;;
    	5)
        	echo -n "Enter the current name of the file: "
        	read oldname
        	if [ -f "$oldname" ]; then
            	echo -n "Enter the new name for the file: "
            	read newname
              mv "$oldname" "$newname"
            	echo "File renamed from '$oldname' to '$newname'."
        	else
            	echo "File '$oldname' does not exist."
        	fi
        	;;
    	6)
        	echo "Exiting. Goodbye!"
        	exit
        	;;
    	*)
        	echo "Invalid choice. Please select a valid option."
        	;;
	esac
done
