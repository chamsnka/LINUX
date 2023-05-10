//WAP to create zombie process

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

//main function
int main()
{
	// variable declarition
	pid_t p;
	p=fork();
	//child process
	if(p==0)
	{
		printf(" i am child PID %d\n",getpid());
		printf(" my parent PID is %d\n", getppid());
	}
	//parent process
	else if(p>0)

	{
		//wait(NULL);
		
		sleep(30);
		printf("i am parent  PID %d\n",getpid());
		printf(" my grand parent PID is %d\n",getppid());
	}
	else
	{
		printf("process not created\n");
	}
	return 0;

}
