#! /usr/bin/bash

string=""
read -p "Number of numbers: " number
read -p "Maximum number: " max

while [[ "$number" != '0' ]];
do
	string=$string" "$((1 + RANDOM % $max))
	((number--))
done
./push_swap $string