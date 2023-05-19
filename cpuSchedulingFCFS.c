#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

struct process
{
    int pid;   // process id
    int burst; // burst time
};

int main()
{
    printf("Prajwal Arun Korade\nFCFS Algorithm\n");
    int n, i, j, t;
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
    }

    // Implementing the FCFS algorithm
    printf("\nProcess\tBurst time\tWaiting time\tTurnaround time\n");
    t = 0;
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst, t, t + p[i].burst);
        t += p[i].burst;
    }
    return 0;
}