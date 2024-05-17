#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (pid == 0) {
    printf("Дочерний процесс: ID текущего процесса: %d, ID родительского процесса: %d\n", getpid(), getppid());
  } else if (pid > 0) {
    printf("Родительский процесс: ID текущего процесса: %d, ID родительского процесса: %d\n", getpid(), getppid());
    printf("ID дочернего процесса: %d\n", pid);
  } else {
    perror("fork");
  }

  return 0;
}