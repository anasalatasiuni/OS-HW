#!/bin/bash

# compile the program
gcc ex2.c -pthread -o ex2

# check if the user intered n as arguemnt
if [ "$#" -eq 1 ]; then
    n=$1
else
    # give initial value of 10 if n is not passed
    n=10
fi
echo "running ex2 with n = $n"
# run the excutable
echo $n | ./ex2