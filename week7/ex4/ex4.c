#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* myRealloc(int* ptr, size_t oldsize, size_t newsize) {
    int* newptr = malloc(newsize);
    oldsize < newsize ? memcpy(newptr, ptr, oldsize) : memcpy(newptr, ptr, newsize);
    free(ptr);
    return newptr;
}

int main() {
    int N;
    scanf("%d", &N);
    int *arr = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        arr[i] = i;
    }

    int newN;
    scanf("%d", &newN);

    arr = myRealloc(arr, N * sizeof(int), newN * sizeof(int));


    for (int i = 0; i < newN; i++) {
        arr[i] = i;
        i == newN-1?printf("%d\n", arr[i]):printf("%d ", arr[i]);
    }
}
