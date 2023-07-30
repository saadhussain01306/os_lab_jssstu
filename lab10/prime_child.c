#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int shmfd = shm_open("OS", O_CREAT | O_RDWR, 0666);
    ftruncate(shmfd, 4096);
    void *shmptr = mmap(0, 4096, PROT_WRITE, MAP_SHARED, shmfd, 0);
    printf("\nChild Printing:\n");
    for (int i = a; i <= b; i++)
    {
        int flag = 1;
        for (int j = i / 2; j >= 2; j--)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf("%d ", i);
            sprintf(shmptr, "%d ", i);
            shmptr += (strlen(shmptr));
        }
    }
}
/*
gcc prime_parent.c -o parent
gcc prime_child.c -o prime
./parent 10 20

Child Printing:
11 13 17 19 
[PARENT] Child process completed

Parent printing:
11 13 17 19 
*/
