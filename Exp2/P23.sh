#!/bin/bash
#Programmer name: Nathan John Cordeiro
# Display the following patterns :
# * * * * *
# * * * *
# * * *
# * *
# *


for ((i=5; i>=1; i--)); do
    for ((j=1; j<=i; j++)); do
        echo -n "* "
    done
    echo
done

