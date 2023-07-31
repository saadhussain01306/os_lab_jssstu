#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 30

int main()
{
    int fd, n;
    char buffer[BUFFER_SIZE];
    fd = open("sample.txt", O_RDWR);

    printf("File descriptor is %d\n", fd);
    if (fd == -1)
    {
        printf("Failed to open file.\n");
        exit(0);
    }

    printf("Reading first 10 characters from file: \n");
    n = read(fd, buffer, 10);
    write(1, buffer, n); // 1 is fd
    printf("\n");

    printf("Skipping 5 characters from current position in the file: \n");
    lseek(fd, 5, SEEK_CUR);
    n = read(fd, buffer, 10);
    write(1, buffer, n);
    printf("\n");

    printf("Going to 5th last character in the file: \n");
    lseek(fd, -5, SEEK_END);
    n = read(fd, buffer, 5);
    write(1, buffer, n);
    printf("\n");

    printf("Going to the 3rd character in the file: \n");
    lseek(fd, 3, SEEK_SET);
    n = read(fd, buffer, 5);
    write(1, buffer, n);
    printf("\n");

    return 0;
}
/*
The tree missed the days the kids used to come by and play. 
It still wore the tire swing the kids had put up in its branches years ago although both the tire and the rope had seen better days. 
The tree had watched all the kids in the neighborhood grow up and leave, and it wondered if there would ever be a time when another child played and laughed again under its branches. 
That was the hope that the tree wished every day as the swing gently swung empty in the wind.
  */
/*
output:-
gcc 5_a.c
/a.out sample.txt
File descriptor is 3
Reading first 10 characters from file: 
The tree m
Skipping 5 characters from current position in the file: 
 the days 
Going to 5th last character in the file: 
ind.

Going to the 3rd character in the file: 
 tree
*/
