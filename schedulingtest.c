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


int anti_optimization = 0;
int nth_prime(int n) {
  int counter = 0;
  int i;
  if (n == 1)
    return 2;
  for (i = 3;; i += 2) {
    if (is_prime(i)) {
      counter++;
      if (counter == (n - 1)) {
        anti_optimization++;
        return i;
      }
    }
  }
}

void testscheduling(void) {
  int pid;

  printf(1, "schedulingtest - the next lines should be displayed in order\n");

  // Criando o primeiro processo
  pid = fork(40);
  if (pid == 0) {
    nth_prime(250000);
    printf(1, "1 - proccess finished.\n");
    exit();
  }

  // Criando o segundo processo
  pid = fork(20);
  if (pid == 0) {
    nth_prime(250000);
    printf(1, "2 - proccess finished.\n");
    exit();
  }

  // Criando o terceiro processo
  pid = fork(10);
  if (pid == 0) {
    nth_prime(250000);
    printf(1, "3 - proccess finished!\n");
    exit();
  }
}

int main(void) {
  testscheduling();
  exit();
}
