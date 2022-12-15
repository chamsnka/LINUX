#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
 int main(int argc,char *argv[])
{
	int fd1,fd2;
	char buffer[1024];
	int ch;
	//opening a for readonly:
	fd1=open(argv[1],O_RDONLY);

        if(fd1<0)
        {
                perror("open fails\n");
                exit(0);
        }
        //open file in a write mode:
	fd2=open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(fd2<0)
	{
		perror("open fails\n");
		exit(0);
	}
	//loop for copying from one file to another
	while(read(fd1,buffer,1))
	{
		//display a file in another
		write(fd2,buffer,1);

	}
	//closing file
	close(fd1);
	close(fd2);
}


