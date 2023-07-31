#include<stdio.h>
#include<stdlib.h>

typedef struct process {
    int Id, AT, BT, CT, TAT, WT; 
} pro;

pro p[15];

void main() {
    int n, tempBT[15], total_WT=0, total_TAT=0;
    float avg_WT=0, avg_TAT=0;
    int minIndex, minBT, completed=0, curTime = 0;
    printf("\nEnter the number of processes:\n");
    scanf("%d", &n);
    printf("\nEnter the arrival time and burst time of the process:\n");
    printf("AT BT\n");
    for(int i=0; i<n; i++) {
        p[i].Id = (i+1);
        scanf("%d%d", &p[i].AT, &p[i].BT);
        tempBT[i] = p[i].BT;
    }

    printf("\nGantt Chart:\n");
    while(completed != n) {
        minIndex = -1;
        minBT = 9999;
        for(int i=0; i<n; i++) {
            if(p[i].AT <= curTime && p[i].BT>0) {
                if(p[i].BT < minBT || (p[i].BT == minBT && p[i].AT < p[minIndex].AT)) {
                    minBT = p[i].BT;
                    minIndex = i;
                }
            }
        }

        curTime++;

        if (minIndex != -1)
        {
            p[minIndex].BT--;
            printf("| P%d(1) %d", p[minIndex].Id, curTime);
            if (p[minIndex].BT == 0)
            {
                p[minIndex].CT = curTime;
                p[minIndex].TAT = p[minIndex].CT - p[minIndex].AT;
                p[minIndex].WT = p[minIndex].TAT - tempBT[minIndex];
                total_TAT += p[minIndex].TAT;
                total_WT += p[minIndex].WT;
                completed++;
            }
        }
    }
    printf("|\n");
    avg_TAT = (float)total_TAT/n;
    avg_WT = (float)total_WT/n;

    //Printing the table of processes with details
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].Id, p[i].AT, tempBT[i], p[i].CT, p[i].TAT, p[i].WT);
    }
    printf("\nAverage TAT = %.2f\nAverage WT = %.2f\n", avg_TAT, avg_WT);
}
/*
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
| P4(1) 1| P4(1) 2| P4(1) 3| P1(1) 4| P5(1) 5| P2(1) 6| P2(1) 7| P5(1) 8| P5(1) 9| P5(1) 10| P1(1) 11| P1(1) 12| P1(1) 13| P1(1) 14| P1(1) 15| P3(1) 16| P3(1) 17| P3(1) 18| P3(1) 19| P3(1) 20| P3(1) 21| P3(1) 22| P3(1) 23|

PID	AT	BT	CT	TAT	WT
1	  2	   6	15	13	7
2	  5	   2	 7	 2	0
3	  1	   8	23	22	14
4	  0	   3	 3	 3	 0
5	  4	   4	10	 6	 2

Average TAT = 9.20
Average WT = 4.60
*/
