#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title:  Generate the fibonacci series for the number of terms entered by the user.

echo "Enter number of terms to generated :"
  read n
  x=0
  y=1
  i=2
  echo "Fibonacci Series for $n terms :"
  echo "$x"
  echo "$y"
  while [ $i -lt $n ]
  do
  	i=`expr $i + 1 `
  	z=`expr $x + $y `
  	echo "$z"
  	x=$y
  	y=$z
  done
