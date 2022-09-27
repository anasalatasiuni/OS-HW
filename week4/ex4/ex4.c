#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
	char a[101];
		scanf("%[^\n]s",a);
		if(fork() == 0){	
			system(a);
			return EXIT_SUCCESS;
		}
	


	return 0;
}
