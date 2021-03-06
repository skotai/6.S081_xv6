# pingpong命令
写一个程序，使用UNIX系统调用在两个进程之间通过一对管道''ping-pong''一个字节，每个方向一个。

父进程应该向子进程发送一个字节；子进程应该打印"<pid>: received ping"，其中<pid>是它的进程ID，将管道上的字节写给父进程，然后退出；

父进程应该从子进程读取字节，打印"<pid>: received pong"，然后退出

## 最终结果的样子
$pingpong

$<pid>: received ping

$<pid>: received pong

## 思路
1：建立2个数组p1，p2，父进程用p1写,子进程用p2写，并且用pipe函数把2个数组弄成管子（p[1]用来写入，p[0]用来读出）

2：用fork创建子进程，并用pid记录此时此刻是父还是子(pid==0（子）pid!=0（父）)

3：write(a,b,c):把长为c的b写入a，read(a,b,c):把a读进b中，b长为c

4：对于父进程，要把"ping"写进p1管子中，并且读取p2管子的内容

5：对于子进程，要把"pong"写进p2管子中，并且读取p1管子的内容

## 代码
```
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
        write(p1[1],"ping",4);//写入p1管子中
        read(p2[0],buf,50);//读取p2管子内容
        printf("%d: received %s\n", getpid(), buf);
    }else{//子程序
        read(p1[0],buf,50);//读取p1管子内容
        printf("%d: received %s\n", getpid(), buf);
        write(p2[1],"pong",4);//写入p2管子中
    }
    exit(0);
}
```
