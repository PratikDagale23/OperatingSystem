#include<stdio.h>
#include <stdlib.h>
#define MAX_PROCESS 10
    struct process
{
    int pid;   // process id
    int burst; // burst time
    int rem;   // remaining time
};
int main()
{
    printf("\nName : Prajwal Korade\n");
    int n, i, j, tq, t, flag;
    struct process p[MAX_PROCESS];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    // Input the burst time for each process
    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i].burst);
        p[i].pid = i + 1;
        p[i].rem = p[i].burst;
    }
    // Input the time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &tq);
    // Implementing the round-robin algorithm
    printf("\nProcess\tBurst time\tRemaining time\n");
    i = 0;
    t = 0;
    while (1)
    {
        flag = 0;
        for (j = 0; j < n; j++)
        {
            if (p[j].rem > 0)
            {
                flag = 1;
                if (p[j].rem > tq)
                {
                    t += tq;
                    p[j].rem -= tq;
                    printf("P%d\t%d\t\t%d\n", p[j].pid, p[j].burst, p[j].rem);
                }
                else
                {
                    t += p[j].rem;
                    printf("P%d\t%d\t\t%d\n", p[j].pid, p[j].burst, 0);
                    p[j].rem = 0;
                }
            }
        }
        if (flag == 0)
            break;
    }
    return 0;
}