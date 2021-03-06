# Sleep命令
实现xv6的UNIX程序sleep；你的sleep应该暂停一个用户指定的tick数。tick是xv6内核定义的一个时间概念，即来自定时器芯片的两次中断之间的时间

## 最终结果的样子
$sleep x
-------一段延迟后------
$
## 思路
1：接受的参数必须是2个(argc==2)，一个是sleep，一个是秒数，如果不符合，则报错
2：把存放在argv[1]里的字符串秒数通过atoi转换成int
3：通过sleep()函数进行时间的中断

## 代码
```
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{
  if(argc==2){
      int time=atoi(argv[1]);
      sleep(time);
  }else{
    fprintf(2, "Error\n");
  }
  exit(0);
}
```
