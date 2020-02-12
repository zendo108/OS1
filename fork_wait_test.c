#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
        int x = 100;
        printf("x in parent is equal to %d\n", x);
        x = x + 10;
        printf("adding 10 to x before creating child process\n");
        int p = fork();
        if(p<0)
                exit(1);
        else if(p==0)
                {
                        printf("this is inside child process id %d parent id %d and x = %d\n", getpid(), getppid(), x);
                        x += 20;
                        printf("x after adding 20 inside child = %d",x);
                        printf("\n");
                }
        else if(p>0)
                {
                        printf("this is inside parent process id %d and x = %d\n", getpid(), x );
                        x += 20;
                        printf("x after adding 20 inside child = %d",x);
                        printf("\n");
                        wait(NULL);//wait for child process to finish
                }
        return 0;
}
