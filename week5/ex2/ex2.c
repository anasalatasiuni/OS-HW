#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct Thread{
	pthread_t id;
	int i;
	char message[256];
};

void *fun(void *args){
	struct Thread *thread_ptr = (struct Thread *) args;
	printf("Thread %lld says: %s\n",(long long)thread_ptr->id, thread_ptr->message); 
}

int main(){
	int n;
	scanf("%d",&n);
	struct Thread *arr[n];
	for(int i=0;i<n;i++){
		arr[i] = (struct Thread *) malloc(sizeof(struct Thread));
		arr[i]->i = i;
		sprintf(arr[i]->message, "Hello from thread %d", i);
		pthread_create(&(arr[i]->id), NULL, fun, (void *)arr[i]);

		/* this is the fix:
		pthread_join will force the program to wait till the thread finish its job
		after adding this line the threads id became equal.*/
		pthread_join(arr[i]->id,NULL);
	}
	pthread_exit(NULL);
	for(int i=0;i<n;i++){
		free(arr[i]);
	}
	return 0;
}
