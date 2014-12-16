#!/bin/bash


Alphabet=(a b c d e f g h i j k l m n o p q r s t u v w x y z)

# $1: the first pair?
# $2: N
# $3: M
function ProduceData()
{

	# producing test data
	# the input format has been described in readme

	if [ $1 = 1 ]
	then
		echo $N > in
	else
		echo $N >> in
	fi

	for ((i=0; i<N-1; i++))
	do
		((index = $RANDOM % ${#Alphabet[@]}))
		printf "${Alphabet[$index]} " >> in 
	done
	echo ${Alphabet[(($RANDOM % ${#Alphabet[@]}))]} >> in
	echo $M >> in
}

function Compile()
{
	rm -r basicstack.out
	gcc BasicStack.c stack.c basic.c -o basicstack.out -g 

	rm -r optstack.out
	gcc OptStack.c optstack.c basic.c -o optstack.out -g 

	echo "Compile complete ..."
}


# execute

Compile 

# produce input data

while read N
do
	# new cycle test case
	echo "" >> result
	echo "-------------------" >> result 
	printf "Routine\tTicks\n" >> result 
	read M
	ProduceData 1 $N $M	
	
	while read N
	do
		if [ $N = 0 ]
		then 
			break
		fi

		read M
		ProduceData 0 $N $M	
	done	

	echo "Producing data complete ..."

	# start to test
	./basicstack.out < in >> result
	./optstack.out < in >> result
	
done < in.in


echo "Test complete ..."
echo 'U can see the test result by type `cat result`'


cat result 
