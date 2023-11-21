##! /usr/bin/bash #linux
#! /bin/bash #OSX

string=""
#read -p "Number of numbers: " number
#read -p "Maximum number: " max
i=1000
j=$i
number=100
k=$number
max=2750000
result=0
sum=0
average=0


while [[ "$i" != '0' ]];
do
	string=""
	number=$k
	while [[ "$number" != '0' ]];
	do
		string=$string" "$((1 + RANDOM % $max))
		((number--))
	done
	result=$(./push_swap $string | wc -l)
	echo result: $result
#	./push_swap $string | ./checker_linux $string
#	echo $string
	sum=$((result+sum))
	((i--))
done
average=$(($sum/$j))
echo "average: $average"
#./push_swap $string | wc -l #&& echo "number of elements $i" #grep "Stack a" && echo $i



#while [[ "$i" != '1000' ]];
#do
#	number=$i
#	while [[ "$number" != '0' ]];
#	do
#		string=$string" "$((1 + RANDOM % $max))
#		((number--))
#	done
#	i=$(($i+100))
#	./push_swap $string # | wc -l && echo "number of elements $i" #grep "Stack a" && echo $i
#done
#./push_swap $string #| grep "Stack"
#echo $string