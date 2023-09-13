#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

signed long prev_computed, i;

void SIGhandler(int sig){
	printf("\nReceived a ");
	printf("SIGUSR1. The max n is ");
	printf("%ld! = %ld\n", i-1, prev_computed);
	exit(0);
}
int main(void){
	signed long cur_value;

	printf("2 power n:\n");
	signal(SIGUSR1, SIGhandler);
	prev_computed = 1;
	for(i = 1; ; i++){
		cur_value = prev_computed * i;
		if(cur_value < prev_computed)
			raise(SIGUSR1);
		prev_computed = cur_value;
	}
	return 0;
}
