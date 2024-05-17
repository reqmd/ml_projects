#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  pid_t pid = getpid(); 
  pid_t ppid = getppid(); 

  printf("Идентификатор текущего процесса: %d\n", pid);
  printf("Идентификатор родительского процесса: %d\n", ppid);
  int child_pid = fork();

  if (child_pid == 0) { 
    char *argv[] = {"new_process", NULL}; 

    perror("execvp");
    exit(1);
  } else if (child_pid > 0) { 
    printf("Идентификатор дочернего процесса: %d\n", child_pid);
    wait(NULL); 
  } else { 
    perror("fork");
    exit(1);
  }

  return 0;
}
