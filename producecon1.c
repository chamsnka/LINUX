//Program to demonstrate producer consumer problem synchronization 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

// variable declaration 
int count=0;
char buffer[5];

//func defination for producer 
void *producer()
{
	// decalaring variable 
	int in=0;
	char ch='a';
	// infinite while loop
	while(1)
	{
		while(count==5);
		buffer[in]=ch;
		in=(in+1)%5;
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
		count++;

	}
	pthread_exit(exit);
}
//fun defination for consumer			
void *consumer()
{
	int out=0;
	char data[5];
	while(1)
	{
		while(count==0);
		data[out]=buffer[out];
		out=(out+1)%5;
	//	sleep(1);
		if(out==0)
		
			printf("\t consumer:%s\n",data);
			count--;
	}
	pthread_exit(exit);
}

int main (int argc, char *argv[])
{
	// thread declaration
	pthread_t p1, p2;
	// creating p1 thread for producer
	if (pthread_create(&p1, NULL, &producer, NULL) != 0) 
	{
		perror("thread create failed");
		return 1;
	}
	//creating p2 thread for consumer
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

	printf("thread joined sucess");

	return 0;
}

