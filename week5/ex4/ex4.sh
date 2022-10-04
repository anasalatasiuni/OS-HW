#!/bin/bash

gcc ex4.c -pthread -o ex4

echo -n "the answer is "
./ex4 10000000 8
echo ''
for m in 1 2 4 10 100; do
    echo -n "time when m = $m:"
    time ./ex4 10000000 $m > /dev/null
done