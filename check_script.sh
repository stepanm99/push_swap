##! /usr/bin/bash #linux
#! /bin/bash #OSX

string=""
#read -p "Number of numbers: " number
#read -p "Maximum number: " max
i=10
j=0
number=10
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

while [[ "$number" != "100" ]]
do
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
			((i--))
		else
			result=0
		fi
		if [[ "$result" != '1' ]]
		then
			if [ "$checker_output" == "OK" ]
			then
				((OK++))
			fi
			if [ "$checker_output" == "KO" ]
			then
				((KO++))
			fi
		fi
		sum=$((result+sum))
	done
	number=$k
	((number++))
	k=$number
	echo "----------- $number ---------------"
	average=$(($sum/$j))
	echo out: n: $number
	echo out: average:$average
	echo out: samples: $j
	echo out: OK: $OK
	echo out: KO: $KO
	i=10
	j=0
	max=2147483647
	result=0
	sum=0
	average=0
	temp=""
	push_swap_output=""
	checker_output=""
	OK=0
	KO=0
done

# average=$(($sum/$j))
# echo out: n: $number
# echo out: average:$average
# echo out: samples: $j
# echo out: OK: $OK
# echo out: KO: $KO
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
