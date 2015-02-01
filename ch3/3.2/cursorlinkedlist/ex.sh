#!/bin/bash

rm -r testcursor
gcc test.c cursor.c -g -o testcursor
./testcursor
