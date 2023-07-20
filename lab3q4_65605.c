#include <stdio.h>
int main() {
	int a;
	int b = 0 ,c = 0;
	do {
		printf("enter a number : ");
		scanf("%d",&a);
		if(a > 0){
			b += a;
			c += 1;
		}
	} while (a > 0);
	printf("summation = %d\n",b);
	printf("average = %.2f",(float)b/(float)c);
}
