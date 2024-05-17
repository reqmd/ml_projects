#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
  char message[] = "Приветствую!"; 

  void sigusr1_handler(int sig) {
    printf("\nПолучен сигнал SIGUSR1! Меняю сообщение.\n");
    strcpy(message, "Добрый день!"); 
  }

  void sigusr2_handler(int sig) {
    printf("\nПолучен сигнал SIGUSR2! Меняю сообщение.\n");
    strcpy(message, "Вечер добрый!"); 
  }

  signal(SIGUSR1, sigusr1_handler);
  signal(SIGUSR2, sigusr2_handler);

  while (1) {
    printf("%s\n", message); 
    sleep(1); 
  }

  return 0;
}