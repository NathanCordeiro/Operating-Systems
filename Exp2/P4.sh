#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: To print the number table.

echo "Enter the number -"
read n

i=1
 
while [ $i -le 10 ]
do
res=`expr $i \* $n`

echo "$n * $i = $res"
 
((++i))
 
done
