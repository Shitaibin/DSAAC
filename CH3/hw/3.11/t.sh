#!/bin/bash


gcc 3.11.c ../BasicHeaderFile/list.c -o 3.11.out -g
echo 'Compile complete'

while read N
do
	echo $N > in
	for ((i=1; i<=N+1; i++))
	do
		echo $i >> in
	done
	echo 'Producing data complete'

	./3.11.out < in >> result
	echo 'A test complete'
done < in.in

cat result
