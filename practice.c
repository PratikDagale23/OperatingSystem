#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct process
{
    int id;
    int burst_time;
    int priority;
    int rem_time;
};

void Array_sort(struct process p[], int n)
{
    struct process temp;
    int min = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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
    struct process p[MAX];
    int i, j, n;
    printf("enter number of processes:");
    scanf("%d",&n);

    printf("enter the burst time and priority for all process\n");
    for ( i = 0; i < n; i++)
    {
        p[i].id = i+1;
        printf("process %d:\n", i+1);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
        printf("\n");
    }

    // FCFS
    printf("FCFS Algrithm:");
    printf("\nProcess\tBurst time\tWaiting time\tTurnaround time\n");
    int t = 0;
    for ( i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n",p[i].id, p[i].burst_time, t, t+p[i].burst_time);
        t+=p[i].burst_time;
    }
    
    // Priority
    printf("Priority Scheduling Algorithm");
    printf("\nProcess\tBurst time\tWaiting time\tTurnaround time\n");
    Array_sort(p,n);
    t = 0;
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i].id, p[i].burst_time, t, t + p[i].burst_time);
        t += p[i].burst_time;
    }

    // SJF
    printf("SJF Algorithm");
    printf("\nProcess\tBurst time\tWaiting time\tTurnaround time\n");
    t = 0;
    int total_time;

    for (i = 0; i < n; i++)
    {
        p[i].rem_time = p[i].burst_time;
        total_time+=p[i].burst_time;
    }

    while(t<total_time)
    {
        int min = MAX;
        int shortest = 0;
        for ( i = 0; i < n; i++)
        {
            if(p[i].rem_time>0 && p[i].rem_time <min)
            {
                min = p[i].rem_time;
                shortest = i+1;
            }
        }
        
        if(shortest == 0)
        {
            t++;
            continue;
        }

        p[shortest].rem_time--;
        if(p[shortest].rem_time ==0)
        {
            printf("P%d\t%d\t\t%d\t\t%d\n", p[shortest].id, p[shortest].burst_time, t - p[shortest].burst_time, t);
        }
        t++;
    }
    





}