#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define clear_buffer() while(getchar()!='\n')

int sum=0;
int main(){
	pid_t pid;
	int i = 0,num;
	printf("Enter a positive number : ");
	scanf(" %d",&num);
	if (num <= 0) {
		printf("You did noot enter a positive number\n");
		exit(1);
	}
	if ((pid = fork()) > 0){
		for(i=1;i <= num;i++)
			sum +=i;	
	}
 	else {
		for (i=1;i<=2*num;i++)
			sum+=i;
		printf("I am child my sum = %d\n",sum);
		exit(0);
	}
	wait(NULL);
        printf("I am child my sum = %d\n",sum);
	return 0;
}
