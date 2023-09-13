#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int notDone = 1; int cnt = 0;
void mySIGhandler(int sig) {
    notDone = 0;
}

void printCnt(int sig) {
    printf("it takes %d\n", cnt);
}

int main(void) {
    pid_t pid = fork();

    if (pid == 0) {
        printf("child created\n");
        signal(SIGUSR1, printCnt);
        while(notDone){
            cnt++;
        }
        printf("this line should not be shown\n");
        exit(0);
    } else {
        signal(SIGALRM,mySIGhandler); 
        printf("parent wait for SIGALRM\n");
        sleep(5);
        kill(pid, SIGUSR1);
        usleep(100000);
        kill(pid, SIGKILL);
    }
    return 0;
}
