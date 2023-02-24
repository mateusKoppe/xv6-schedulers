// Test that fork fails gracefully.
// Tiny executable so that the limit can be filling the proc table.

#include "types.h"
#include "user.h"

#define SEARCH_NTH_PRIME 250000

// Worst possible implementation to find a prime
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
        printf(1, "", i); // Anti optimization
        return i;
      }
    }
  }
}

void testscheduling(void) {
  int pid;

  printf(1, "schedulingtest - the next lines should be displayed in order\n");
  int tickets[] = { 40, 20, 10 };
  int tickets_amount = sizeof(tickets)/sizeof(tickets[0]);

  for (int i = 0; i < tickets_amount; i++) {
    pid = fork(tickets[i]);
    if (pid == 0) {
      nth_prime(SEARCH_NTH_PRIME);
      printf(1, "%d - proccess finished.\n", i+1);
      exit();
    }
  }
}

int main(void) {
  testscheduling();
  exit();
}
