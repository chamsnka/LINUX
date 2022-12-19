// program to demonstrate using mutex even_odd:
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int min,max;
pthread_mutex_t mutex;

// definition of even_odd
void *even_odd() 
{
	//locking the mutex
	pthread_mutex_lock(&mutex);
	// using loop find odd-even
	for (; min<= max;)
	{
		if(min % 2 == 0)
		{
			printf("even=%d\n",min);
		}
		if(min % 2==1)
		{

			printf("odd=%d\n",min);
		}
		min++;
	
	}
	//unlocking the mutex when complete
	pthread_mutex_unlock(&mutex);

}


int main() 
{
	// declare the variable 
	pthread_t t1, t2;
	printf("enter min and max value: ");
	scanf("%d%d",&min,&max);
	// initialize the mutex
	pthread_mutex_init(&mutex,NULL);

	//create the thread 1and fun call 
	if (pthread_create(&t1, NULL, &even_odd, NULL) != 0) 
	{
		return 1;
	}
	// create the thread 2 & fun call
	if (pthread_create(&t2, NULL, &even_odd, NULL) != 0) 
	{
		return 2;
	}
	// join the thread t1 and t2 
	if (pthread_join(t1, NULL) != 0) 
	{
		return 5;
	}
	
	if (pthread_join(t2, NULL) != 0) 
	{
		return 6;
	}
	// destroy the thread after complete
	pthread_mutex_destroy(&mutex);

	return 0;
}
