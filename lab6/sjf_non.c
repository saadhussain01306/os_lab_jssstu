#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int Id, AT, BT, CT, TAT, WT, isCompl;
} pro;

pro p[15];

void main()
{
    int n, total_WT = 0, total_TAT = 0;
    float avg_WT = 0, avg_TAT = 0;
    int idleTime = 0;
    printf("\nEnter the number of processes:\n");
    scanf("%d", &n);
    printf("\nEnter the arrival time and burst time of the process:\n");
    printf("AT BT\n");
    for (int i = 0; i < n; i++)
    {
        p[i].Id = (i + 1);
        scanf("%d%d", &p[i].AT, &p[i].BT);
        p[i].isCompl = 0;
    }

    int minIndex, minBT, completed = 0, curTime = 0;

    printf("\nGantt Chart:\n\n");
    while (completed != n)
    {
        minIndex = -1;
        minBT = 9999;
        for (int i = 0; i < n; i++)
        {
            if (p[i].AT <= curTime && p[i].isCompl == 0)
            {
                if (p[i].BT < minBT || (p[i].BT == minBT && p[i].AT < p[minIndex].AT))
                {
                    minBT = p[i].BT;
                    minIndex = i;
                }
            }
        }
        if (minIndex == -1)
        {
            curTime++; // If no process which is not completed is present at the current time increment it.
            idleTime++;
        }
        else
        {
            // As the process is not preempted, the process executes tillit is completed, i.e., for it's full BT.
            if (idleTime > 0)
            {
                printf("| Idle till %d", idleTime);
                idleTime = 0;
            }
            curTime += p[minIndex].BT;
            p[minIndex].CT = curTime;
            p[minIndex].TAT = p[minIndex].CT - p[minIndex].AT;
            p[minIndex].WT = p[minIndex].TAT - p[minIndex].BT;
            total_TAT += p[minIndex].TAT;
            total_WT += p[minIndex].WT;
            p[minIndex].isCompl = 1;
            completed++;
            printf("| P%d (%d) %d", p[minIndex].Id, p[minIndex].BT, p[minIndex].CT);
        }
    }
    printf("|\n");
    avg_TAT = (float)total_TAT / n;
    avg_WT = (float)total_WT / n;

    // Printing the table of processes with details
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].Id, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }
    printf("\nAverage TAT = %.2f\nAverage WT = %.2f\n", avg_TAT, avg_WT);
}


/* gcc sjf_non.c
  ./a.out
  Enter the number of processes:
5

Enter the arrival time and burst time of the process:
AT BT
2 6
5 2
1 8
0 3
4 4

Gantt Chart:

| P4 (3) 3| P1 (6) 9| P2 (2) 11| P5 (4) 15| P3 (8) 23|

PID	AT	BT	CT	TAT	WT
1	   2	6	  9	   7	 1
2	   5	2	  11	 6   4
3	   1	8	  23	22	14
4	   0	3	  3	  3	   0
5	   4	4	  15	11	 7

Average TAT = 9.80
Average WT = 5.20
*/
  
