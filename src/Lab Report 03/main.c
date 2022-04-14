#include<stdio.h>
#include<unistd.h>

int main(){
    int pid;
    pid = fork();

    if(pid == 0){
        printf("Process ID of child: %d\n", getpid());
    }else{
        printf("Process ID of parent: %d\n", getpid());
    }
}