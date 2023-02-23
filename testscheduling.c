// Test that fork fails gracefully.
// Tiny executable so that the limit can be filling the proc table.

#include "types.h"
#include "user.h"

int is_prime(int number) {
  int i;
  for (i = 2; i * i <= number; i++) {
    if (number % i == 0)
      return 0;
  }
  return 1;
}

int nth_prime(int n) {
  int counter = 0;
  int i;
  if (n == 1)
    return 2;
  for (i = 3;; i += 2) {
    if (is_prime(i)) {
      counter++;
      if (counter == (n - 1)) {
        printf(1, "the prime of %d is %d", n, i);
        return i;
      }
    }
  }
}

void testscheduling(void) {
  int pid;

  printf(1, "\nFork test iniciado\n");

  // Criando o primeiro processo
  pid = fork(40);
  if (pid == 0) {
    printf(1, "\n\nPrimeiro processo filho executando!\n");
    nth_prime(250000);
    printf(1, "Primeiro processo filho terminou!\n");
    exit();
  }

  // Criando o segundo processo
  pid = fork(20);
  if (pid == 0) {
    printf(1, "Segundo processo filho executando fibonacci!\n");
    nth_prime(250000);
    printf(1, "Segundo processo filho terminou!\n");
    exit();
  }

  // Criando o terceiro processo
  pid = fork(10);
  if (pid == 0) {
    printf(1, "Terceiro processo filho executando fibonacci!\n\n");
    nth_prime(250000);
    printf(1, "Terceiro processo filho terminou!\n");
    exit();
  }
}

int main(void) {
  testscheduling();
  exit();
}
