#include <stdio.h>
#include <stdlib.h>

typedef struct process
{
    int Id, AT, BT, CT, TAT, WT, isCompl, priority;
} pro;

pro p[15];

void main()
{
    int n, total_WT = 0, total_TAT = 0, idleTime = 0;
    float avg_WT = 0, avg_TAT = 0;
    printf("\nEnter the number of processes:\n");
    scanf("%d", &n);
    printf("\nEnter the arrival time, burst time and priority of the process:\n");
    printf("AT BT P\n");
    for (int i = 0; i < n; i++)
    {
        p[i].Id = (i + 1);
        scanf("%d%d%d", &p[i].AT, &p[i].BT, &p[i].priority);
        p[i].isCompl = 0;
    }

    int minIndex, minPriority, completed = 0, curTime = 0;

    printf("\nGantt Chart:\n\n");
    while (completed != n)
    {
        minIndex = -1;
        minPriority = 9999;
        for (int i = 0; i < n; i++)
        {
            if (p[i].AT <= curTime && p[i].isCompl == 0)
            {
                if (p[i].priority < minPriority || (p[i].priority == minPriority && p[i].AT < p[minIndex].AT))
                {
                    minPriority = p[i].priority;
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
            // As the process is not preempted, the process executes till it is completed, i.e., for it's full BT.
            if (idleTime > 0)
            {
                printf("| Idle till %d", idleTime);
            }
            idleTime = 0;
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
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tP\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].Id, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT, p[i].priority);
    }
    printf("\nAverage TAT = %.2f\nAverage WT = %.2f\n", avg_TAT, avg_WT);
}
/*
Enter the number of processes:
7

Enter the arrival time, burst time and priority of the process:
AT BT P
0 3 2
2 5 6
1 4 3
4 2 5
6 9 7
5 4 4
7 10 10

Gantt Chart:

| P1 (3) 3| P3 (4) 7| P6 (4) 11| P4 (2) 13| P2 (5) 18| P5 (9) 27| P7 (10) 37|

PID	AT	BT	CT	TAT	WT	P
1	  0	   3	3	   3	0	  2
2	  2	   5	18	16	11	6
3	  1	   4	7	   6	2	  3
4	  4	   2	13	 9	7	  5
5	  6	   9	27	21	12	7
6	  5	   4	11	6	   2	4
7	   7	10	37	30	20	10

Average TAT = 13.00
Average WT = 7.71
*/
