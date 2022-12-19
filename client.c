// program to demonstrate client code
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>


int main(int argc,char * argv[])
{
	// variable declare
	int sockfd,portno;
	struct sockaddr_in server_addr;

	char buf[1024];

	//check for appropriate no. of command line input

	if(argc<3)
	{
		printf("provide required command line \n");
		exit(1);
	}
	portno=atoi(argv[2]);
	//socket is created
	sockfd=socket(AF_INET,SOCK_STREAM,0);

	//check if socket is created properly
	if(sockfd<0)
	{
		printf("error in opening socket\n");
		exit(1);
	}

	//build the structure of server address
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(portno);
	server_addr.sin_addr.s_addr=inet_addr(argv[1]);


	//connect to the server

	if(connect(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr))<0)
	{
		printf("connection failed\n");
		exit(1);
	}

	while(1)
	{
		//clear buffer
		bzero(buf,1024);
		
		//now write some data to the server
		fgets(buf,1024,stdin);
		n=write(sockfd,buf,strlen(buf));
		if(n<0)
		{
			printf("error in writing\n");
			exit(1);
		}

		//now read back from the sever
		bzero(buf,1024);//clear buffer
		n=read(sockfd,buf,1024);
		if(n<0)
		{
			printf("error in reading");
			exit(1);    
		}


		// print servers response
		printf(" \nserver--->%s",buf);


		// detect end of conversation
		if(!strncmp("bye",buf,3))
			//    exit(1);
			break;
	}    
	close(sockfd);
	return 0;

}

