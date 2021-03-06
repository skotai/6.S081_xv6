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