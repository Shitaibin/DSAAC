#!/bin/bash

while read LINE
do
	echo $LINE | ./mbum
done < in


