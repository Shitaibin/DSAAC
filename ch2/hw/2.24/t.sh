#!/bin/bash

while read line
do
	echo $line | ./a.out
done < in
