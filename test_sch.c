#include "types.h"
#include "user.h"

#define FORKS 20

int main(){
  int pid, i, n;

  for (i = 0, n = 1; i < FORKS; i++, n+=20){
    pid = fork(n);
    if(pid == 0){
      for(;;){}
      exit();
    }
  }
  while(1){
    pid = wait();
    if(pid < 0) break;
  }
  exit();
}
