## :dart: Tasks to accomplish  
1. Rewrite the program below to use 𝑃𝑂𝑆𝐼𝑋 threads rather than 𝑓𝑜𝑟𝑘. 
2. The behaviour of threaded version of the program and the analysis should lead identifying a potential problem with the compute function  when it is used in a threaded manner. 
3. Need to ensure that each process performs only a subset of work and this local result is merged into the actual result.   

## :key: Hint
This problem can be resolved using a Mutual Exclusion or a Semaphore.  

## 💻 Initial given program

```
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#define N 2 /* define the total number of processes we want */

float total=0; /* Set global variable */

int compute() /* compute function just does something. */
{
 int i;
 float oldtotal=0, result=0;
 /* for a large number of times */
 for(i=0;i<2000000000;i++)
 result = sqrt(1000.0) * sqrt(1000.0);

 /* Print the result – should be no surprise */
 printf("Result is %f\n",result);
 /* to keep a running total in the global variable total */

  oldtotal = total;
 total = oldtotal + result;
 /* Print running total so far. */
 printf("Total is %f\n",total);
 return 0;
} // code to be continued

int main()
{
 int pid[N], i, j;
 float result=0;
 printf("\n"); /* bit of whitespace */
 /* to loop and create the required number of processes */
 /* NOTE carefully how only the child process is left to run */
 for(i=0;i<N;i++)
 { /* Do the fork and catch it if it/one fails */
 if((pid[i]=fork())==-1) exit(1);
 /* a child? Yes, do our computation */
 else if(pid[i] > 0)
 { /* give a message about the proc ID */
 printf("Process Id for process %d is %d\n",i,getpid());

 /* call the function to do some computation */
 compute();

 /* after computation, quit or process creation will explode!*/
 break;
 }
 }
 return 0;
} 
```
