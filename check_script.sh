##! /usr/bin/bash #linux
#! /bin/bash #OSX

string=""
#read -p "Number of numbers: " number
#read -p "Maximum number: " max
i=2
number=20
max=100
while [[ "$i" != '1000' ]];
do
	number=$i
	while [[ "$number" != '0' ]];
	do
		string=$string" "$((1 + RANDOM % $max))
		((number--))
	done
	i=$(($i+100))
	./push_swap $string | grep "Stack a" && echo $i
done
#./push_swap $string #| grep "Stack"
#echo $string