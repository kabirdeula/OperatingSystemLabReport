# Get process ID of child and parent process

## Source Code

```c
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
```

## Output

![Process ID of Parent and Child](./LR03.png)