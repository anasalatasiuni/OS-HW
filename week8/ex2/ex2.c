#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>     
#include <memory.h>

int main() {

    int* ptr;
    int sz = 100 * 1024 * 1024;

    for (int i = 0; i < 10; i++) {
        ptr = malloc(sz);
        memset(ptr, 0, sz);
        sleep(1);
    }

    printf("Done\n");
}
/*
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 2  0      0 1524112  15860 440688    0    0   679    70  676 1111  3  2 95  0  0
 0  0      0 1438020  15860 440688    0    0     0     0  947 1106  0  2 98  0  0
 1  0      0 1304996  15860 440688    0    0     0     0  974 1126  2  1 98  0  0
 0  0      0 1232120  15860 440688    0    0     0     0 1029  996  1  1 98  0  0
 0  0      0 1126028  15860 440688    0    0     0     0 1210 1113  1  2 98  0  0
 0  0      0 1023784  15860 440688    0    0     0     0 1362 1573  1  1 98  0  0
 0  0      0 919960  15860 440688    0    0     0    20  976 1234  1  1 98  0  0
 0  0      0 822864  15860 440688    0    0     0     0  764  963  0  1 99  0  0
 0  0      0 720240  15868 440688    0    0     0    32  964 1145  1  1 97  0  0
 1  0      0 616460  15868 440672    0    0     0     0  970  936  0  1 98  0  0
 0  0      0 514236  15868 440580    0    0     0     0 1329 1729  1  1 98  0  0
Done
*/
/*
	The changes in swap sizes were not tracked by my system. 
	when memory isn't freed, there are significant changes in the amount of free memory.
 */
