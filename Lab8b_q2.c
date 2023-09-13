#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
	FILE *file_desc = fopen("aaa.txt","w");
	int fd = fileno(file_desc);
	printf("current file descriptor id is %d\n",fd);
	dup2(fd, STDOUT_FILENO);
	printf("please read this line in aaa.txt\n");
	close(fd);
	return 0;
}
