#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;
    char temp[50];

    // Optional
    if (argc < 2)
    {
        printf("\nThe file name is not passed\n");
        exit(1);
    }

    fp = fopen(argv[1], "r");

    // Optional
    if (fp == NULL)
    {
        printf("\nThe file does not exist.\n");
        exit(1);
    }

    while (!feof(fp))
    {
        fgets(temp, 50, fp);
        printf("%s", temp);
    }
    fclose(fp);
    return 0;
    }
/*gcc cat.c
  ./a.out file_name
*/
