#!/bin/bash

rm -r testlist
gcc test.c list.c -g -o testlist
./testlist
