#!/bin/bash


# executable program
find . -name *.out > to_del

# input data, because some is very big
find . -name in >> to_del

# .o file
find . -name *.o >> to_del

# .swp file
find . -name *.swp >> to_del

cat to_del 
echo '* using cat to_del | xargs rm to delete them.' 
