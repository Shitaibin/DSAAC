#!/bin/bash

gcc BlancingSymbols.c ../stack.c ../basic.c -o blancing.out -g
echo 'Compile complete ...'
./blancing.out < in.in 
echo 'Test complete ...' 
