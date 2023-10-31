##! /usr/bin/bash #linux
#! /bin/bash #OSX

string=""
#read -p "Number of numbers: " number
#read -p "Maximum number: " max
i=100
number=20
max=100
#while [[ "$i" != '100' ]];
#do
	number=$i
	while [[ "$number" != '0' ]];
	do
		string=$string" "$((1 + RANDOM % $max))
		((number--))
#	done
#	((i++))
#	./push_swap $string | grep "Stack a not" && echo $i
done
./push_swap $string | grep "Stack"
#echo $string