#!/bin/bash

g++ test.c avltree.cc -o avltest.out -g 
echo 'Compile complete'
./avltest.out
echo 'Test complete'

