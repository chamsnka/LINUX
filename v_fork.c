#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //creating the child process
    pid_t pid = vfork();  

    printf("parent process pid before if...else block: %d\n", getpid());

    if (pid == 0)
    {  
        //checking if this is the a child process
        printf("This is the child process and pid is: %d\n\n", getpid());
        exit(0);
    }
    else if (pid > 0) 
    {  
        //parent process execution
        printf("This is the parent process and pid is: %d\n", getpid());
    } 
    else 
    {
        printf("Error while forking\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}
