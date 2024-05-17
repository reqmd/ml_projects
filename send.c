#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Использование: signal_sender <pid> <signal>\n");
    printf("  <pid> - идентификатор процесса-получателя\n");
    printf("  <signal> - сигнал для отправки (1 - SIGUSR1, 2 - SIGUSR2)\n");
    return 1;
  }

  int pid = atoi(argv[1]); 
  int signal_type = atoi(argv[2]); 

  int signal_number;
  if (signal_type == 1) {
    signal_number = SIGUSR1;
  } else if (signal_type == 2) {
    signal_number = SIGUSR2;
  } else {
    printf("Неверный тип сигнала. Должно быть 1 (SIGUSR1) или 2 (SIGUSR2).\n");
    return 1;
  }

  if (kill(pid, signal_number) != 0) {
    printf("Ошибка при отправке сигнала процессу %d.\n", pid);
    return 1;
  }

  printf("Сигнал %d отправлен процессу %d.\n", signal_number, pid);
  return 0;
}
