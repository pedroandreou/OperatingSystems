#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <signal.h>

struct my_msgbuf {
    long mtype;
    char mtext[200];
};
/*
*
*Function for checking that all the letters are capitals
*
*/
int Caps(char mtext[200]){
	for(int i =0; i< 200; i++){
		if( mtext[i] == 10){ //10 equals to ^J, escape character. It is always after the string.
			break;
                }
		if(!(mtext[i] >= 'A' && mtext[i] <= 'Z')){
			return -1; //if at least one letter is not capital
		}
        }
return 1; //if all the letters are capitals
}

void sigterm_handler(int sig)
{
    write(0, "ESCAPE FROM THE PLANET HAS BEEN ACCOMPLISHED!\n", 50);
}

int main(void)
{
   
    void sigterm_handler(int sig); /* prototype */
    struct my_msgbuf buf;
    int msqid;
    key_t key;
    struct sigaction sa;

    sa.sa_handler = sigterm_handler;
    sa.sa_flags = 0; // or SA_RESTART
    sigemptyset(&sa.sa_mask);

    if ((key = ftok("kirk3.c", 'B')) == -1) {
        perror("ftok");
        exit(1);
    }

    if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
        perror("msgget");
        exit(1);
    }

    /* CATCHING THE SIGTERM SIGNAL */
    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    /* displaying the pid so can be used to the other terminal */
    printf("PID %d:\n", getpid());
    
    printf("Enter lines of text, ^D to quit:\n");


    buf.mtype = 1; /* we don't really care in this case */

    while(fgets(buf.mtext, sizeof buf.mtext, stdin) != NULL) {
        int len = strlen(buf.mtext);

	if(Caps(buf.mtext) == 1){
		buf.mtype=2;
        }

        /* ditch newline at end, if it exists */
        if (buf.mtext[len-1] == '\n') buf.mtext[len-1] = '\0';

        if (msgsnd(msqid, &buf, len+1, 0) == -1) /* +1 for '\0' */
            perror("msgsnd");
    }

    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    return 0;
}
