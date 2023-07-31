#include <stdio.h>
struct process
{
    int ID, AT, BT, CT, TAT, WT;
};
void main()
{
    struct process P[10], temp;
    int n, i, j, ct, temp1 = 0;
    float total_tat = 0, total_wt = 0;
    printf("Enter the number of Process: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        P[i].ID = i + 1;
        printf("Enter AT for process %d :", i + 1);
        scanf("%d", &P[i].AT);
        printf("Enter BT for process %d :", i + 1);
        scanf("%d", &P[i].BT);
    }
    printf("\nGantt Chart:\n");
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (P[j].AT > P[j + 1].AT)
            {
                temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
    P[0].CT = P[0].AT + P[0].BT;
    ct = P[0].CT;
    if (P[0].AT > 0)
        printf("|Idle till %d", P[0].AT);
    printf("| P%d(%d) %d", P[0].ID, P[0].BT, ct);
    for (i = 1; i < n; i++)
    {
        if (P[i].AT > P[temp1].CT)
        {
            printf("|Idle till %d", P[i].AT);
            ct = P[i].AT + P[i].BT;
        }
        else
            ct += P[i].BT;
        P[i].CT = ct;
        temp1 = i;
        printf("| P%d(%d) %d", P[i].ID, P[i].BT, ct);
    }
    for (i = 0; i < n; i++)
    {
        P[i].TAT = P[i].CT - P[i].AT;
        P[i].WT = P[i].TAT - P[i].BT;
        total_tat += P[i].TAT;
        total_wt += P[i].WT;
    }
    printf("\n\nID\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", P[i].ID, P[i].AT, P[i].BT, P[i].CT, P[i].WT, P[i].TAT);
    }
    printf("AVG TAT : %.3f\n", total_tat / n);
    printf("AVG WT : %.3f\n", total_wt / n);
}
/*
gcc fcfs.c
  ./a.out
  Enter the number of Process: 5
Enter AT for process 1 :2
Enter BT for process 1 :2
Enter AT for process 2 :5
Enter BT for process 2 :6
Enter AT for process 3 :0
Enter BT for process 3 :4
Enter AT for process 4 :0
Enter BT for process 4 :7
Enter AT for process 5 :7
Enter BT for process 5 :4

Gantt Chart:
| P3(4) 4| P4(7) 11| P1(2) 13| P2(6) 19| P5(4) 23

ID	AT	BT	CT	WT	TAT
3	  0	  4	   4	 0	 4
4	  0	  7	   11	 4	11
1	  2	  2	   13	 9	11
2	  5	  6	   19	 8	14
5	  7	  4	   23	 12	16
AVG TAT : 11.200
AVG WT : 6.600
*/
