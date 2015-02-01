#!/bin/bash

while read line
do
	echo $line | ./changed
done < in
