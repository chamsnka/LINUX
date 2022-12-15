#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc , char *argv[])
{
	if(argc<0)
	{
		printf("less argument error");
	}
	// declare the variable 
	int fd;
	char buffer[100];
	// open a file in the read mode 
	fd=open(argv[1],O_RDONLY);
	//less than 0 its fail to open 
	if(fd<0)
	{
		perror("open fails");
		exit(0);
	}
	// read the data by char
	read(1,&buffer,1);
	write("%s",buffer);
	close(fd);
	
}
   
    
