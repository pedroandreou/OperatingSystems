#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(){

   pid_t Child1, Child2; 

   int cChild1 = 0; //counter for child1
   
   int cChild2 = 0; //counter for child2
   
   int cParent = 0; //counter for parent
   int i;

   (Child1 = fork()) && (Child2 = fork());

   //10 iterations of printing the processes
	for(i=0;i<10;i++){
	   if (Child1 == 0){ /*child process 1 */
             cChild1++;
	     printf("child %d process: counter=%d\n", getpid(), cChild1);
	   }
           else { /* this is the parent process */
		       if (Child2 == 0){ /*child process2 */
                             cChild2++;
			     printf("child %d process: counter=%d\n", getpid(), cChild2);
		       }
                       else{
                            cParent++;
                            printf("parent %d process: counter=%d\n", getppid(), cParent);
		       }
           }
        sleep(1);
        }

return 0;
}

