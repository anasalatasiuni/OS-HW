#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct page
{
    int counter;
    int id;
};

int main(int argc, char *argv[]) 
{
    if(argc<=1) {
        printf("Error: please pass the input as an argument.\n");
        return 0;
    }
    const int n = atoi(argv[1]);
    struct page memory[n];
    for(int i=0;i<n;i++){
        memory[i].counter = -1;
        memory[i].id = -1;
	}
    FILE *File;
    File = fopen("Lab 09 input.txt", "r");
    int tmp, hit, miss;
    miss = hit = 0;
    fscanf (File, "%d", &tmp);
    while(!feof(File)){
        bool found = 0;
        int min_ind = 0;
        for(int i=0;i<n;i++){
            if(memory[min_ind].counter>memory[i].counter){
                min_ind = i;
            }
            memory[i].counter = memory[i].counter>>1;
            if(memory[i].id == tmp){
                found = 1;
                memory[i].counter += (1<<7);
				hit++;
            }
        }
        if(!found){
            memory[min_ind].id = tmp;
            memory[min_ind].counter = (1<<7);
            miss++;
        }
        fscanf (File, "%d", &tmp);
    }
    double ratio = (double)hit/miss;
    printf("Hits: %d\nMisses: %d\nRatio of Hit/Miss : %lf\n",hit,miss,ratio);
    return 0;
}
