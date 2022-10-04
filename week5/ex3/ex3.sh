#!/bin/bash

gcc ex3.c -pthread -o ex3

echo -n "the answer is "
./ex3 10000000 8
echo ''
for m in 1 2 4 10 100; do
    echo -n "time when m = $m:"
    time ./ex3 10000000 $m > /dev/null
done