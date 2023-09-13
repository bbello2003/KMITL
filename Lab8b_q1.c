#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#define SIZE 10
#include <unistd.h>

int main() {
	int pfd[2];
	int nread;
	int pid;
	char buf[SIZE];
	char inbuf[SIZE*2];
	pipe(pfd);
	printf("write pipe id = %d\n", pfd[1]);
	printf("read file id = %d\n", pfd[0]);
	pid = fork();
	if(pid == 0) {
		close(pfd[1]);
		while((nread = read(pfd[0], buf, SIZE)) != 0)
			if(nread > 11)
				printf("avoid overflow no conversion %s to int\n",buf);
			else
				printf("child recieved %s. After + 5 = %d\n",buf,atoi(buf) + 5);
		close(pfd[0]);
	} else {
		close(pfd[0]);
		sprintf(inbuf,"%ld",123456789012);
		write(pfd[1], inbuf, strlen(inbuf) + 1);
		close(pfd[1]);
		wait(NULL);
	}
	return 0;
}
