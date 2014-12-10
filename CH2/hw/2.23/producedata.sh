#!/bin/bash

for i in 1000 10000
do
	echo "$i " >> $i.in
	for ((j=0; j < i; j++))
	do
		echo "$j " >> $i.in
	done
	echo "55" >> $i.in
done
