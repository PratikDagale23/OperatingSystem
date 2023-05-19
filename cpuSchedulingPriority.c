#include <stdio.h>
#include <stdlib.h>
#define MAX_PROCESS 10
struct process
{
    int pid;      // process id
    int burst;    // burst time
    int priority; // priority of process
    int rem;      // remaining time
};
// Function to sort the processes based on their priority
void sort(struct process p[], int n)
{
    int i, j;
    struct process temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].priority > p[j + 1].priority)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
int main()
{
    printf("\nName : Prajwal Arun Korade \n");
    int n, i, j;
    struct process p[MAX_PROCESS];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    // Input the burst time and priority for each process
    printf("Enter the burst time and priority for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d:\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &p[i].burst);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
        p[i].pid = i + 1;
        p[i].rem = p[i].burst;
    }
    // Sort the processes based on their priority
    sort(p, n);
    // Implementing the Priority Scheduling algorithm
    printf("\nProcess\tBurst time\tPriority\tRemaining time\n");
    i = 0;
    while (i < n)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst, p[i].priority, p[i].rem);
        p[i].rem--;
        if (p[i].rem == 0)
            i++;
        sort(p, n); // sort the processes again after each iteration
    }
    return 0;
}