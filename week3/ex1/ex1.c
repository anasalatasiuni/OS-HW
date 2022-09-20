#include <stdio.h>
#include <stdlib.h>


int foo(int age){
	int result;
	
	result = 2022 - age ;
	
	return result;
}

int main(){

	
	const int x = 10;
	const int *q = &x;
	
	int * const  p = malloc(sizeof(int)*5);	
	
	for (int i = 0 ; i< 5; i++){
	*(p+i) = x;
	}
	
	
	for (int i = 0 ; i< 5; i++){
	printf("%p\n",(p+i));	
	}
	
	for (int i = 0 ; i< 5; i++){
	scanf("%d",p+i);	
	}
	
	for (int i = 0 ; i< 5; i++){
	*(p+i) = foo(*(p+i));	
	}
	
	free(p);
	
	return EXIT_SUCCESS;
}
