#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h>
#include <unistd.h>
#include <math.h> 
#include <pthread.h>
#include <semaphore.h>
/*#define N 2       define the total number of processes we want  */
#define NUM_THREADS     2

float total=0;    /* Set global variable */   

sem_t mutex; 

void *compute() 
{   
    long i; 
    float oldtotal=0, result=0; 
 
    for(i=0;i<4;i++) 
      result = sqrt(1000.0) * sqrt(1000.0); 
     
    //wait 
    sem_wait(&mutex); 
    printf("Result is %f\n",result); 

    oldtotal = total; 
    total = oldtotal + result; 
 
    //signal
    printf("Total is %f\n",total); 
 
    sem_post(&mutex);
    pthread_exit(NULL); 
} // code to be continued
int main()  
{ 
    sem_init(&mutex, 0, 1);
    long i;
    pthread_t thread;
    float result=0; 

    printf("\n"); 

   
    for(i=0;i<NUM_THREADS;i++){         
	    fprintf (stderr, "Process Id for process %ld is %d\n", i, (int) getpid ());
	    pthread_create (&thread, NULL, compute, NULL);
            pthread_join(thread, NULL);
    }   

   
    sem_destroy(&mutex); 
       

    pthread_exit(NULL);
 }  

