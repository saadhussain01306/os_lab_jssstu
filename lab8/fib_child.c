#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
  int k = 2, n1, n2, n3;
  void *shmptr;
  int shm_fd = shm_open("OS", O_CREAT | O_RDWR, 0666);
  ftruncate(shm_fd, 4096);
  shmptr = mmap(0, 4096, PROT_WRITE, MAP_SHARED, shm_fd, 0);

  printf("\nChild Printing:\n");
  int i = atoi(argv[1]);
  n3 = n1 = 0;
  n2 = 1;
  for (k = 1; k <= i; k++)
  {
    n3 = n1 + n2;
    sprintf(shmptr, "%d ", n1);
    printf("%d ", n1);
    shmptr += strlen(shmptr);
    n1 = n2;
    n2 = n3;
  }

  return 0;
}
/*
gcc fib_parent.c -o parent
 gcc fib_child.c -o fib
./parent 10

Child Printing:
0 1 1 2 3 5 8 13 21 34 
[PARENT] Child process completed

Parent printing:
0 1 1 2 3 5 8 13 21 34 
*/
