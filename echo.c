#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char*argv[])
{
	//if argument less than 2 its fail 
	if(argc<2)
	{
		printf("less argument error");
		exit(0);
	}

	//declare the variable 
	int i,count=0;
	for(i=1;i<argc;i++)
	{
		//print number of arguments 
		write(1,argv[i],strlen(argv[i]));
		write(1," ",1);
		
	}
}

