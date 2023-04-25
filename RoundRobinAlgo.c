// Round Robin Agorithm

#include <stdio.h>

int main()
{
    int i, number_of_processes, sum = 0, count = 0, y, time_quantum, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;

    // Input number of processes
    printf("Total number of process in the system: ");
    scanf("%d", &number_of_processes);

    // Assign the number of processes to y
    y = number_of_processes;

    // Input of AT and BT
    for (i = 0; i < number_of_processes; i++)
    {
        printf("\nEnter the Arrival and Burst time of the Process[%d] \n", i + 1);

        printf("\nArrival time is: \n");
        scanf("%d", &at[i]);

        printf("\nBurst time is: \n");
        scanf("%d", &bt[i]);

        temp[i] = bt[i];
    }

    // Input Time Quantum
    printf("Enter the Time Quantum for the process: \n");
    scanf("%d", &time_quantum);

    // Display the P_ID, BT, WT and TAT
    printf("\n P_ID \t BT \t WT \t TAT");
    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= time_quantum && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;

            count = 1;
        }

        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - time_quantum;
            sum = sum + time_quantum;
        }

        if (temp[i] == 0 && count == 1)
        {
            y--;

            printf("\nP_ID[%d] \t\t %d \t\t %d \t\t %d", i + 1, bt[i], sum - at[i] - bt[i], sum - at[i]);
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];

            count = 0;
        }

        if (i == number_of_processes - 1)
        {
            i = 0;
        }

        else if (at[i + 1] <= sum)
        {
            i++;
        }

        else
        {
            i = 0;
        }
    }

    avg_wt = wt * 1.0 / number_of_processes;
    avg_tat = tat * 1.0 / number_of_processes;

    printf("\n Average Turn Around Time: \t%f", avg_wt);
    printf("\n Average Waiting Time: \t%f", avg_tat);

    return 0;
}
