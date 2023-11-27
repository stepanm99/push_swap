##! /usr/bin/bash #linux
#! /bin/bash #OSX

string=""
#read -p "Number of numbers: " number
#read -p "Maximum number: " max
i=1000
j=0
number=500
k=$number
max=2147483647
result=0
sum=0
average=0
temp=""
push_swap_output=""
checker_output=""
OK=0
KO=0


while [[ "$i" != '0' ]];
do
	string=""
	number=$k
	while [[ "$number" != '0' ]];
	do
		string=$string" "$((1 + RANDOM % $max))
		((number--))
	done
	push_swap_output=$(./push_swap $string)
	temp=$(wc -l <<< "$push_swap_output")
	checker_output=$(./checker_Mac $string <<< "$push_swap_output")
	if [ $temp != '1' ]
	then
		result=$temp
		((j++))
	else
		result=0
	fi
	if [ "$checker_output" == "OK" ]
	then
		((OK++))
	fi
	if [ "$checker_output" == "KO" ]
	then
		((KO++))
	fi
	sum=$((result+sum))
	((i--))
done
average=$(($sum/$j))
echo average:$average
echo samples: $j
echo OK: $OK
echo KO: $KO
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