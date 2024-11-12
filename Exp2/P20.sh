#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: Write a shell script to display following information
# Display Processor Information
# Display REal Time Main Memory Status
# Display Real Time Process Status
# Exit

while true; do
	echo "1) Processor info"
	echo "2) Real-time main memory status"
	echo "3) Real-time process status"
	echo "4) Quit"

  read -p "Choose an option: " ch

	case $ch in
    	1)
        	echo "Processor info:"
        	lscpu
        	;;
    	2)
        	echo "Real-time main memory status:"
        	cat /proc/meminfo
        	;;
    	3)
        	echo "Real-time process status:"
        	ps
        	;;
    	4)
        	echo "Quit"
        	break
        	;;
    	*)
        	echo "Invalid output"
        	;;
	esac
done
