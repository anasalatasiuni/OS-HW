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
            if (A1[j] == A1[j+1]){
                if(A2[j] == A2[j+1]){
                    swap(&A1[j], &A1[j+1]);
                    swap(&A2[j], &A2[j+1]);
                }
            }
            else if(A1[j] > A1[j+1]){
                swap(&A1[j], &A1[j+1]);
                swap(&A2[j], &A2[j+1]);
            }
        }
    }
}

int main(){
    
    int n, arrivalTime[30], burstTime[30], temp[30], t = 0, cnt = 0, s_p = 0;
	scanf("%d",&n);
    for (int i = 0 ; i < n ; i++ ){
	scanf("%d%d",&arrivalTime[i],&burstTime[i]);	
	}
    bubble_sort(n, arrivalTime,burstTime);

    for(int i=0;i<n;i++)
        temp[i] = burstTime[i];

    int completionTime[30];
    int turnAroundTime[30];
    int waitingTime[30];
    float sum1 = 0, sum2 = 0;

    burstTime[29] = 1e4;

    for(t=0;cnt!=n;t++){
        s_p = 29;
        for(int i=0;i<n;i++)
            if(burstTime[i] < burstTime[s_p] && (arrivalTime[i] <= t && burstTime[i] > 0))
                s_p = i;
        
        burstTime[s_p]--;

        if(!burstTime[s_p]){
            cnt++;
            waitingTime[s_p] = t + 1 - arrivalTime[s_p] - temp[s_p];
            turnAroundTime[s_p] = t + 1 - arrivalTime[s_p];

            sum1 += waitingTime[s_p];
            sum2 += turnAroundTime[s_p];

            completionTime[s_p] = turnAroundTime[s_p] + arrivalTime[s_p];
        }
    }

    float averageWaitingTime = sum1/n;
    float averageTurnAroundTime = sum2/n;

    for(int i=0;i<n;i++)
        printf("P%d:\nArrival Time: %d\nBurst Time:%d\nCompletion Time:%d\nTurn Around Time:%d\nWaiting Time:%d\n---\t---\t---\t---\t---\t---\n", i+1, arrivalTime[i], temp[i], completionTime[i], turnAroundTime[i], waitingTime[i]); 
    printf("Average Turnaround Time: %f\n", averageTurnAroundTime);
    printf("Average Waiting Time: %f\n", averageWaitingTime);
    return 0;
}
