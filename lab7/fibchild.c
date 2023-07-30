#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
    int k = 1, n1, n2, n3;
    void *shmptr;
    int shmid = shmget((key_t)1122, 4096, 0666);
    shmptr = shmat(shmid, NULL, 0666);
    int i = atoi(argv[1]);

    printf("\nChild Printing:\n");
    n3 = n1 = 0;
    n2 = 1;
    for (k = 0; k < i; k++)
    {
        n3 = n1 + n2;
        sprintf(shmptr, "%d ", n1);
        printf("%d ", n1);
        shmptr += strlen(shmptr);
        n1 = n2;
        n2 = n3;
    }

    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
