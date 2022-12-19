//Program to demonstrate producer consumer problem using semaphore
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

// decalare the variable 
int count = 0;
char buffer [26];
sem_t empty, full;

// func defination for producer 
void *producer(void  *arg)
{
	// decalre the variable 
	int in = 0;
	char  ch = 'a';
	while(1)
	{
		sem_wait(&empty);
		buffer[in] = ch;
		in = (in+1)%26;
	//	sleep(1);
		if(in==0)
		{
			ch='a';
			printf("producer:%s\n",buffer);
		}
		else
		{
			ch++;
		}
		sem_post(&full);
	}
	pthread_exit(exit);
}

// fun defination for consumer 
void *consumer(void  *arg)
{
	//decalre the variable 
	int out=0;
	char data[26];
	while(1)
	{
		sem_wait(&full);
		data[out]=buffer[out];
		out=(out+1)%26;
	//	sleep(1);
		if(out==0)

			printf("\tconsumer:%s\n",data);
		sem_post(&empty);

	}
	pthread_exit(exit);
}

int main (int argc, char *argv[])
{
	pthread_t p1, p2;
	//create full semaphore
	sem_init(&full,0,0);
	//create empty semaphore
	sem_init(&empty,0,26);
	//create a p1 thread and calling func  producer
	if (pthread_create(&p1, NULL, &producer, NULL) != 0) 
	{
		perror("thread create failed");
		return 1;
	}

	//create a p2 thread and calling func consumer 
	if (pthread_create(&p2, NULL, &consumer, NULL) != 0)
	{
		perror("thread create failed");
		return 2;
	}

	// joining the thread p1 and p2
	if (pthread_join(p1, NULL) != 0) 
	{
		perror("thread failed to join");
		return 3;

	}

	if (pthread_join(p2, NULL) != 0)
	{
		perror("thread failed to join");
		return 4;
	}
	//destroying the full and empty after process complete
	sem_destroy(&full);
	sem_destroy(&empty);

	return 0;
}

