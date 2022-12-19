//program to demonstrate producer consumer problem using mutex and semaphore
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>

//declaring varible 
int count=0;
char buffer[6];
sem_t empty;
sem_t full;
pthread_mutex_t produce;
pthread_mutex_t consume;

// fun defination for producre1
void *producer1(void  *arg)
{
	int in=0;
	char ch='a';
	// infinite while loop
	while(1)
	{
		sem_wait(&empty);
		pthread_mutex_lock(&produce);
		buffer[in]=ch;
		in=(in+1)%6;
		sleep(0.5);
		if(in==0)
		{
			ch='a';
			printf("producer 1:%s\n",buffer);
		}
		else
		{
			ch++;
		}
		pthread_mutex_unlock(&produce);
		sem_post(&full);
	}
	pthread_exit(exit);
}
// func declartion for producer2
void *producer2(void *arg)
{
	int in=0;
	char ch='A';
	while(1)
	{
		sem_wait(&empty);
		pthread_mutex_lock(&produce);
		buffer[in]=ch;
		in=(in+1)%6;
		sleep(0.5);
		if(in==0)
		{
			ch='A';
			printf("producer 2:%s\n",buffer);
		}
		else
		{
			ch++;
		}
		pthread_mutex_unlock(&produce);

		sem_post(&full);
	}
	pthread_exit(exit);
}


// fun declaration for consumer 
void *consumer(void  *arg)
{
	int out=0;
	char data[6];
	while(1)
	{
		sem_wait(&full);
		pthread_mutex_lock(&consume);
		data[out]=buffer[out];
		out=(out+1)%6;
		//	sleep(1);
		if(out==0)

			printf("\tconsumer:%s\n",data);
		pthread_mutex_unlock(&consume);

		sem_post(&empty);

	}
	pthread_exit(exit);
}

int main (int argc, char *argv[])
{
	//declaring variable 
	pthread_t p1, p2,p3;
	sem_init(&full,0,0);

	sem_init(&empty,0,6);
	pthread_mutex_init(&produce,NULL);
	pthread_mutex_init(&consume,NULL);

	//creating a thread  p1,p2 for producer
	if (pthread_create(&p1, NULL, &producer1, NULL) != 0) 
	{
		perror("thread create failed");
		return 1;
	}

	if (pthread_create(&p2, NULL, &producer2, NULL) != 0)
	{
		perror("thread create failed");
		return 2;
	}
	// creating a thread p3 for consumer
	if(pthread_create(&p3,NULL,&consumer,NULL)!=0)
	{
		perror("thread create failed");
		return 3;
	}

	// joining the thread p1,p2,p3
	if (pthread_join(p1, NULL) != 0) 
	{
		perror("thread failed to join");
		return 4;

	}
	if (pthread_join(p2, NULL) != 0)
	{
		perror("thread failed to join");
		return 5;
	}
	if (pthread_join(p3, NULL) != 0)
        {
                perror("thread failed to join");
                return 6;
        }

	sem_destroy(&full);
	sem_destroy(&empty);
	pthread_mutex_destroy(&produce);
	pthread_mutex_destroy(&consume);


	return 0;
}

