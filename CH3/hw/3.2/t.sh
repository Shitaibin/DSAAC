#!/bin/bash

gcc 3.2.c ../BasicHeaderFile/list.c -o 3.2.out -g
echo 'Compile complete'
./3.2.out < in > result
echo 'Test complete'
cat result 
