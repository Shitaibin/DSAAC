#!/bin/bash

rm avltree.out
g++ testavltree.cc avltree.c -g -o avltree.out
echo 'Compile complete'

echo '-------------------------------' >> result
while read line
do
	echo $line > in
	./avltree.out < in >> result
	echo 'A test finished'
done < in.in
echo 'Test complete'
cat result
