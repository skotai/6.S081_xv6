#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(){
    int p1[2],p2[2];
    pipe(p1);
    pipe(p2);
    int pid=fork();
    char buf[50];
    if(pid!=0){//父进程
        write(p1[1],"ping",4);
        read(p2[0],buf,50);
        printf("%d: received %s\n", getpid(), buf);
    }else{
        read(p1[0],buf,50);
        printf("%d: received %s\n", getpid(), buf);
        write(p2[1],"pong",4);
    }
    exit(0);
}