
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t my_pid, child_pid, parent_pid;
    child_pid = fork();
    if (child_pid < 0)
    {
        printf("\nFork failed, exiting!!\n");
        exit(1);
    }

    if (child_pid == 0)
    {
        // This is the child process part
        printf("\n[CHILD] This is the child process.\n");
        my_pid = getpid();
        parent_pid = getppid();
        printf("[CHILD] My pid is %d\n", my_pid);
        printf("[CHILD] My parent's pid is %d\n", parent_pid);
        printf("[CHILD] Exiting\n");
        exit(1);
    }
    else
    {
        // This is the parent process part
        printf("\n[PARENT] This is the parent process\n");
        my_pid = getpid();
        parent_pid = getppid();
        printf("[PARENT] My pid is %d\n", my_pid);
        printf("[PARENT] My parent's pid is %d\n", parent_pid);
        printf("[PARENT] Sleeping for 10 seconds\n");
        sleep(10);
        printf("\n[PARENT] Child process with pid = %d has ended, but still has an entry in the process table.\n", child_pid);
        printf("[PARENT] It is therefore a Zombie process\n");
    }
    return 0;
}
/*gcc zombie.c
  ./a.out
  PARENT] This is the parent process
[PARENT] My pid is 3072
[PARENT] My parent's pid is 1944
[PARENT] Sleeping for 10 seconds

[CHILD] This is the child process.
[CHILD] My pid is 3073
[CHILD] My parent's pid is 3072
[CHILD] Exiting

[PARENT] Child process with pid = 3073 has ended, but still has an entry in the process table.
[PARENT] It is therefore a Zombie process
*/
