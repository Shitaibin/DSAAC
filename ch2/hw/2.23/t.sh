#!/bin/bash

while read LINE
do
	echo $LINE | ./a.out
done < in
