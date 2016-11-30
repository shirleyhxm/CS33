// treethread.c

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

void* thread(void* pN);

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Incorrect number of operands.");
    return 1;
  }

  long N = strtol(argv[1], NULL, 10);
  thread((void*)&N);
  return 0;
}

void* thread(void* pN) {
  long n = *((long *)pN);
  if (n > 1) {
    n--;
    pthread_t left;
    pthread_t right;
    pthread_create(&left, NULL, thread, (void*)&n);
    pthread_create(&right, NULL, thread, (void*)&n);
    pthread_join(left, NULL);
    pthread_join(right, NULL);
  }
  printf("Hello, world!\n");
  return NULL;
}
