#!/bin/bash

gcc ToPostfix.c stack.c basic.c -o topostfix.out -g
echo 'Compile complete ...'

./topostfix.out < in > in.in 
echo 'Test complete ...'
echo 'This routine produces file in.in, you can test it with Postfix.c'

