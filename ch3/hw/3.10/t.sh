#!/bin/bash



gcc 3.10.c -o 3.10.out -g
echo 'Compile complete'


while read M
do
	read N
	echo "$M $N" > in
	for ((i=0; i<N; i++))
	do
		echo $i >> in
	done

	./3.10.out < in
	echo 'A test complete' 
done < in.in 
	

