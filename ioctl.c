// program to demonstrate ioctl:
#include<stdio.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<linux/input.h>
int main(int argc , char *argv[])
{

	int fd;
	char var[100];
	//to open a file in read_mode:
	fd=open(argv[1],O_RDONLY);

	if(fd<0)
	{
		printf("the file not be open");
		return -1;
	}
	//to find a device name 
	ioctl(fd,EVIOCGNAME(sizeof(var)),var);
	printf("the input device name:\%s\n",var);
	return 0;
}

