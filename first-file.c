#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid = getpid();
  pid_t ppid = getppid();

  printf("ID текущего процесса: %d\n", pid);
  printf("ID родительского процесса: %d\n", ppid);

  return 0;
}