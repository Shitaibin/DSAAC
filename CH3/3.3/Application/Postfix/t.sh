#!/bin/bash

gcc Postfix.c stack.c basic.c -o postfixS.out -g
echo 'Compile complete ...'

./postfixS.out < in 
echo 'Test complete'
