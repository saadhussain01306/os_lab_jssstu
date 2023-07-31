#include<stdio.h>
#include<stdlib.h>

typedef struct process {
    int Id, AT, BT, CT, TAT, WT, flag; 
} pro;

pro p[15];

void swap(pro *a, pro *b) {
    pro temp = *a;
    *a = *b;
    *b = temp;
    return; 
}

void sort(int n) {
    for(int i = 0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(p[j].AT > p[j+1].AT) {
                swap(&p[j], &p[j+1]);
            }
        }
    }
}

void main() {
    int n, tempBT[15], total_WT=0, total_TAT=0, quantum;
    float avg_WT=0, avg_TAT=0;
    printf("\nEnter the number of processes:\n");
    scanf("%d", &n);
    printf("\nEnter the arrival time and burst time of the process:\n");
    printf("AT BT\n");
    for(int i=0; i<n; i++) {
        p[i].Id = (i+1);
        scanf("%d%d", &p[i].AT, &p[i].BT);
        tempBT[i] = p[i].BT;
        p[i].flag = 0;
    }
    printf("\nEnter the time quantum:\n");
    scanf("%d", &quantum);
    sort(n);

    //A queue is required for demonstrating this algorithm
    int completed = 0, curIndex, curTime = p[0].AT, *waitQueue, front = 0, rear = 0;
    waitQueue = (int *)malloc(n*sizeof(int));
    waitQueue[rear] = 0;
    p[0].flag = 1;

    while (completed != n) {
        curIndex = waitQueue[front];
        front = (front+1) % n;
        if(p[curIndex].BT > quantum) {
            p[curIndex].BT -= quantum;
            curTime += quantum;
            printf("| P%d(%d) %d", p[curIndex].Id, quantum, curTime);
        } else {
            curTime += p[curIndex].BT;
            printf("| P%d(%d) %d", p[curIndex].Id, p[curIndex].BT, curTime);
            p[curIndex].BT = 0;
        p[curIndex].CT = curTime;
         p[curIndex].TAT = p[curIndex].CT - p[curIndex].AT;
        total_TAT += p[curIndex].TAT;
        p[curIndex].WT = p[curIndex].TAT - tempBT[p[curIndex].Id-1];
        total_WT += p[curIndex].WT;
        }

        for(int i=0; i<n && p[i].AT <= curTime; i++) {
            if(i == curIndex || p[i].flag == 1 || p[i].BT == 0) 
                continue;
            rear = (rear+1) % n;
            p[i].flag = 1;
            waitQueue[rear] = i;
        }

        if(p[curIndex].BT > 0) {
            rear = (rear+1)%n;
            waitQueue[rear] = curIndex;
        } else {
            completed++;
        }

    }
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

gcc rr.c
  ./a.out
  Enter the number of processes:
5

Enter the arrival time and burst time of the process:
AT BT
0 5
1 3
2 1
3 2
4 3

Enter the time quantum:
2
| P1(2) 2| P2(2) 4| P3(1) 5| P1(2) 7| P4(2) 9| P5(2) 11| P2(1) 12| P1(1) 13| P5(1) 14
PID	AT	BT	CT	TAT	WT
1	0	5	13	13	8
2	1	3	12	11	8
3	2	1	5	3	2
4	3	2	9	6	4
5	4	3	14	10	7

Average TAT = 8.60
Average WT = 5.80
*/
