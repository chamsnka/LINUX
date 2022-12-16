#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/mman.h>
int main(int argc,char*argv[])
{
	if(argc<2)
	{
		printf("less argument error");
		return 0;
	}
        //declaring a variable 
	int fd;
	char *red;
	struct stat n;
	// opening a file in read mode
	fd=open(argv[1],O_RDONLY);
	//if file discrepter is less than zero then file is not present
	if(fd<0)
	{
		printf("file open error");
		return -1;
	}
	// to get the status information about that
	fstat(fd,&n);
        // reading the data from the file 
	red=mmap(0,n.st_size,PROT_READ,MAP_SHARED,fd,0);
		for(int i=0;i<n.st_size;i++)
		{
			//displaying the data to output console
			write(1, &red[i], 1);
		}
	// closeing the file  
	close(fd);
}
