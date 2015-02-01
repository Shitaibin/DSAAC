#!/bin/bash


Alphabet=(a b c d e f g h i j k l m n o p q r s t u v w x y z)

N=1000
((M=$N/2)) # alter the relationship between N and M, you can get different test result

# Read N, M
echo "Input N and M in two lines"
read N
read M

# producing test data
# the input format has been described in readme
echo $N > in
for ((i=0; i<N-1; i++))
do
	((index = $RANDOM % ${#Alphabet[@]}))
	printf "${Alphabet[$index]} " >> in
done
echo ${Alphabet[(($RANDOM % ${#Alphabet[@]}))]} >> in
echo $M >> in
echo "Producing data complete ..."

# compile 
rm -r basicstack.out
gcc BasicStack.c stack.c -o basicstack.out -g 
echo "Compile complete ..."

# test it
echo "Start to test ..."
echo "" >> result
echo "--------------------------" >> result
./basicstack.out < in >> result
echo "Test complete ..."
echo 'U can see the test result by type `cat result`'



