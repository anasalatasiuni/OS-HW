#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <string.h>     
#include <memory.h>

int main() {

    int* ptr;
    int sz = 100 * 1024 * 1024;

    for (int i = 0; i < 10; i++) {
        ptr = malloc(sz);
        memset(ptr, 0, sz);

        struct rusage cur;

        getrusage(RUSAGE_SELF, &cur);

        printf("%ld\n", cur.ru_maxrss);
        
        sleep(1);
    }

    printf("Done\n");
}
//The size of the memory increases every second.
