#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t pid, pidsub;
    int i,j;
    printf("only parent before fork\n");
    for(i=0;i<5;i++){
        pid=fork();
        if(pid==0){
            if((i%2)==0){
                printf("I am the child no %d\n",i);
                int num_gc= 3; /*7.1*/
                for(j=0;j<num_gc;j++){
                    pidsub = fork();/*7.2*/
                    if(pidsub==0){
                        printf("I am grandchild num %d of even child no %d\n",j,i);
                        exit(0);/*7.3*/
                    }
                } //for j
                for(j=0;j<num_gc;j++){
                    pidsub=fork();
                    if(pidsub ==0){
                        printf("I am grandchild num %d of even child no %d\n",j,i);
                        exit(0);
                    }//for j
                }
                while(wait(NULL)!=-1);/*7.4*/
                exit(0);
            }/*even child*/else{//odd child
                printf("I am the child no %d\n",i);
                int num_gc= 4; /*7.5*/
                for(j=0;j<num_gc;j++){
                    pidsub=fork();
                    if(pidsub ==0){ /*7.6*/
                        printf("I am grandchild num %d of odd child no %d\n",j,i);
                        exit(0);/*7.7*/
                    }//for j
                    while(wait(NULL)!=-1);
                    //exit(0); /*7.8*/
                }
                //exit(0); /*7.9*/
            } //odd child
        } //if pid==0
    } //for i
    while(wait(NULL)!=-1);
    return 0;
}
