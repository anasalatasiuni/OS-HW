#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const int MAX_SIZE = 256;
    char arr[MAX_SIZE];
    gets(arr);
    int i = 0;
    while(i < strlen(arr)){
        if(arr[i] == '.')
            break;
        i++;
    }
    i--;
    putchar('"');
    while(i >= 0){
        putchar(arr[i]);
        i--;
    }
    putchar('"');

    return 0;
}
