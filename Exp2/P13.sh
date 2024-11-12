#!/bin/bash
#Programmer name: Nathan John Cordeiro
#Program title: Using switch case print the capitals given the state name.

echo "Choose the options for getting the capital of the states:"
echo "1) Maharashtra"
echo "2) Goa"
echo "3) Karnataka"
echo "4) Tamil Nadu"
echo "5) West Bengal"

read choice

case $choice in
	1) echo "Mumbai";;
	2) echo "Panjim";;
	3) echo "Bangalore";;
  4) echo "Chennai";;
	5) echo "Kolkata";;
	*) echo "Invalid option";;
esac
