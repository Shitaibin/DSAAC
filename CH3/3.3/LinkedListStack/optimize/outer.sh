#!/bin/bash

while read N
do 
	read M
	printf "%d\n%d\n" $N $M > _tmpfile 	
	./t.sh < _tmpfile 
done < in.in

rm -f _tmpfile


