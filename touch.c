#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
	//declare the variable 
	int fd,i;
	//if argument is one the file is not created
	if(argc < 2)
	{
		printf("less argument error");
	}
	for(i=0;i<argc;i++)
	{
		//creating the file according to argument
		fd= open(argv[i],O_CREAT,0777);
	}
	if(fd<0)
	{
		perror("file open error");
		exit(0);
	}
}

       
