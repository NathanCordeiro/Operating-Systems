#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: To display square of first 20 numbers.

i=1
 
while [ $i -le 20 ]
do
res=$(( $i * $i ))

echo "$i ^ 2 = $res"
 
((++i))
 
done
