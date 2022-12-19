//Program to demonstrate odd_even_thread
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

 
// global variable 
int min,max;
// func defination for even number
void* even()
{
	// loop for range 
    for (; min <= max;) 
    {
	// calculate for even num
        if(min % 2 == 0)
        {
            printf("even=%d\n",min);
            min++;
            sleep(1);
        }
    }
}

 
// function defination for odd number 
void* odd() 
{
    for (; min <= max;) 
    {
	//calculate for odd number 
        if(min % 2 == 1)
        {
            printf("odd=%d\n",min);
            min++;
            sleep(1);
        }
    }
}

 


int main(int argc, char *argv[]) 
{
	//declaring the thread variable 
    pthread_t t1, t2;
    printf("enter min and max value: ");
    
    scanf("%d %d",&min,&max);
    // create and calling the fun thread1
    if (pthread_create(&t1, NULL, &even, NULL) != 0) 
    {
        return 1;
    }
    //create and calling the fun thread2

    if (pthread_create(&t2, NULL, &odd, NULL) != 0) 
    {
        return 2;
    }

 
    //join the thread for blocking thread one 
    if (pthread_join(t1, NULL) != 0) 
    {
        return 5;
    }
    // join the thread for blocking thread two
    if (pthread_join(t2, NULL) != 0) 
    {
        return 6;
    }

 

    return 0;
}
