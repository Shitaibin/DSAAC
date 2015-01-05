#!/bin/bash


gcc BSTTest.c bst.c -o bsttest.out -g
echo 'Compile complete'

./bsttest.out 
echo 'Test complete'

