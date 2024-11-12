#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Display the following pattern
# 1 2 3 4
# 2 3 4
# 3 4
# 4


N=4

for ((i=1; i<=N; i++)); do
    for ((j=i; j<=N; j++)); do
        echo -n "$j "
    done
    echo
done
