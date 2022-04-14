// C Program for SJF Scheduling

#include <stdio.h>

int main(){
    int burst_time[20], process[20], waiting_time[20], turnaround_time[20], i, j, n, total = 0, pos, temp;
    float avg_waiting_time, avg_turnaround_time;

    printf("\nEnter the number of process: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time:\n");
    for (i = 0; i < n; i++){
        printf("P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        process[i] = i + 1;
    }

    // Sorting burst time in ascending order using selection sort.
    for (i = 0; i < n; i++){
        pos = i;
        for (j = i + 1; j < n; j++){
            if (burst_time[j] < burst_time[pos]) pos = j;
        }
        temp = burst_time[i];
        burst_time[i] = burst_time[pos];
        burst_time[pos] = temp;

        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;
    }

    waiting_time[0] = 0; // Waiting time for first process will be zero.

    // Calculating waiting time
    for (i = 1; i < n; i++){
        waiting_time[i] = 0;
        for (j = 0; j < i; j++) waiting_time[i] += burst_time[j];
        total += waiting_time[j];
    }

    avg_waiting_time = (float)total / n;
    total = 0;
    
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++){
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total += turnaround_time[i];
        printf("\nP%d\t\t%d\t\t%d\t\t%d", process[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    avg_turnaround_time = (float)total / n;

    printf("\n\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n\n", avg_turnaround_time);

    return 0;
}