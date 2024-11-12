#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: Give commands to perform tasks given below in linux operating system
# View memory status in kilobytes
# view PID of a specific process
# To view list of all logged in users
# To forcefully delete directory having sub directories and files 

while true; do
	echo "Menu:"
	echo "1. View memory status in KB"
	echo "2. View PID of a specific process"
	echo "3. View list of all logged in users"
	echo "4. Forcefully delete a directory having subdirectories"
	echo "5. Exit"
	echo -n "Enter your choice: "
	read choice

	case $choice in
    	1)
        	echo "Memory status in KB:"
        	free -k
        	;;
    	2)
        	echo -n "Enter the name of the process: "
        	read process_name
        	pgrep "$process_name" || echo "No process found with name '$process_name'."
        	;;
    	3)
        	echo "List of all logged in users:"
        	who
        	;;
    	4)
        	echo -n "Enter the path of the directory to delete: "
        	read directory_path
        	if [ -d "$directory_path" ]; then
            	rm -rf "$directory_path"
            	echo "Directory '$directory_path' and its contents have been deleted."
        	else
            	echo "Directory '$directory_path' does not exist."
        	fi
        	;;
    	5)
        	exit 0
        	;;
	    *)
        	echo "Invalid choice, please try again."
        	;;
	esac
done
