#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int x = (argv[1][0]) - '0';
	for(int i=0;i< x;i++){
	    fork();
	    sleep(5);
    }
    return 0;
}
