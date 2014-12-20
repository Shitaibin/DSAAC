#!/bin/bash

gcc ToPostfix.c stack.c basic.c -o topostfix.out -g
echo 'Compile complete ...'

./topostfix.out < in > result 
echo 'Test complete ...'

