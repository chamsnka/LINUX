//Program to demonstrate thread_safe:
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
//golbal declare
char * HELLO_MESSAGE; 

//declare the func1
void *threadfun1()
{
	HELLO_MESSAGE = "HELLO WORLD!";
}
//declare the fun2
void *threadfun2()
{
	for(int i = 0; i < 13; i++)
	{
		printf("\n%c \n",HELLO_MESSAGE[i]); 
	}
}

int main()
{
	//declaring the variable	
	pthread_t p1;
	pthread_t p2; 
	// creating pthread p1,p2 and calling fun1 &2 thread
	pthread_create(&p1,NULL,&threadfun1,NULL);
	pthread_create(&p2,NULL,&threadfun2,NULL);
	//execution for specified period 
	sleep(1); 
	pthread_exit(NULL);
	return 0;
}
