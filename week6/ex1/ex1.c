#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int n, int A1[], int A2[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if (A1[j] > A1[j+1]){
              swap(&A1[j], &A1[j+1]);
              swap(&A2[j], &A2[j+1]);
            }
        }
    }
}

int main(){
    int n, arrivalTime[30], burstTime[30];
	scanf("%d",&n);
    for (int i = 0 ; i < n ; i++ ){
	scanf("%d%d",&arrivalTime[i],&burstTime[i]);	
	}
    bubble_sort(n, arrivalTime, burstTime);

    int completionTime[30];
    int turnAroundTime[30];
    int waitingTime[30];

    completionTime[0] = arrivalTime[0] + burstTime[0];
    turnAroundTime[0] = completionTime[0] - arrivalTime[0];
    waitingTime[0] = 0;

    for(int i=1;i<n;i++){
        completionTime[i] = burstTime[i] + completionTime[i-1];
        if(completionTime[i-1] < arrivalTime[i])
            completionTime[i] = completionTime[i] + arrivalTime[i] - completionTime[i-1];
        turnAroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnAroundTime[i] - burstTime[i];
    }

    float sum = 0;
    for(int i=0;i<n;i++)
        sum += waitingTime[i];
    float averageWaitingTime = sum/n;

    sum = 0;
    for(int i=0;i<n;i++)
        sum += turnAroundTime[i];
    float averageTurnAroundTime = sum/n;

    for(int i=0;i<n;i++)
        printf("P%d:\nArrival Time: %d\nBurst Time:%d\nCompletion Time:%d\nTurn Around Time:%d\nWaiting Time:%d\n---\t---\t---\t---\t---\t---\n", i+1, arrivalTime[i], burstTime[i], completionTime[i], turnAroundTime[i], waitingTime[i]);
    
    printf("Average Turnaround Time: %f\n", averageTurnAroundTime);
    printf("Average Waiting Time: %f\n", averageWaitingTime);
    return 0;
}
