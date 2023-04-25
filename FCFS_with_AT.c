// FCFS Algorithm (with AT)

#include <stdio.h>

int main()
{
    int n, bt[20], at[20], ct[20], tat[20], wt[20];

    printf("Enter number of processes : ");
    scanf("%d", &n);

    printf("Enter the arrival time: \n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d] : ", i + 1);
        scanf("%d", &at[i]);
    }

    printf("Enter the burst time: \n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d] : ", i + 1);
        scanf("%d", &bt[i]);
    }

    ct[0] = at[0] + bt[0];

    for (int i = 1; i < n; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
    }

    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
    }

    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
