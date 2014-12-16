#!/bin/bash

gcc PostfixAdvanced.c stack.c basic.c -o postfixA.out -g
echo 'Compile complete ...'

./postfixA.out < in
./postfixA.out < in.in 
echo 'Test complete'
