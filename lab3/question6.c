#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int pfds1[2];
    int pfds2[2];

    pipe(pfds1);
    pipe(pfds2);

    pid_t pid;
	
        if (!fork()) { /* child */
	     dup2(pfds1[1], 1);
	     close(pfds1[0]);
	     close(pfds1[1]);
	     close(pfds2[0]);
	     close(pfds2[1]);
	     execlp("/bin/cat", "cat", "/etc/group", NULL);
	     
	}
	 else { /* parent */

		pid = fork();

	    	if (pid == 0) { /* child */
		    dup2(pfds1[0], 0);
		    dup2(pfds2[1], 1);
	            close(pfds1[0]);
		    close(pfds1[1]);
		    close(pfds2[0]);
		    close(pfds2[1]);
		    execlp("/usr/bin/sort", "sort", NULL);
	    	} 
		/* parent's part below */ 
	        dup2(pfds2[0], 0);
		close(pfds1[0]);
		close(pfds1[1]);
	        close(pfds2[0]);
		close(pfds2[1]);
	        execlp("/usr/bin/cut","cut", "-f3", "-d:", NULL);
        }   	

    return 0;
}
