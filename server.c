//program to demonstrate server

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

 

int main(int argc,char* argv[])
{
    //variable declaration 
    int sockfd,newsockfd,portno,n;
    struct sockaddr_in server_addr,client_addr;
    char buf[1024];
    socklen_t len;

    //check for appropriate no. of command line input
    if(argc<2)
    {
        printf("provide required command line...\n");
        exit(1);
    }
    
    portno=atoi(argv[1]);
    sockfd=socket(AF_INET,SOCK_STREAM,0);

    //check if socket is created properly
    if(sockfd<0)
    {
        printf("error in opening socket\n");
        exit(1);
    }

    //build the structure of server address
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=INADDR_ANY;
    server_addr.sin_port=htons(portno);

 
    //bind the socket to the address and port no specified in structure

    if(bind(sockfd,(struct sockaddr *) &server_addr,sizeof(server_addr))<0)
        printf("error in binding address\n");

 
    //listen to any incoming client

    listen(sockfd,10);
    len=sizeof(client_addr);
    newsockfd=accept(sockfd,(struct sockaddr *)&client_addr,&len);

    //check if the client socket is created properly
   if(newsockfd<0)
    {
        printf("error in accepying in request\n");
        exit(1);
    }

    while(1)
    {
        //clear buffer
        bzero(buf,1024);
        
        //now read some data from the client
        n=read(newsockfd,buf,1024);
        
        if(n<0)
        {
            printf("error in reading\n");
            exit(1);
        }

            //print client requests data
            printf(" client-->%s",buf);
            
            //clear buffer
            bzero(buf,1024);

            //sending some data to the client
            fgets(buf,1024,stdin);
            n=write(newsockfd,buf,1024);
            
            if(n<0)
            {
                printf("error in writing..\n");
                exit(1);
            }

            //detect end of conversation

            if(!strncmp("bye",buf,3))
            break;    

    }
        close(newsockfd);
        close(sockfd);
        return 0;

}

 
