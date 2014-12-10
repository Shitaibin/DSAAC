#!/bin/bash

rm -r teststack
gcc TestLinkedStack.c stack.c -o teststack
./teststack
