#!/bin/bash


Alphabet=(a b c d e f g h i j k l m n o p q r s t u v w x y z)

#declaration functions


rm -r result

# $1: 1, write L to file, 0, write N&M 
# $2: L or  N
# $3: M
function ProduceData()
{

	# producing test data
	# the input format has been described in readme

	if [ $1 = 1 ]
	then
		echo $2 > in
	else
		N=$2
		M=$3
		echo $N >> in	
		for ((i=0; i<N-1; i++))
		do
			((index = $RANDOM % ${#Alphabet[@]}))
			printf "${Alphabet[$index]} " >> in 
		done
		echo ${Alphabet[(($RANDOM % ${#Alphabet[@]}))]} >> in
		echo $M >> in
	fi

}

function Compile()
{
	rm -r arraystack.out
	gcc ArrayStack.c stack.c -o arraystack.out -g 

	echo "Compile complete ..."
}



# execute

Compile 

# produce input data

while read L
do
	# new cycle test case
	echo "" >> result
	echo "-------------------" >> result 
	printf "Routine\tTicks\n" >> result 

	rm -r in

	ProduceData 1 $L	
	
	while read N
	do
		if [ $N = 0 ]
		then 
			break;
		fi

		read M
		ProduceData 0 $N $M	
	done	

	echo "Producing data complete ..."

	# start to test
	echo "Start to test ..."
	./arraystack.out < in >> result
	
done < in.in


echo "Test complete ..."
echo 'U can see the test result by type `cat result`'


cat result
