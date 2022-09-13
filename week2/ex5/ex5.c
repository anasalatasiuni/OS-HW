#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int MAX_SIZE = 256;

int tribonacci(int n){
    if(n == 0) return 0;
    if(n == 2 || n == 1) return 1;
    int result = 0;
    int c = 1, b = 1, a = 0;
    for(int i = 3 ;i <= n;i++){
        result = c + b + a;
        a = b;
        b = c;
        c = result;
    }
    return result;
}

int main()
{
    printf("tribonacci(34)= %d\n", tribonacci(34));
    printf("tribonacci(4)= %d\n", tribonacci(4));
    return 0;
}
