#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	
    pid_t x = fork();
    clock_t t = clock();
    if(x<0)
	    return EXIT_FAILURE;
    else if (x==0){
			printf("Child1 ==> ID: %d and Parent ID: %d\n",getpid(), getppid());
            t= clock() - t;
            printf("Child1 Execution Time : %f ms\n", (float) t / CLOCKS_PER_SEC*1e6);
            return EXIT_SUCCESS;
		}
	    else{
		pid_t y = fork();
		t = clock();
		
		if(y<0)
		return EXIT_FAILURE;
		else if (y==0){
		printf("Child2 ==> ID: %d and Parent ID: %d\n",getpid(), getppid());
		t= clock() - t;
            printf("Child2 Execution Time : %f ms\n", (float) t / CLOCKS_PER_SEC*1e6);
                return EXIT_SUCCESS;
		}else {
			printf("Parent ==> ID: %d and Parent ID: %d\n",getpid(), getppid());
		t= clock() - t;
            printf("Parent Execution Time : %f ms\n", (float) t / CLOCKS_PER_SEC*1e6);
                return EXIT_SUCCESS;
			}
	    }
    
    return 0;
}
