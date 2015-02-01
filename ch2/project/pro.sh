#!/bin/bash

echo "start ..."
for ((c=1000;c<=100000000;c*=10))
do
	./sum $c >> resultpro	
	echo "finshed $c"
done
