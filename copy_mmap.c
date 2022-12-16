
#include<stdlib.h>
#include<string.h>
// for input and output file
#include<stdio.h>
// for creating and reading a file
#include<fcntl.h>
// for using mmap
#include<sys/mman.h>
//for Linux access
#include <unistd.h>
// for fstat 
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
	// condition to check whether the required argument are passed or not
	if(argc<3)
	{
		printf("ERROR:Less argument passed\n");
		return 0;
	}
	// Declaration of variables 
	int sfd, dfd;
	char *src, *dest;
	// stat is used to find the size of an file
	// SOURCE  
	struct stat s;   
	//opening and Reading an file  
	sfd = open(argv[1], O_RDONLY);

	// calculating the size of source file
	int size = lseek(sfd,0,SEEK_END);

	// mapping the source file     
	src = mmap(NULL, 1, PROT_READ, MAP_PRIVATE, sfd, 0);

	// creating an destination file
	dfd = creat(argv[2], 0777);
	// allocating the size of des_file by calculating the size of source_file
	ftruncate(dfd, size+1);
	// Opening an destination file in read/write mode
	dfd = open(argv[2], O_RDWR | O_CREAT ,0777);

	// mapping destination file
	dest = mmap(NULL, 1, PROT_READ | PROT_WRITE, MAP_SHARED, dfd, 0);

	// COPY 
	/* from source to destination , number of bytes*/
	for(int i = 0; i<size; i++)
	{
		write(dfd,&src[i], 1);
	}

	// unmapping the files from source
	munmap(src, s.st_size);
	munmap(dest, s.st_size);

	close(sfd);
	close(dfd);



	return 0;
}
